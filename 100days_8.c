#include <stdio.h>

// Recursive function to compute a^b
long long power(int a, int b) {
    // Base case
    if (b == 0)
        return 1;
    
    // Recursive case
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    printf("Enter base (a): ");
    scanf("%d", &a);

    printf("Enter exponent (b): ");
    scanf("%d", &b);

    if (b < 0) {
        printf("Negative exponents are not supported in this program.\n");
    } else {
        long long result = power(a, b);
        printf("%d^%d = %lld\n", a, b, result);
    }

    return 0;
}
