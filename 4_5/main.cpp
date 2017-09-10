#include <iostream>
#include "BST.hpp"

using namespace std;

int main()
{
	BST<int> bst;

	bst.insert(4);
	bst.insert(2);
	bst.insert(5);
	bst.insert(1);
	bst.insert(3);

	BSTNode<int>* current = bst.get_head();

	for ( int x : bst )
	{
		cout << x << " ";
	}

	return 0;
}
