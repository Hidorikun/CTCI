#pragma once

class Node
{
public:
	Node* next;
	int data;

public:
	Node(int _data)
	{
		this->data = _data;
		this->next = NULL;
	}

};

class SLL
{
public:
	Node* head;

public:
	SLL( Node* _head )
	{
		this->head = _head;
	}

	void append( Node * new_node )
	{
		Node* current = this->head;
		while( current->next != NULL )
			current = current->next;
		current->next = new_node;
	}
};
