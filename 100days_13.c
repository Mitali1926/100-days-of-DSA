#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[100][100];

    // Input matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    printf("Spiral order traversal:\n");

    while (top <= bottom && left <= right) {

        // Traverse top row (left → right)
        for (int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Traverse right column (top → bottom)
        for (int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Traverse bottom row (right → left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column (bottom → top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}
