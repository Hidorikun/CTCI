#pragma once

template<class T>
class SLLNode
{
public:
    T data;
    SLLNode* next;
public:
    SLLNode( T _data, SLLNode* _next = NULL ) : data{_data}, next{_next} {};
    ~SLLNode(){};

};

template<class T>
class SLLIterator
{
private:
    SLLNode<T>* current_node;
public:
    SLLIterator(SLLNode<T>* _current_node)
    {
        this->current_node = _current_node;
    }

    ~SLLIterator(){};

    SLLIterator& operator++()
    {
        this->current_node = current_node->next;
        return *this;
    }

    T& operator*(){ return current_node->data; };
    bool operator==(const SLLIterator& rhs) const { return current_node == rhs.current_node; };
    bool operator!=(const SLLIterator& rhs) const { return current_node != rhs.current_node; };
};

template<class T>
class SLL
{
public:
    SLLNode<T>* head;
    SLLNode<T>* tail;

public:
    SLL()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    ~SLL() {};

    void push_back( T data )
    {
        SLLNode<T>* new_node = new SLLNode<T>(data);

        if (this->tail == NULL)
        {
            this->tail = new_node;
            this->head = new_node;
        }else{
            this->tail->next = new_node;
            this->tail = this->tail->next;
        }
    }

    void push_front( T data )
    {
        SLLNode<T>* new_node = new SLLNode<T>(data);

        if (this->head == NULL)
        {
            this->head = new_node;
            this->tail = new_node;
        }else{
            new_node->next = this->head;
            this->head = new_node;
        }

    }

    SLLIterator<T> begin() { return SLLIterator<T>(this->head); };
    SLLIterator<T> end() { return SLLIterator<T>(NULL); };

};

