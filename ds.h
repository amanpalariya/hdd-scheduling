#ifndef CS303_DS_H
#define CS303_DS_H

#include <stdbool.h>
#include <stdlib.h>

enum scheduling_algo {
    RANDOM = 0,
    FIFO = 1,
    SSTF = 2,
    SCAN = 3,
    C_SCAN = 4
};

struct disk {
    int rotational_speed_in_RPM;
    int avg_seek_time;
    int sector_size_in_bytes;
    int number_of_surfaces;
    int number_of_cylinders;
    int number_of_sectors_per_track;
    int rw_head_track;
    int rw_head_sector;
};

struct request {
    int platter;
    int cylinder;
    int sector;
    int number_of_sectors_to_read;
};

struct request_queue_node {
    struct request* req;
    struct request_queue_node* prev;
    struct request_queue_node* next;
};

struct request_queue {
    int max_size;
    int size;
    struct request_queue_node* head;
    struct request_queue_node* tail;
};

int* get_new_int_array(int length);

struct disk* get_new_disk(
    int rotational_speed_in_RPM,
    int avg_seek_time,
    int sector_size_in_bytes,
    int number_of_surfaces,
    int number_of_cylinders,
    int number_of_sectors_per_track);

long get_time_taken_to_obey_request_in_millis(struct disk* d, struct request* req);

void move_to_position_of_request(struct disk* d, struct request* req);

struct request* get_new_request(
    int platter,
    int cylinder,
    int sector,
    int number_of_sectors_to_read);

bool is_queue_full(struct request_queue* queue);

bool is_queue_empty(struct request_queue* queue);

void init_queue(struct request_queue* queue, int max_size);

struct request_queue* get_new_empty_queue(int max_size);

bool enqueue(struct request_queue* queue, struct request* req);

struct request* dequeue(struct request_queue* queue);

struct request* peek_queue(struct request_queue* queue);

void free_queue(struct request_queue* queue);

void free_request(struct request* req);

void free_disk(struct disk* d);

#endif