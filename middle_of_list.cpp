#include <iostream>


struct Node {
    int data;
    Node* next;

    Node(int i) : data(i) {}; 
};

Node* init(int n) {
    Node* head = nullptr;
    for (int i=0; i<n; i++) {
        Node* p = new Node(3);
        p->next = head;
        head = p;
    }

    return head;
}

int main() {    
    int n;
    std::cout << "Enter size of list: ";
    std::cin >> n;

    Node* head = init(n);

    // Find the middle element of single linked list.
    Node* first = head;
    Node* second = head;
    while (!second->next) {
        first = first->next;
        second = second->next;

        if (!second->next)
            second = second->next;
    }

    std::cout << "The middle element: " << first->data << std::endl;

    return 0;
}