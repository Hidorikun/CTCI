#pragma once
#include <vector>

using namespace std;

template<class T>
class BSTNode
{
private:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
	BSTNode<T>* parent;

public:
	BSTNode(T _data,
			BSTNode<T>* _parent = NULL,
			BSTNode<T>* _left = NULL,
			BSTNode<T>* _right = NULL
			) : data{_data}, left{_left}, right{_right}, parent{_parent} {};

	~BSTNode(){};

	T get_data() { return this->data; };
	BSTNode<T>* get_left() { return this->left; };
	BSTNode<T>* get_right() { return this->right; };
	BSTNode<T>* get_parent() { return this->parent; };

	void set_data( T new_data ) { this->data = new_data; };
	void set_left(BSTNode<T>* new_left) { this->left = new_left; };
	void set_right(BSTNode<T>* new_right) { this->right = new_right; };
	void set_parent(BSTNode<T>* new_parent) { this->parent = new_parent; };

	bool operator<(BSTNode other)
	{
		return this->data < other.data;
	}

	bool operator>(BSTNode other)
	{
		return this->data > other.data;
	}

	bool operator==(BSTNode other)
	{
		return this->data == other.data;
	}
};


template<class T>
class BSTIterator
{
private:
	BSTNode<T>* current;

public:
	BSTIterator<T>( BSTNode<T>* _current ) : current{_current} {};
	~BSTIterator<T> () {};

	BSTIterator<T>& operator++( )
	{
		BSTNode<T>* current_aux;
		if ( this->current->get_right() != NULL )
		{
			current_aux = this->current->get_right();

			while( current_aux->get_left() != NULL )
				current_aux = current_aux->get_left();

			this->current = current_aux;
			return *this;
		}

		BSTNode<T>* parent = this->current->get_parent();

		current_aux = this->current;
		while( parent!=NULL && parent->get_right() == current_aux )
		{
			current_aux = parent;
			parent = current_aux->get_parent();
		}

		this->current = parent;


		return *this;
	}

	BSTIterator<T>& operator=( BSTIterator<T> it )
	{
		this->current = it.current();
		return *this;
	}

	bool operator==( BSTIterator<T> const it) const
	{
		return this->current == it.current;
	}

	bool operator!=( BSTIterator<T> const it) const
	{
		return this->current != it.current;
	}

	T operator*() const
	{
		return this->current->get_data();
	}
};


template<class T>
class BST
{
private:
	BSTNode<T>* head;

	void parse_inorder( BSTNode<T>* x, std::vector< BSTNode<T>* >& inorder )
	{
		if ( x != NULL )
		{
			parse_inorder(x->get_left(), inorder);
			inorder.push_back(x);
			parse_inorder(x->get_right(), inorder);
		}
	}

	void parse_postorder( BSTNode<T>* x, std::vector< BSTNode<T>* >& postorder )
	{
		if ( x != NULL )
		{
			parse_postorder(x->get_left(), postorder);
			parse_postorder(x->get_right(), postorder);
			postorder.push_back(x);
		}
	}

	void parse_preorder( BSTNode<T>* x, std::vector< BSTNode<T>* >& preorder )
	{
		if ( x != NULL )
		{
			preorder.push_back(x);
			parse_preorder(x->get_left(), preorder);
			parse_preorder(x->get_right(), preorder);
		}
	}

	BSTNode<T>* translate_sorted_array( std::vector<T> sorted_array, int st, int dr )
	{
		if ( dr - st <= 1 ) return NULL;

		int mid = (st + dr) / 2;
		BSTNode<T>* node = new BSTNode<T>(sorted_array[mid]);
		node->set_left( translate_sorted_array(sorted_array, st, mid) );
		node->set_right( translate_sorted_array(sorted_array, mid, dr) );

		return node;
	}

public:
	BST(BSTNode<T>* _head = NULL): head{_head} {};
	BST( std::vector<T> sorted_array ) : head{this->translate_sorted_array(sorted_array, -1, sorted_array.size())} {};

	~BST(){};

	void set_head( BSTNode<T>* new_head ) { this->head = new_head; };
	BSTNode<T>* get_head() { return this->head; };

	void insert( T data )
	{
		BSTNode<T>* new_node = new BSTNode<T>(data);
		if (this->head == NULL){
			this->head = new_node;
		}else
		{
			BSTNode<T>* current = this->head;

			bool inserted = false;
			while(!inserted)
			{
				if (*new_node < *current)
				{
					if (current->get_left() == NULL)
					{
						current->set_left(new_node);
						new_node->set_parent(current);
						inserted = true;
					}
					current = current->get_left();
				}
				else
				{
					if (current->get_right() == NULL)
					{
						current->set_right(new_node);
						new_node->set_parent(current);
						inserted = true;
					}
					current = current->get_right();
				}
			}
		}
	}

	std::vector< BSTNode<T>* > get_inorder()
	{
		std::vector< BSTNode<T>* > result;
		parse_inorder( this->head, result );
		return result;
	}

	std::vector< BSTNode<T>* > get_postorder()
	{
		std::vector< BSTNode<T>* > result;
		parse_postorder( this->head, result );
		return result;
	}

	std::vector< BSTNode<T>* > get_preorder()
	{
		std::vector< BSTNode<T>* > result;
		parse_preorder( this->head, result );
		return result;
	}

	BSTIterator<T> begin()
	{
		BSTNode<T>* first_node = this->head;
		while( first_node->get_left() != NULL )
			first_node = first_node->get_left();
		return BSTIterator<T>(first_node);
	}

	BSTIterator<T> end() { return BSTIterator<T>(NULL); }
};
