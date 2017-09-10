#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define TElem int
#define INF ( 1 << 30 )

class TreeNode
{
private:
	TElem data;
	TreeNode* parent;
	std::vector< TreeNode* > children;

public:
	TreeNode( TElem _data ) : data{_data}
	{
		this->parent = NULL;
	};

	~TreeNode();

	TElem getData(){ return this->data; }
	TreeNode* getParent() { return this->parent; }

	void setParent( TreeNode* newParent ) { this->parent = newParent; }

	std::vector< TreeNode* > getChildren() { return this->children; }

	void addChild( TreeNode* newChild )
	{
		newChild->parent = this;
		this->children.push_back( newChild );
	}

	int getChildrenCount() { return this->children.size(); };

	bool isLeaf() { return this->getChildrenCount() == 0; }
};

class Tree
{
private:
	TreeNode* root;

public:
	Tree( TreeNode* _root = NULL ) : root{_root}{};
	TreeNode* getRoot() { return this->root; };
};

void printTree( Tree tree )
{
	std::map<TreeNode*, int> level;
	std::queue<TreeNode*> q;

	q.push( tree.getRoot() );
	level[tree.getRoot()] = 0;

	while( !q.empty() )
	{
		TreeNode* currentNode = q.front();
		q.pop();

		level[currentNode] = level[currentNode->getParent()] + 1;

		for ( TreeNode* child : currentNode->getChildren() )
			q.push( child );

		for(int i = 0; i < level[currentNode]; i++)
			std::cout<< " ";
		std::cout<< level[currentNode] << "\n";
	}
}
