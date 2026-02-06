#include <stdio.h>
void removeDuplicates(int arr[], int n) {
    if (n == 0) return;  // Handle edge case for empty array
    int j = 0;  // j will track the position to insert unique elements
    for (int i = 1; i < n; i++) {
        // If the current element is different from the previous one
        if (arr[i] != arr[i - 1]) {
            j++;  // Move the pointer for unique elements
            arr[j] = arr[i];  // Place the unique element in the correct position
        }
    }
    // Print the unique elements
    for (int i = 0; i <= j; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    // Input the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input. Array size should be positive.\n");
        return 1;
    }
    int arr[n];
    // Input the array elements
    printf("Enter the elements of the array (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array with duplicates removed: ");
    removeDuplicates(arr, n);

    return 0;
}

