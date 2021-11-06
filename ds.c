#include "ds.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "logger.h"

int* get_new_int_array(int length) {
    int* array = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++)
        array[i] = 0;
    return array;
}

struct disk* get_new_disk(
    int rotational_speed_in_RPM,
    int avg_seek_time,
    int sector_size_in_bytes,
    int number_of_surfaces,
    int number_of_cylinders,
    int number_of_sectors_per_track) {
    struct disk* d = (struct disk*)malloc(sizeof(struct disk));
    d->rotational_speed_in_RPM = rotational_speed_in_RPM;
    d->avg_seek_time = avg_seek_time;
    d->sector_size_in_bytes = sector_size_in_bytes;
    d->number_of_surfaces = number_of_surfaces;
    d->number_of_cylinders = number_of_cylinders;
    d->number_of_sectors_per_track = number_of_sectors_per_track;
    d->rw_head_track = 0;
    d->rw_head_sector = 0;
    return d;
}

long get_time_taken_to_obey_request_in_millis(struct disk* d, struct request* req) {
    // TODO: Fix seek time
    // Everything is calculated in milliseconds
    long seek_time = 3 * d->avg_seek_time * abs(req->cylinder - d->rw_head_track) / d->number_of_cylinders;
    long rotational_delay = ((req->sector - d->rw_head_sector + d->number_of_sectors_per_track) % d->number_of_sectors_per_track) * 60 * 1000 / d->number_of_sectors_per_track / (d->rotational_speed_in_RPM);
    long transfer_time = (req->number_of_sectors_to_read) * 60 * 1000 / d->number_of_sectors_per_track / (d->rotational_speed_in_RPM);
    return seek_time + rotational_delay + transfer_time;
}

void move_to_position_of_request(struct disk* d, struct request* req) {
    d->rw_head_track = req->cylinder;
    d->rw_head_sector = (req->sector + req->number_of_sectors_to_read - 1) % d->number_of_sectors_per_track;
}

struct request* get_new_request(
    int platter,
    int cylinder,
    int sector,
    int number_of_sectors_to_read) {
    struct request* req = (struct request*)malloc(sizeof(struct request));
    req->platter = platter;
    req->cylinder = cylinder;
    req->sector = sector;
    req->number_of_sectors_to_read = number_of_sectors_to_read;
}

void init_request_queue_node(struct request_queue_node* node, struct request* req, struct request_queue_node* prev, struct request_queue_node* next) {
    node->req = req;
    node->prev = prev;
    node->next = next;
}

struct request_queue_node* get_new_empty_request_queue_node() {
    return (struct request_queue_node*)malloc(sizeof(struct request_queue_node));
}

struct request_queue_node* get_new_request_queue_node(struct request* req, struct request_queue_node* prev, struct request_queue_node* next) {
    struct request_queue_node* node = get_new_empty_request_queue_node();
    init_request_queue_node(node, req, prev, next);
    return node;
}

void free_request_queue_node(struct request_queue_node* node) {
    free_request(node->req);
    free(node);
}

bool is_queue_full(struct request_queue* queue) {
    return queue->size == queue->max_size;
}

bool is_queue_empty(struct request_queue* queue) {
    return queue->size == 0;
}

void init_queue(struct request_queue* queue, int max_size) {
    queue->max_size = max_size;
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
}

struct request_queue* get_new_empty_queue(int max_size) {
    struct request_queue* queue = (struct request_queue*)malloc(sizeof(struct request_queue));
    init_queue(queue, max_size);
    return queue;
}

bool __enqueue(struct request_queue* queue, struct request* req) {
    struct request_queue_node* node = get_new_request_queue_node(req, NULL, queue->head);
    if (is_queue_empty(queue)) {
        queue->head = node;
        queue->tail = node;
        queue->size = 1;
        return true;
    } else if (is_queue_full(queue)) {
        return false;
    } else {
        queue->head->prev = node;
        queue->head = node;
        queue->size += 1;
        return true;
    }
}

bool enqueue(struct request_queue* queue, struct request* req) {
    bool response = __enqueue(queue, req);
    return response;
}

struct request* __dequeue(struct request_queue* queue) {
    if (is_queue_empty(queue)) {
        return NULL;
    } else if (queue->size == 1) {
        struct request_queue_node* removed_node = queue->tail;
        struct request* req = removed_node->req;
        queue->head = NULL;
        queue->tail = NULL;
        queue->size = 0;
        free(removed_node);
        return req;
    } else {
        struct request_queue_node* removed_node = queue->tail;
        struct request* req = removed_node->req;
        queue->tail = queue->tail->prev;
        queue->tail->next = NULL;
        queue->size -= 1;
        free(removed_node);
        return req;
    }
}

struct request* dequeue(struct request_queue* queue) {
    struct request* response = __dequeue(queue);
    return response;
}

struct request* peek_queue(struct request_queue* queue) {
    if (is_queue_empty(queue)) {
        return NULL;
    } else {
        return queue->tail->req;
    }
}

void free_queue(struct request_queue* queue) {
    struct request_queue_node* node = queue->head;
    while (node != NULL) {
        free_request_queue_node(node);
        node = node->next;
    }
    free(queue);
}

void free_request(struct request* req) {
    free(req);
}

void free_disk(struct disk* d) {
    free(d);
}