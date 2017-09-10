#include <iostream>
#include "SLL.hpp"

using namespace std;

void print_sll( SLL sll )
{
	Node* current = sll.head;
	while( current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << "\n";
}

Node* find_n_to_last_iterative(SLL sll, int n)
{
	Node* tracer = NULL;
	Node* current = sll.head;

	for(int i=1; i < n; i++)
	{
		if (current == NULL)
			break;
		current = current->next;
	}

	if( current != NULL )
	{
		tracer = sll.head;
		while( current->next != NULL )
		{
			tracer = tracer->next;
			current = current->next;
		}
	}
	return tracer;
}

int rec( Node* node, Node* &result, int n)
{
	if (node == NULL){
		result = NULL;
		return 0;
	}
	int m = rec( node->next, result, n) + 1;

	if ( m == n ){
		result = node;
	}
	return m;
}

Node* find_n_to_last_recursive( SLL sll, int n )
{
	Node* result;

	rec( sll.head, result, n);

	return result;
}
int main()
{
	SLL sll;
	sll.push_back(new Node{1});
	sll.push_back(new Node{2});
	sll.push_back(new Node{3});
	sll.push_back(new Node{4});
	print_sll(sll);

	Node* result = find_n_to_last_recursive(sll, 3);

	if (result == NULL)
		cout << "NULL";
	else
		cout << result->data;

	return 0;
}
