#include<stdio.h>
int main() {
int a[100], n, i, x, pos;
// Read number of elements
printf("Enter number of elements:");
scanf("%d", &n);
//Read array elements
printf("Enter %d elements:\n", n);
for(i = 0; i < n; i++) {
scanf("%d", &a[i]);
}
// Read element to insert and position
printf("Enter element to insert");
scanf("%d", &x);
printf("Enter position (1-based)");
scanf("%d", &pos);
// check valid position
if(pos < 1 || pos > n + 1){
printf("Invalid position\n");
return 0;
}
// Shift elements to the right
for(i = n - 1; i >= pos - 1; i--){
a[i + 1] = a[i];
}
// Insert element
a[pos - 1] = x;
n++;
// Display updated array
printf("Array after insertion:\n");
for(i = 0; i < n; i++) {
printf("%d\t", a[i]);
}
return 0;
}
