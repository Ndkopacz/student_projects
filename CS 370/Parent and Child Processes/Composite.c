#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_composite(int num) {
    if (num < 4) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return true;
    }
    return false;
}

int nth_composite(int n) {
    int count = 0;
    for (int i = 4; ; i++) {
        if (is_composite(i)) {
            count++;
            if (count == n) return i;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int sum = 0;
    int composite_count = 0;
    int i = 4;

    while (composite_count < n) {
        if (is_composite(i)) {
            sum += i;
            composite_count++;
        }
        i++;
    }

    printf("Composite: Sum of first %d Composite numbers is %d\n", n, sum);
    printf("Composite: The nth Composite number is %d\n", nth_composite(n));

    if (sum > 200) {
        return n;
    } else {
        return sum;
    }
}