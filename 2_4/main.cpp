#include <iostream>
#include "SLL.hpp"

using namespace std;

SLL add_sll( SLL a, SLL b )
{
	Node* new_end = new Node{-1};
	Node* pre_head =  new_end;

	int sum, remainder = 0;
	Node* ca = a.head;
	Node* cb = b.head;

	while( ca != NULL && cb != NULL )
	{
		sum = (ca->data + cb->data + remainder) % 10;
		remainder = (ca->data + cb->data + remainder) > sum;
		new_end->next = new Node{sum};
		new_end = new_end->next;
		ca = ca->next;
		cb = cb->next;
	}

	while( ca != NULL)
	{
		sum = (ca->data + remainder) % 10;
		remainder = (ca->data + remainder) > sum;

		new_end->next = new Node{sum};
		new_end = new_end->next;
		ca = ca->next;
	}

	while( cb != NULL)
	{
		sum = (cb->data + remainder) % 10;
		remainder = (cb->data + remainder) > sum;

		new_end->next = new Node{sum};
		new_end = new_end->next;
		cb = cb->next;
	}

	if (remainder)
		  new_end->next = new Node{remainder};

	return SLL{pre_head->next};
}

int main()
{
	SLL sll;
	sll.push_back( new Node{9} );
	sll.push_back( new Node{3} );
	sll.push_back( new Node{5} );
	print_sll(sll);

	SLL sll2;
	sll2.push_back( new Node{9} );
	sll2.push_back( new Node{5} );
	sll2.push_back( new Node{9} );
	print_sll(sll2);

	SLL sum = add_sll(sll, sll2);
	print_sll(sum);

	return 0;
}
