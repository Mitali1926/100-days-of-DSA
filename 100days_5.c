#include <stdio.h>
int main() {
    int n1, n2, i, j, k;
    printf("Enter number of entries in first log: ");
    scanf("%d", &n1);
    printf("Enter number of entries in second log: ");
    scanf("%d", &n2);
    int log1[n1], log2[n2], merged[n1 + n2];
    printf("Enter %d arrival times for first log (sorted):\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &log1[i]);
    }
    printf("Enter %d arrival times for second log (sorted):\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &log2[i]);
    }
    i = j = k = 0;
    // Merge the two logs
    while (i < n1 && j < n2) {
        if (log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    // Copy remaining elements
    while (i < n1) {
        merged[k++] = log1[i++];
    }
    while (j < n2) {
        merged[k++] = log2[j++];
    }
    printf("Merged chronological log:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    return 0;
}

