/*Factorial*/
#include <stdio.h>

unsigned long long factorialIterative(int n) {
    unsigned long long result = 1; // Use unsigned long long to handle large results
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d (iterative) is: %llu\n", n, factorialIterative(n));
    }

    return 0;
}