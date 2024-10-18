#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* nthNode(struct Node* head, int n) {
    struct Node* current = head;
    int count = 0;

    while (current != NULL && count < n) {
        current = current->next;
        count++;
    }

    return current;
}

int main() {
    struct Node* head = NULL;
    int n;

    // Create a linked list (example: 1 -> 2 -> 3 -> 4 -> 5)
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);
    head = insertNode(head, 5);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    struct Node* nth = nthNode(head, n);

    if (nth != NULL) {
        printf("The %dth node is %d\n", n, nth->data);
    } else {
        printf("The linked list does not have %d nodes\n", n);
    }

    return 0;
}
