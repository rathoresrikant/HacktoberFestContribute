#include <iostream>
#include <string>

struct node
{
public:
	char data;
	node * next;

	node(char data_t)
	{
		data = data_t;
		next = NULL;
	}
	node()
	{
		next = NULL;
	}
};

//simpe stack implementation using single linked list
class stack_char
{
private:
	int count;
public:
	node* head;
	stack_char()
	{
		head = NULL;
		count = 0;
	}

	void push(char data) 
	{
		node* new_node = new node(data);
		if (!new_node)
		{
			std::cout << "new failed "<<std::endl;
			return;
		}
		new_node->next = head;
		head = new_node;
		count++;
	}

	void pop() 
	{
		if (head == NULL) {
			return;
		}
		node* temp = head;
		head = head->next;
		delete temp;
		count--;
	}

	char top() 
	{
		return head->data;
	}

	bool isEmpty() {
		return count == 0;
	}

	int size() {
		return count;
	}

	//to be sure there is no memory leaks
	~stack_char()
	{
		if (!isEmpty())
		{
			for (int i = 0; i<size(); i++)
			{
				pop();
			}
		}
	}
};

std::string reverse_string(std::string to_be_reversed)
{
	stack_char stack;
	std::string reversed = "";
	for (char c : to_be_reversed)
	{
		stack.push(c);
	}

	int original_stack_size = stack.size(); //save this before itself, as in pop the stack size keeps reducing
	for (int i = 0; i < original_stack_size; i++)
	{
		reversed.push_back(stack.top());
		stack.pop();
	}
	return reversed;
}

int main()
{
	std::cout << reverse_string("Here is a string");
	return 0;
}
