#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Check is a value is prime or not
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num % 2 == 0 && num != 2) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function that returns a random integer between a lower and an upper bound
int random_in_range(int lower_bound, int upper_bound){
    return rand() % (upper_bound - lower_bound) + lower_bound;
}

// Function that returns the number of prime numbers found in an array
int get_prime_count(int *array, int arraySize){
    int prime_count = 0;
    for (int i = 0; i < arraySize; i++) {
        if (is_prime(array[i])) {
            prime_count++;
        }
    }
    return prime_count;
}

// Function that computes and returns the running ratio of prime to non-prime numbers
float get_running_ratio(void){
    int maxPrimeCount = 0;
    int maxCountIteration = 0; 
    int iterations = random_in_range(50, 100);
    printf("[Primes]: Number of iterations is: %d\n", iterations);
    float total_ratio = 0.0;

    for (int i = 1; i <= iterations; i++) {
        // Allocate memory for the array
        int array_size = random_in_range(150, 200);
        int* numbers = malloc(array_size * sizeof(int));

        // Set each value in the array
        for (int j = 0; j < array_size; j++) {
            numbers[j] = random_in_range(50, 200);
        }

        // Call get_prine_count to count the number of primes, then add that to the ratio
        int prime_count = get_prime_count(numbers, array_size);
        int composite_count = array_size - prime_count;
        float ratio = (composite_count == 0) ? 0 : (float)prime_count / composite_count;
        total_ratio += ratio;

        // Updating (if needed) the iteration with the highest number of primes
        if (prime_count > maxPrimeCount) {
            maxPrimeCount = prime_count;
            maxCountIteration = i;
        }
        
        free(numbers);
    }

    float average_ratio = total_ratio / iterations;
    printf("[Primes]: Iteration with MAX prime count: %d\n", maxCountIteration);
    return average_ratio;
}

