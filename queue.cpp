#include <iostream>
using namespace std;

class queue
{
private:
	int front, rear, capacity;
	int *arrQ;
public:
	queue(int c){
		front = rear = 0;
		capacity = c;
	}
	
	void enqueue(int data){
		if (rear == capacity)
		{
			std::cout << "Queue is full!\n";
		}
		else{
			arrQ[rear] = data;
			rear++;
		}
	}

	void dequeue(){
		if (front==rear)
		{
			std::cout << "Queue is Empty!\n";
		}
		else{
			for (int i = 0; i < rear-1; ++i)
			{
				arrQ[i] = arrQ[i+1];
			}
			rear--;
		}
	}

	void display(){
		if (front==rear)
		{
			std::cout << "Queue is Empty!\n";
		}
		else{
			for (int i = front; i < rear; ++i)
			{
				std::cout << arrQ[i] << "<-";
			}
			std::cout << "\n";
		}
	}

	void front_ele(){
		if (rear==front)	
		{
			std::cout << "Queue is Empty!\n";
		}
		else{
			std::cout << arrQ[front] << "\n";
		}
	}

	void get_max(){
		if (front==rear)
		{
			std::cout << "Queue is Empty!\n"; 
		}
		else{
			int max = 0;
			for (int i = front; i < rear; ++i)
			{
				if (arrQ[i]>max)
				{
					max = arrQ[i];
				}
			}
			std::cout << max << "\n";
		}
	}
	
};

int main(int argc, char const *argv[])
{
	queue a(10);
	a.enqueue(332);
	a.enqueue(12);
	a.display();
	a.dequeue(); 
	a.display();
	a.enqueue(333);
	a.enqueue(1243);
	a.enqueue(984586);
	a.enqueue(44);
	a.display();
	a.front_ele();
	a.display();
	a.dequeue();
	a.display();
	return 0;
}
