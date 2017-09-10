#include <iostream>
#include <queue>
#include "SLL.h"
#include "BST.h"

using namespace std;

vector< SLL< BSTNode<int>* >* > get_sll_levels(BST<int> bst)
{
    vector< SLL<BSTNode<int>* >* > result;

    queue< BSTNode<int>* >* current_queue;
    queue< BSTNode<int>* >* secondary_queue;

    int current_level = 0;

    current_queue = new queue< BSTNode<int>* >;
    secondary_queue = new queue< BSTNode<int>* >;

    if ( bst.get_head() == NULL )
        return result;

    current_queue->push(bst.get_head());

    while(!(current_queue->empty() && secondary_queue->empty()))
    {
        result.push_back( new SLL< BSTNode<int>* > );
        while(!current_queue->empty())
        {
            BSTNode<int>* current_node = current_queue->front();
            current_queue->pop();

            result[current_level]->push_back( current_node );

            if (current_node->get_left() != NULL )
                secondary_queue->push( current_node->get_left());

            if (current_node->get_right() != NULL )
                secondary_queue->push( current_node->get_right());
        }

        swap(current_queue, secondary_queue);
        current_level++;
    }
    return result;
}

int main()
{

    BST<int> bst;
    vector<int> a;
    for (int i = 0; i < 14; i ++)
        a.push_back(i);

    BST<int> bst2(a);

    vector< SLL< BSTNode<int>* >* > levels = get_sll_levels( bst2 );

    for ( auto sllptr : levels )
    {
        for ( auto nodeptr : *sllptr )
            cout << nodeptr->get_data() << " ";
        cout << "\n";
    }

    return 0;
}
