#include <iostream>
#include <map>
#include "tree.hpp"

using namespace std;

bool isBalanced( Tree tree )
{
	map<TreeNode*, int> level;
	queue<TreeNode*> q;

	q.push( tree.getRoot() );
	level[tree.getRoot()] = 0;

	int mn = INF,
		mx = -INF;

	while( !q.empty() )
	{
		TreeNode* currentNode = q.front();
		q.pop();

		level[currentNode] = level[currentNode->getParent()] + 1;
		if ( currentNode->isLeaf())
		{
			mn = min( level[currentNode], mn );
			mx = max( level[currentNode], mx );
		}
		else
		{
			for ( TreeNode* child : currentNode->getChildren() )
				q.push( child );
		}
	}

	int maxLevelDifference = mx - mn;

	return maxLevelDifference <= 1;
}

int main()
{
	TreeNode* n1 = new TreeNode( 1 );
	for ( int i = 0; i < 3; i ++ )
		n1->addChild( new TreeNode(2) );

	TreeNode* r = new TreeNode(0);
	r->addChild(n1);
	TreeNode* n2 = new TreeNode(1);
	n2->addChild(new TreeNode(3));
	//n1->addChild(n2); //this will make it false
	r->addChild( new TreeNode(4));

	printTree( Tree(r) );
	cout << isBalanced( Tree(r) );

	return 0;
}
