#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "logger.h"
#include "simulator.h"

int main(int argc, char** argv) {
    int r;    // Rotational speed of disk
    int t_s;  // Average seek time
    int N;    // Sector size
    int number_of_surfaces = 4;
    int number_of_cylinders = 25;
    int sectors_per_track = 20;
    int number_of_requests = 1000;
    enum scheduling_algo algo;

    scanf("%d", &r);
    scanf("%d", &N);
    scanf("%d", &t_s);
    scanf("%d", (int*)&algo);

    if (r <= 0 || N <= 0 || t_s < 0) {
        printf("Invalid values for r, N, t_s\n");
        return 0;
    }
    if (algo < 0 || algo > 4) {
        printf("Invalid values for algo, should be 0, 1, 2, 3, or 4\n");
        return 0;
    }

    printf("Starting simulation with the following configuration\n");
    printf("Rotational Speed: %d RPM  \n", r);
    printf("Sector size     : %d bytes\n", N);
    printf("Avg Seek Time   : %d ms   \n", t_s);
    printf("Scheduling algo : ");
    switch (algo) {
        case RANDOM:
            printf("RANDOM");
            break;
        case FIFO:
            printf("FIFO  ");
            break;
        case SSTF:
            printf("SSTF  ");
            break;
        case SCAN:
            printf("SCAN  ");
            break;
        case C_SCAN:
            printf("C-SCAN");
            break;
        default:
            break;
    }
    printf("\n\n");

    srand(time(NULL));
    set_log_level(LOG_LEVEL_STAT);

    run(number_of_requests, get_new_disk(r, t_s, N, number_of_surfaces, number_of_cylinders, sectors_per_track), algo);
    return 0;
}
