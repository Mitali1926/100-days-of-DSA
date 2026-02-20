#include <stdio.h>
#include <string.h>

int main() {
    char codeName[100];
    int i, length;

    printf("Enter the secret code name: ");
    fgets(codeName, sizeof(codeName), stdin);

    // Remove newline character if present
    length = strlen(codeName);
    if (codeName[length - 1] == '\n') {
        codeName[length - 1] = '\0';
        length--;
    }

    printf("Mirror format: ");

    // Print characters in reverse order
    for (i = length - 1; i >= 0; i--) {
        printf("%c", codeName[i]);
    }

    printf("\n");

    return 0;
}
