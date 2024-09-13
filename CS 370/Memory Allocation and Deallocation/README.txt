README
======

A. This package includes the following files. In your own readme file, modify the information as needed.

|-- Description PDF of the assignment
|-- README.txt [This file]
|-- Primes.c
|-- Primes.h
|-- Driver.c


B. Use your designed makefile 
To compile the code and build the executable using the command 

systemprompt>  make

To remove the  executable files use

systemprompt>  make clean

To run the program use (assuming seed is 3) 

systemprompt> ./Driver 3

which will run the program and generate the outputs.

==================================

This project includes modules for calculating statistical properties of prime numbers within a generated array of integers. The project is structured into three main components: Primes.c, Primes.h, and Driver.h. Each plays a specific role in the application.

-- Primes.c --
Functionality:

int random_in_range(int lower_bound, int upper_bound): Generates a random integer within a specified range. The lower bound is inclusive, while the upper bound is exclusive.
bool is_prime(int num): Determines whether a given integer is a prime number. Returns true if the number is prime, otherwise returns false.
int get_prime_count(int* array, int arraySize): Counts how many numbers in the provided array are prime numbers.
float get_running_ratio(void): Computes the ratio of prime numbers to composite numbers over multiple iterations of randomly generated arrays. It tracks the iteration with the highest number of prime numbers and calculates the average ratio across all iterations.
Primes.h
Description: This header file provides declarations for the functions implemented in Primes.c. It ensures that these functions can be correctly used in other parts of the program, particularly within the Driver.c module.

Contents:

Declarations for random_in_range, is_prime, get_prime_count, and get_running_ratio.

-- Driver.c --
Functionality:

Call primes.c after setting setting the random seed given by the user

Use:

```./Driver [seed]``` 

==================================

Valgrind: no leaks

==157887== Memcheck, a memory error detector
==157887== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==157887== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==157887== Command: ./Driver 12345
==157887== 
[Driver]: Seeding RNG with seed: 12345
[Primes]: Number of iterations is: 99
[Primes]: Iteration with MAX prime count: 57
[Driver]: AVG prime/composite ratio: 0.259702
==157887== 
==157887== HEAP SUMMARY:
==157887==     in use at exit: 0 bytes in 0 blocks
==157887==   total heap usage: 100 allocs, 100 frees, 71,012 bytes allocated
==157887== 
==157887== All heap blocks were freed -- no leaks are possible
==157887== 
==157887== For lists of detected and suppressed errors, rerun with: -s
==157887== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

========================================

Valgrind: leaks

==157833== Memcheck, a memory error detector
==157833== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==157833== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==157833== Command: ./Driver 12345
==157833== 
[Driver]: Seeding RNG with seed: 12345
[Primes]: Number of iterations is: 99
[Primes]: Iteration with MAX prime count: 57
[Driver]: AVG prime/composite ratio: 0.259702
==157833== 
==157833== HEAP SUMMARY:
==157833==     in use at exit: 69,988 bytes in 99 blocks
==157833==   total heap usage: 100 allocs, 1 frees, 71,012 bytes allocated
==157833== 
==157833== 69,988 bytes in 99 blocks are definitely lost in loss record 1 of 1
==157833==    at 0x4C39185: malloc (vg_replace_malloc.c:442)
==157833==    by 0x40091E: get_running_ratio (Primes.c:43)
==157833==    by 0x4007AA: main (Driver.c:21)
==157833== 
==157833== LEAK SUMMARY:
==157833==    definitely lost: 69,988 bytes in 99 blocks
==157833==    indirectly lost: 0 bytes in 0 blocks
==157833==      possibly lost: 0 bytes in 0 blocks
==157833==    still reachable: 0 bytes in 0 blocks
==157833==         suppressed: 0 bytes in 0 blocks
==157833== 
==157833== For lists of detected and suppressed errors, rerun with: -s
==157833== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)