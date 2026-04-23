#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* node = newNode(data);

    if (head == NULL) return node;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    return head;
}

// Get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* p1 = head1;
    struct Node* p2 = head2;

    // Move pointer of longer list ahead
    int diff = abs(len1 - len2);

    if (len1 > len2) {
        for (int i = 0; i < diff; i++) p1 = p1->next;
    } else {
        for (int i = 0; i < diff; i++) p2 = p2->next;
    }

    // Traverse both lists together
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) return p1; // intersection node
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    // Second list (first part)
    scanf("%d", &m);
    struct Node* temp2 = NULL;
    struct Node* tail2 = NULL;

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);

        // Stop when value matches intersection (30 here)
        if (x == 30) break;

        struct Node* node = newNode(x);
        if (temp2 == NULL) {
            temp2 = tail2 = node;
        } else {
            tail2->next = node;
            tail2 = node;
        }
    }

    // Find node with value 30 in first list
    struct Node* temp1 = head1;
    while (temp1 != NULL && temp1->data != 30)
        temp1 = temp1->next;

    // Attach intersection
    if (tail2 != NULL)
        tail2->next = temp1;
    else
        temp2 = temp1;

    head2 = temp2;

    // Find intersection
    struct Node* result = findIntersection(head1, head2);

    if (result)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}