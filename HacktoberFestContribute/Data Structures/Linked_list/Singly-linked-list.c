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

// Function to insert a new node at the end of the list
void insertAtEnd(struct node** head, int data) {
    struct node* newNode = createNode(data);
    
    // If the list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Add the new node at the end
    temp->next = newNode;
}

// Function to delete the first occurrence of a node with the given data
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;
    
    // If the head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
    
    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the data was not found
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    
    // Free memory of the deleted node
    free(temp);
}

// Function to display the linked list
void displayList(struct node* head) {
    struct node* temp = head;
    
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; // Initialize an empty list
    int choice, value, delValue, n;

    // Get the number of elements to insert
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    // Inserting elements into the list
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    // Display the list
    printf("\nCurrent ");
    displayList(head);

    // Asking the user if they want to delete a node
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
