#include <stdio.h>

// Recursive function to compute nth Fibonacci number
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
    } 
    else {
        printf("\nFibonacci Series:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", fib(i));
        }

        printf("\n\nFibonacci number at position %d is %d\n", n-1, fib(n-1));
    }

    return 0;
}

