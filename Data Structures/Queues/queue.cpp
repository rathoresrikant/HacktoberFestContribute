#include<stdio.h>
#include<iostream>
#include<string.h>
#define SIZE 5
using namespace std;

class queue
{
    int data[SIZE];
    int front;
    int rear;
public:
    void enq(int a)
    {
        if(rear==SIZE)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        data[rear++]=a;
    }
    int deq()
    {
        if(rear==front)
        {
            return -9999;
        }
        int v=data[front++];
        return v;
    }
    void display()
    {
        for(int i=0;i<=rear;i++)
        {
            if(i==rear)
                cout<<data[i]<<" <-- rear"<<endl;
            else if(i==front)
                cout<<data[i]<<"<-- front"<<endl;
            else
                cout<<data[i]<<endl;
        }
    }
    queue()
    {
        front=0;
        rear=0;
    }
};

void menu()
{
    cout<<"#####################################"<<endl;
    cout<<"############### QUEUE ###############"<<endl;
    cout<<"Choose the following options- "<<endl;
    cout<<"1. Enqueue\n2. Dequeue\n3. Display\n4. Exit"<<endl;
}
int main()
{
    queue q1;
    int exit=0,choice,value;
    menu();
    while(!exit)
    {
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter value to be inserted"<<endl;
                    cin>>value;
                    q1.enq(value);
                    break;
            case 2: value=q1.deq();
                    if(value==-9999)
                        cout<<"Queue Underflow"<<endl;
                    else
                        cout<<"Popped item is: "<<value<<endl;
                    break;
            case 3: q1.display();
                    break;
            case 4: exit++;
                    break;
            default: cout<<"Wrong input recieved"<<endl;
        }
    }
    return 0;
}
