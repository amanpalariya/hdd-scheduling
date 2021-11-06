#include "simulator.h"

#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include "ds.h"
#include "helper.h"
#include "logger.h"

struct request* generate_random_request(struct disk* d) {
    return get_new_request(randint(0, d->number_of_surfaces - 1), randint(0, d->number_of_cylinders - 1), randint(0, d->number_of_sectors_per_track - 1), randint(1, d->number_of_sectors_per_track));
}

void swap_requests(struct request** req_1, struct request** req_2) {
    struct request* req = *req_1;
    *req_1 = *req_2;
    *req_2 = *req_1;
}

void random_sort(int number_of_requests, struct request** reqs) {
    for (int i = 0; i < number_of_requests; i++) {
        int index = randint(0, number_of_requests - 1);
        swap_requests(&reqs[i], &reqs[index]);
    }
}

void fifo_sort(int number_of_requests, struct request** reqs) {}

void sstf_sort(int number_of_requests, struct request** reqs, int initial_rw_track) {
    // Minimizes seek time only
    int current_rw_track = initial_rw_track;
    for (int i = 0; i < number_of_requests; i++) {
        int min_seek_time_request_index = i;
        for (int j = i; j < number_of_requests; j++) {
            int old_seek_time = abs(current_rw_track - reqs[min_seek_time_request_index]->cylinder);
            int new_seek_time = abs(current_rw_track - reqs[j]->cylinder);
            if (new_seek_time < old_seek_time) {
                min_seek_time_request_index = j;
            }
        }
        swap_requests(&reqs[i], &reqs[min_seek_time_request_index]);
        current_rw_track = reqs[i]->cylinder;
    }
}

void scan_sort(int number_of_requests, struct request** reqs, int initial_rw_track, bool is_initially_going_outwards) {
    int current_rw_track = initial_rw_track;
    bool is_going_outwards = is_initially_going_outwards;
    for (int i = 0; i < number_of_requests; i++) {
        int next_index = i;
        bool found = false;
        for (int j = i; j < number_of_requests; j++) {
            int old_seek_time = abs(current_rw_track - reqs[next_index]->cylinder);
            int new_seek_time = abs(current_rw_track - reqs[j]->cylinder);
            if (is_going_outwards) {
                if (reqs[i]->cylinder >= current_rw_track) {
                    if (new_seek_time < old_seek_time) {
                        next_index = j;
                    }
                    found = true;
                }
            } else {
                if (reqs[i]->cylinder <= current_rw_track) {
                    if (new_seek_time < old_seek_time) {
                        next_index = j;
                    }
                    found = true;
                }
            }
        }
        if (!found) {
            is_going_outwards = !is_initially_going_outwards;
        }
        swap_requests(&reqs[i], &reqs[next_index]);
        current_rw_track = reqs[i]->cylinder;
    }
}

void c_scan_sort(int number_of_requests, struct request** reqs, int initial_rw_track) {
    int current_rw_track = initial_rw_track;
    for (int i = 0; i < number_of_requests; i++) {
        int next_index = i;
        bool found = false;
        for (int j = i; j < number_of_requests; j++) {
            int old_seek_time = abs(current_rw_track - reqs[next_index]->cylinder);
            int new_seek_time = abs(current_rw_track - reqs[j]->cylinder);
            if (reqs[i]->cylinder >= current_rw_track) {
                if (new_seek_time < old_seek_time) {
                    next_index = j;
                }
                found = true;
            }
        }
        if (!found) {
            current_rw_track = 0;
        }
        swap_requests(&reqs[i], &reqs[next_index]);
        current_rw_track = reqs[i]->cylinder;
    }
}

void sort_according_to_algo(int number_of_requests, struct request** reqs, enum scheduling_algo algo) {
    switch (algo) {
        case RANDOM:
            random_sort(number_of_requests, reqs);
            break;
        case FIFO:
            fifo_sort(number_of_requests, reqs);
            break;
        case SSTF:
            sstf_sort(number_of_requests, reqs, 0);
            break;
        case SCAN:
            scan_sort(number_of_requests, reqs, 0, true);
            break;
        case C_SCAN:
            c_scan_sort(number_of_requests, reqs, 0);
            break;
        default:
            break;
    }
}

void service_requests_sequentially(int number_of_requests, struct request** reqs, struct disk* d) {
    long time = 0;
    long response_times[number_of_requests];
    for (int i = 0; i < number_of_requests; i++) {
        response_times[i] = time;
        log_info("Time elapsed: %ld ms", time);
        time += get_time_taken_to_obey_request_in_millis(d, reqs[i]);
        log_info("Servicing request (platter=%d, cylinder=%d, sector=%d, number_of_sectors_to_read=%d)", reqs[i]->platter, reqs[i]->cylinder, reqs[i]->sector, reqs[i]->number_of_sectors_to_read);
        log_info("Moving RW head from [cylinder, sector] (%d, %d) -> (%d, %d)", d->rw_head_track, d->rw_head_sector, reqs[i]->cylinder, reqs[i]->sector);
        move_to_position_of_request(d, reqs[i]);
    }
    log_info("Time elapsed: %ld ms", time);
    log_stat("Response Time: (avg) %.2f ms, (min) %.2f ms, (max) %.2f ms, (sd) %.2f ms", mean(response_times, number_of_requests), min(response_times, number_of_requests), max(response_times, number_of_requests), standard_deviation(response_times, number_of_requests));
    log_stat("Throughput: %.2f requests per second", (1.0f * number_of_requests) * 1000 / time);
}

void run(int number_of_requests, struct disk* d, enum scheduling_algo algo) {
    struct request* reqs[number_of_requests];
    for (int i = 0; i < number_of_requests; i++) {
        reqs[i] = generate_random_request(d);
    }
    sort_according_to_algo(number_of_requests, reqs, algo);
    service_requests_sequentially(number_of_requests, reqs, d);
}