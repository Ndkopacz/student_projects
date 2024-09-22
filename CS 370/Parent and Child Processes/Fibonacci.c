#include <stdio.h>
#include <stdlib.h>


int fibonacci(int n) {
    // Calculate the nth fibonacci number
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    // Get argument and calculate sums
    int n = atoi(argv[1]);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fibonacci(i);
    }

    printf("Fibonacci: Sum of first %d Fibonacci numbers is %d\n", n, sum);
    printf("Fibonacci: The nth Fibonacci number is %d\n", fibonacci(n));

    // Handle return conditions
    if (sum > 50) {
        return n;
    } else {
        return sum;
    }
}