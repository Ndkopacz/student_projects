#include <stdio.h>
#include <stdlib.h>

int perrin(int n) {
    if (n == 0) return 3;
    if (n == 1) return 0;
    if (n == 2) return 2;
    return perrin(n-2) + perrin(n-3);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += perrin(i);
    }

    printf("Perrin: Sum of first %d Perrin numbers is %d\n", n, sum);
    printf("Perrin: The nth Perrin number is %d\n", perrin(n));

    if (sum > 100) {
        return n;
    } else {
        return sum;
    }
}