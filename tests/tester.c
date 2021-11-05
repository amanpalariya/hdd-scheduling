#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>

#include "../ds.h"
#include "../logger.h"

int total_tests = 0;
int passed_tests = 0;
int failed_tests = 0;

void log_test(char* test_name, bool success) {
    total_tests++;
    if (success) {
        printf("\033[0;32m[✓]: %s\033[0m\n", test_name);
        passed_tests++;
    } else {
        printf("\033[0;31m[ ]: %s\033[0m\n", test_name);
        failed_tests++;
    }
}

void print_test_section(char* section) {
    printf("\n\033[0;1m%s\033[0m\n\n", section);
}

void test_disk() {
    print_test_section("Testing disk");
    struct disk* d = get_new_disk(7500, 512, 2, 4, 25, 20);

    log_test("New disk", d->rotational_speed_in_RPM == 7500 && d->avg_seek_time == 512 && d->sector_size_in_bytes == 2 && d->number_of_surfaces == 4 && d->number_of_cylinders == 25 && d->number_of_sectors_per_track == 20);
}

void test_request() {
    print_test_section("Testing request");
    struct request* req = get_new_request(2, 1, 3, 4);

    log_test("New request", req->platter == 2 && req->cylinder == 1 && req->sector == 3 && req->number_of_sectors_to_read == 4);
}

void test_queue() {
    int MAX_SIZE = 2;
    struct request_queue* queue = get_new_empty_queue(MAX_SIZE);

    log_test("New empty queue", queue->size == 0 && queue->max_size == MAX_SIZE);

    {
        enqueue(queue, get_new_request(1, 2, 3, 4));
        struct request* front = peek_queue(queue);
        log_test("Enqueue (1/2)", queue->size == 1 && (front->platter == 1 && front->cylinder == 2 && front->sector == 3 && front->number_of_sectors_to_read == 4));
    }

    {
        enqueue(queue, get_new_request(4, 3, 2, 1));
        struct request* back = queue->head->req;
        log_test("Enqueue (2/2)", queue->size == 2 && (back->platter == 4 && back->cylinder == 3 && back->sector == 2 && back->number_of_sectors_to_read == 1));
    }

    {
        bool response = enqueue(queue, get_new_request(4, 3, 2, 1));
        log_test("Queue max size", response == false);
    }

    {
        struct request* front = dequeue(queue);
        log_test("Dequeue (1/2)", queue->size == 1 && (front->platter == 1 && front->cylinder == 2 && front->sector == 3 && front->number_of_sectors_to_read == 4));
    }

    {
        struct request* front = dequeue(queue);
        log_test("Dequeue (1/2)", queue->size == 0 && (front->platter == 4 && front->cylinder == 3 && front->sector == 2 && front->number_of_sectors_to_read == 1));
    }

    {
        struct request* front = dequeue(queue);
        log_test("Underflow", queue->size == 0 && front == NULL);
    }

    free_queue(queue);
}

void test_ds() {
    print_test_section("Testing data structures");
    test_disk();
    test_request();
    test_queue();
}

int main(int argc, char** argv) {
    mute_logs();
    test_ds();
    printf("\n%d/%d tests passed\n", passed_tests, total_tests);
    return 0;
}