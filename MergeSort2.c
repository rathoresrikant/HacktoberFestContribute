#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* mergedHead = NULL;

    // Use a temporary pointer for the merged list
    struct Node* temp = NULL;

    // Merging lists
    while (list1 != NULL && list2 != NULL) {
        if (mergedHead == NULL) {
            if (list1->data < list2->data) {
                mergedHead = list1;
                list1 = list1->next;
            } else {
                mergedHead = list2;
                list2 = list2->next;
            }
            temp = mergedHead; // Set temp to the merged head
        } else {
            if (list1->data < list2->data) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
    }

    // Attach any remaining nodes
    if (list1 != NULL) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }

    return mergedHead;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first linked list
    insertEnd(&list1, 1);
    insertEnd(&list1, 3);
    insertEnd(&list1, 5);

    // Insert elements into the second linked list
    insertEnd(&list2, 2);
    insertEnd(&list2, 4);
    insertEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Merge the two linked lists
    struct Node* mergedList = mergeLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
