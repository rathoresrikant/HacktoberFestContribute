#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    
    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    // Find the last node
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Link the new node at the end
    temp->next = newNode;
    newNode->next = *head; // Point the new node's next to the head to maintain circular property
}

// Function to delete a node with the given data
void deleteNode(struct node** head, int data) {
    // If the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = *head;
    struct node* prev = NULL;

    // If the head node holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        // If it's the only node in the list
        if (temp->next == *head) {
            *head = NULL;
            free(temp);
            return;
        }
        
        // Find the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
        return;
    }

    // Traverse the list to find the node to be deleted
    while (temp->next != *head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted was found
    if (temp->data == data) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Element %d not found in the list.\n", data);
    }
}

// Function to display the circular linked list
void displayList(struct node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node* temp = head;

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct node* head = NULL; // Initialize an empty circular linked list
    int n, value, delValue, choice;

    // Get the number of elements to insert
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    // Insert elements into the circular linked list
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    // Display the list
    printf("\nCurrent ");
    displayList(head);

    // Ask the user if they want to delete a node
    printf("Do you want to delete an element? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the value to delete: ");
        scanf("%d", &delValue);
        deleteNode(&head, delValue);

        // Display the list after deletion
        printf("\nAfter deletion, ");
        displayList(head);
    }

    return 0;
}
