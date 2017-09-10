#include <iostream>
#include <map>
#include "SLL.hpp"

using namespace std;

Node* circular_start( SLL sll )
{
	map<Node*, bool> visited;
	Node* current = sll.head;

	while( current != NULL && !visited[current] )
	{
		visited[current] = true;
		current = current->next;
	}
	return current;

}

int main()
{
	SLL sll;
	Node* culpit = new Node{34};

	sll.push_back( new Node{1} );
	sll.push_back( new Node{2} );
	sll.push_back( culpit );
	sll.push_back( new Node{3} );
	sll.push_back( new Node{4} );
	sll.push_back( culpit );

	Node* result = circular_start( sll );

	if ( result == NULL )
		cout << "NULL";
	else
		cout << result->data;

	return 0;
}
