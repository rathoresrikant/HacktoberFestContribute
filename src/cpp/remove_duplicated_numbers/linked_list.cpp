#include "linked_list.h"

int linked_list::get(unsigned int position)
{
	if (position == 0)
		return head->value;
	if (position > list_size)
		return -1;

	linked_list_node *previous = new linked_list_node;
	linked_list_node *current = new linked_list_node;
	current = head;
	for(unsigned int i = 1; i < position; i++)
	{
		previous = current;
		current = current->next;
	}
	return current->value;
}

void linked_list::set(unsigned int position, int value)
{
	if (position == 0)
		head->value = value;
	if (position > list_size)
		return;

	linked_list_node *previous = new linked_list_node;
	linked_list_node *current = new linked_list_node;
	current = head;
	for (unsigned int i = 1; i < position; i++)
	{
		previous = current;
		current = current->next;
	}
	current->value = value;
}

void linked_list::add_node(int value)
{
	linked_list_node *temp = new linked_list_node;
	temp->value = value;
	temp->next = nullptr;
	if(head == nullptr)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	list_size++;
}

void linked_list::insert_node(unsigned int position, int value)
{
	if (position == 0)
		insert_at_head(value);
	else if (position > list_size)
		add_node(value);
	else
	{
		linked_list_node *previous = new linked_list_node;
		linked_list_node *current = new linked_list_node;
		linked_list_node *temp = new linked_list_node;
		current = head;
		for(unsigned int i = 1; i < position; i++)
		{
			previous = current;
			current = current->next;
		}
		temp->value = value;
		previous->next = temp;
		temp->next = current;
	}
	list_size++;
}



void linked_list::insert_at_head(int value)
{
	linked_list_node *temp = new linked_list_node;
	temp->value = value;
	temp->next = head;

	head = temp;

	list_size++;
}

void linked_list::delete_node(unsigned position)
{
	if (position > list_size)
		return;

	linked_list_node *previous = new linked_list_node;
	linked_list_node *current = new linked_list_node;
	current = head;
	for (unsigned int i = 1; i < position; i++)
	{
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	current = nullptr;

	list_size--;
}



size_t linked_list::size()
{
	return list_size;
}
