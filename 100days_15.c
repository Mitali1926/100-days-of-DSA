#include <stdio.h>

int main() {
    int m, n;

    // Input dimensions
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    // Input matrix elements
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;

    // Calculate primary diagonal sum
    for(int i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }

    // Output result
    printf("%d\n", sum);

    return 0;
}