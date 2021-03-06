#pragma once
#include <iostream>

class Node
{
public:
	int data;
	Node* next;
public:
	Node(int value)
	{
		this->data = value;
		this->next = NULL;
	}

};

class SLL
{
public:
	Node* head;
public:
	SLL( Node* _head = NULL )
	{
		this->head = _head;
	}
	void push_back( Node* new_node )
	{
		if ( this->head == NULL)
		{
			this->head = new_node;
		}else{
			Node* current = this->head;
			while( current->next != NULL )
			{
				current = current->next;
			}
			current->next = new_node;
		}
	}
};

void print_sll( SLL sll )
{
	Node* current = sll.head;
	while( current != NULL)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << "\n";
}
