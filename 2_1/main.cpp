#include <iostream>
#include "SLL.hpp"

using namespace std;

void print_sll( SLL* sll )
{
	Node* current = sll->head;
	while (current != NULL)
	{
		cout << current->data << " ";
		current = current->next;
	}
}

void delete_duplicate( SLL* sll )
{
	Node* head = new Node(-1);
	head->next = sll->head;

	if( sll->head != NULL )
	{
		bool duplicate = false;
		Node* pre = head;
		Node* current = head->next;
		Node* pre_scout;
		Node* scout;
		while( current != NULL )
		{
			pre_scout = current;
			scout = current->next;
			while( scout != NULL)
			{
				if( current->data == scout->data)
				{
					duplicate = true;
					pre_scout->next = scout->next;
				}else{
					pre_scout = pre_scout->next;
				}

				scout = scout->next;
			}

			if( duplicate )
			{
				pre->next = current->next;
			}else{
				pre = pre->next;
			}

			current = current->next;
			duplicate = false;
		}
	}
	sll->head = head->next;
}

int main()
{
	SLL* list = new SLL( new Node(1) );
	list->append( new Node(1) );
	list->append( new Node(2) );
	list->append( new Node(1) );
	list->append( new Node(2) );
	list->append( new Node(3) );

	print_sll(list);
	cout << "\n";
	delete_duplicate(list);

	print_sll(list);
	return 0;
}
