#ifndef PRIMES_H
#define PRIMES_H

// Function that returns a random integer between a lower and an upper bound
int random_in_range(int lower_bound, int upper_bound);

// Function that returns the number of prime numbers found in an array
int get_prime_count(int *array, int arraySize);

// Function that computes and returns the running ratio of prime to non-prime numbers
float get_running_ratio(void);

#endif // PRIMES_H