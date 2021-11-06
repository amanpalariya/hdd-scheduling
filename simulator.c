#include "simulator.h"

#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#include "ds.h"
#include "helper.h"
#include "logger.h"

struct request* generate_random_request() {
    // TODO: Change numbers
    return get_new_request(1, 2, 3, 4);
}

void swap_requests(struct request** req_1, struct request** req_2) {
    struct request* req = *req_1;
    *req_1 = req_2;
    *req_2 = req_1;
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

long service_requests(int number_of_requests, struct request** reqs, int* arrival_time, struct disk* d, enum scheduling_algo algo) {
    long time = 0;
    for (int i = 0; i < number_of_requests; i++) {
        time += get_time_taken_to_obey_request_in_millis(d, reqs[i]);
        log_info("Servicing request (platter=%d, cylinder=%d, sector=%d, number_of_sectors_to_read=%d)", reqs[i]->platter, reqs[i]->cylinder, reqs[i]->sector, reqs[i]->number_of_sectors_to_read);
        log_info("Moving RW head from [cylinder, sector] (%d, %d) -> (%d, %d)", d->rw_head_track, d->rw_head_sector, reqs[i]->cylinder, reqs[i]->sector);
        move_to_position_of_request(d, reqs[i]);
    }
    return time;
}

long run(int number_of_requests, struct disk* d, enum scheduling_algo algo) {
    struct request* reqs[number_of_requests];
    int arrival_time[number_of_requests];
    for (int i = 0; i < number_of_requests; i++) {
        reqs[i] = generate_random_request();
        arrival_time[i] = i;  // TODO: Fix this
    }
    // sort_according_to_algo(number_of_requests, reqs, algo);
    long time_taken_in_millis = service_requests(number_of_requests, reqs, arrival_time, d, algo);
    return time_taken_in_millis;
}