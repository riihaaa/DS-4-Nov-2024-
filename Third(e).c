/*Fibonacci Series*/
#include <stdio.h>

void printFibonacciIterative(int n) {
    int a = 0, b = 1, next;
    
    printf("Fibonacci Series (up to %d terms):\n", n);
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // first two Fibonacci numbers are 0 and 1
        } else {
            next = a + b; // next number is the sum of the previous two
            a = b; // update previous two numbers
            b = next;
        }
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printFibonacciIterative(n);

    return 0;
}