#include "linked_list.h"
#include <iostream>

int main()
{
	linked_list *list = new linked_list;
	list->add_node(1);
	list->add_node(2);
	list->add_node(2);
	list->add_node(3);
	list->add_node(3);
	list->add_node(4);
	list->add_node(5);
    list->add_node(1);

	int numbers[10];

	for(int i = 0; i < list->size(); i++)
	{
		int value = list->get(i);
		for(int j = 0; j < 10; j++)
		{
			if (numbers[j] != value)
				continue;

			list->delete_node(i);
			break;
		}
	}

	for(int i = 0; i < list->size(); i++)
		cout << list->get(i) << endl;
	
	return 0;
}
