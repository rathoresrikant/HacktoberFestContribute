#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Node
{
public:
    Node* next;
    int data;
};

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    cout << "LIST DELETED";
}

void LinkedList::add(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        cout << i << ": " << head->data << endl;
        head = head->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    string text;
    int x;
    LinkedList* list = new LinkedList();
    cout << "Enter the list. Enter 'stop' to finish" << endl;
    while(true){
        cin >> text;
        if(text == "stop"){
            break;
        }
        else{
            x = stoi(text);
            list->add(x);
        }
    }
    cout << "List Length: " << list->length << endl;
    if(list->length % 2 == 0){
        cout << "The length is even" << endl;
    }
    else{
        cout << "The length is odd" << endl;
    }
    return 0;
}