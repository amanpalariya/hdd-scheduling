# What does the program do?

It simulates the working of the HDD with given configuration and calculates stats based on random requests.

# How does this program work?

The user inputs a few parameters like the rotational speed of HDD, average seek time, etc.
The program then generates some random requests for disk access and measures the response time and throughput.
Algorithms like FIFO, SSTF, SCAN, and C-SCAN are employed.

# How to compile and run?

1. Unzip the source code.
2. Inside the directory, run `make` to build the project.
3. Run the program by executing `./build/main.out`
4. Enter (space separated) r, N, T_s as given in problem statement.
5. Then enter the algorithm number (see below).

## Algorithm number

0: Random
1: FIFO
2: SSTF
3: SCAN
4: C-SCAN

## Testing

1. Run `make test` to run tests

# Snapshot

After doing the following steps

1. Compile the project by running `make`
2. Start the simulation by executing `printf "7500 512 4 2" | ./build/main.out`.

A possible output can be the following
```
Starting simulation with the following configuration
Rotational Speed: 7500 RPM  
Sector size     : 512 bytes
Avg Seek Time   : 4 ms   
Scheduling algo : SSTF  

INFO  18:55:34: Time elapsed: 0 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 0) -> (0, 0)
INFO  18:55:34: Time elapsed: 6 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 13 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 20 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 27 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 34 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 41 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 48 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 55 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 62 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 69 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 76 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 83 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 90 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 97 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 104 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 111 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 118 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 125 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 132 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 139 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 146 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 153 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 160 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 167 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 174 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 181 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 188 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 195 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 202 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 209 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 216 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 223 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 230 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 237 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 244 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 251 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 258 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 265 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=0, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 0)
INFO  18:55:34: Time elapsed: 272 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 16) -> (0, 6)
INFO  18:55:34: Time elapsed: 280 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 287 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 294 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 301 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 308 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 315 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 322 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=6, number_of_sectors_to_read=12)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 6)
INFO  18:55:34: Time elapsed: 329 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=19, number_of_sectors_to_read=4)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 19)
INFO  18:55:34: Time elapsed: 330 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=19, number_of_sectors_to_read=4)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 2) -> (0, 19)
INFO  18:55:34: Time elapsed: 337 ms
INFO  18:55:34: Servicing request (platter=0, cylinder=0, sector=19, number_of_sectors_to_read=4)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 2) -> (0, 19)
INFO  18:55:34: Time elapsed: 344 ms
INFO  18:55:34: Servicing request (platter=3, cylinder=0, sector=14, number_of_sectors_to_read=4)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 2) -> (0, 14)
INFO  18:55:34: Time elapsed: 349 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 17) -> (0, 16)
INFO  18:55:34: Time elapsed: 363 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 370 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 377 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 384 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 391 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 398 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 405 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 412 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 419 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=16, number_of_sectors_to_read=19)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 16)
INFO  18:55:34: Time elapsed: 426 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=4, number_of_sectors_to_read=2)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 14) -> (0, 4)
INFO  18:55:34: Time elapsed: 430 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=4, number_of_sectors_to_read=2)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 5) -> (0, 4)
INFO  18:55:34: Time elapsed: 437 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=0, sector=4, number_of_sectors_to_read=2)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 5) -> (0, 4)
INFO  18:55:34: Time elapsed: 444 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 5) -> (0, 14)
INFO  18:55:34: Time elapsed: 454 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 462 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 470 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 478 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 486 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 494 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 502 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 510 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 518 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 526 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 534 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 542 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 550 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 558 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 566 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 574 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 582 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 590 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 598 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 606 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 614 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 622 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 630 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 638 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=14, number_of_sectors_to_read=18)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 14)
INFO  18:55:34: Time elapsed: 646 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 11) -> (0, 17)
INFO  18:55:34: Time elapsed: 654 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 661 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 668 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 675 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 682 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 689 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 696 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 703 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 710 ms
INFO  18:55:34: Servicing request (platter=1, cylinder=0, sector=17, number_of_sectors_to_read=17)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (0, 17)
INFO  18:55:34: Time elapsed: 717 ms
INFO  18:55:34: Servicing request (platter=2, cylinder=11, sector=4, number_of_sectors_to_read=10)
INFO  18:55:34: Moving RW head from [cylinder, sector] (0, 13) -> (11, 4)
INFO  18:55:34: Time elapsed: 730 ms
STAT  18:55:34: Response Time: (avg) 350.78 ms, (min) 0.00 ms, (max) 717.00 ms, (sd) 209.27 ms
STAT  18:55:34: Throughput: 136.99 requests per second
```
