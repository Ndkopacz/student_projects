// 1. Set the seed using srand(); the seed is passed as an argument
// 2. Invoke the functions of Primes.C (call  get_running_ratio())

#include <stdio.h>
#include <stdlib.h>
#include "Primes.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <seed>\n", argv[0]);
        return 1;
    }

    // Convert command line argument to integer for seeding
    int seed = atoi(argv[1]);
    srand(seed);  // Seed the random number generator

    printf("[Driver]: Seeding RNG with seed: %d\n", seed);

    // Call the function that handles the prime calculations and gets the running ratio
    float running_ratio = get_running_ratio();

    // Print the results
    printf("[Driver]: AVG prime/composite ratio: %.6f\n", running_ratio);

    return 0;
}