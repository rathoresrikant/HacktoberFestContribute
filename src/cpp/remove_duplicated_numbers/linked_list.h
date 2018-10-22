#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct linked_list_node
{
	int value;
	linked_list_node *next;
};

class linked_list
{
	linked_list_node *head, *tail;
	size_t list_size;

public:
	linked_list()
	{
		head = nullptr;
		tail = nullptr;
		list_size = 0;
	}

	int get(unsigned int position);
	void set(unsigned int position, int value);
	void add_node(int value);
	void insert_node(unsigned int position, int value);
	void delete_node(unsigned int position);
	void insert_at_head(int value);

	size_t size();
};
#endif