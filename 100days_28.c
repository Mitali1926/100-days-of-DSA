#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // If no nodes
    if (n == 0) {
        return 0;
    }

    // Create circular linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
            newNode->next = head;  // Point to itself initially
        } else {
            temp->next = newNode;
            temp = newNode;
            newNode->next = head;  // Maintain circular link
        }
    }

    // Traversal
    struct Node* current = head;

    if (head != NULL) {
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != head);  // Stop when back to head
    }

    return 0;
}