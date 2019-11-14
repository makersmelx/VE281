#ifndef FIB_HEAP_H
#define FIB_HEAP_H

#include "priority_queue.h"
#include <algorithm>
#include <cmath>

// OVERVIEW: A specialized version of the 'heap' ADT implemented as a
//           Fibonacci heap.
template <typename TYPE, typename COMP = std::less<TYPE>>
class fib_heap : public priority_queue<TYPE, COMP>
{
public:
	typedef unsigned size_type;

	// EFFECTS: Construct an empty heap with an optional comparison functor.
	//          See test_heap.cpp for more details on functor.
	// MODIFIES: this
	// RUNTIME: O(1)
    fib_heap(COMP comp = COMP()):compare(comp),heapSize(0),min(NULL){};

	// EFFECTS: Deconstruct the heap with no memory leak.
	// MODIFIES: this
	// RUNTIME: O(n)
	~fib_heap();

	// EFFECTS: Add a new element to the heap.
	// MODIFIES: this
	// RUNTIME: O(1)
	virtual void enqueue(const TYPE &val);

	// EFFECTS: Remove and return the smallest element from the heap.
	// REQUIRES: The heap is not empty.
	// MODIFIES: this
	// RUNTIME: Amortized O(log(n))
	virtual TYPE dequeue_min();

	// EFFECTS: Return the smallest element of the heap.
	// REQUIRES: The heap is not empty.
	// RUNTIME: O(1)
	virtual const TYPE &get_min() const;

	// EFFECTS: Get the number of elements in the heap.
	// RUNTIME: O(1)
	virtual size_type size() const;

	// EFFECTS: Return true if the heap is empty.
	// RUNTIME: O(1)
	virtual bool empty() const;

private:
	// Note: compare is a functor object
	COMP compare;

private:
	// Add any additional member functions or data you require here.
	// You may want to define a strcut/class to represent nodes in the heap and a
	// pointer to the min node in the heap.
	struct Node
	{
		TYPE val;
		Node *left;
		Node *right;
		Node *parent;
		Node *child;
		int degree;
		Node(const TYPE &_val) : val(_val)
		{
			left = right = this;
			child = parent = NULL;
			degree = 0;
		}
	};
	size_type heapSize;
	Node *min;
	
	void consolidate();

	void link(Node *y, Node *x);

	void clear(Node* x);
};

// Add the definitions of the member functions here. Please refer to
// binary_heap.h for the syntax.
template <typename TYPE, typename COMP>
fib_heap<TYPE, COMP>::~fib_heap()
{
//	while (!empty())
//	{
//		dequeue_min();
//	}
    clear(min);
}

template <typename TYPE, typename COMP>
void fib_heap<TYPE, COMP>::enqueue(const TYPE &val)
{
	Node *node = new Node(val);
	if (min == NULL)
	{
		min = node;
	}
	else
	{
		node->left = min;
		node->right = min->right;
		min->right->left = node;
		min->right = node;
		if (compare(val, min->val))
		{
			min = node;
		}
	}
	heapSize++;
}

template <typename TYPE, typename COMP>
TYPE fib_heap<TYPE, COMP>::dequeue_min()
{
	Node *z = min;
	TYPE res = z->val;
	while (z->child != NULL)
	{
		Node *p = z->child;
		p->parent = NULL;
		if (p == p->right)
		{
			z->child = NULL;
		}
		else
		{
			p->left->right = p->right;
			p->right->left = p->left;
			z->child = p->right;
		}
		p->right = min->right;
		p->left = min;
		min->right->left = p;
		min->right = p;
	}
	heapSize--;
	if (heapSize == 0)
	{
		min = NULL;
	}
	else
	{
		min = z->right;
		z->left->right = z->right;
		z->right->left = z->left;
		consolidate();
	}
	delete z;
	return res;
}

template<typename TYPE,typename COMP>
const TYPE &fib_heap<TYPE,COMP>::get_min() const
{
    return min->val;
}

template<typename TYPE,typename COMP>
unsigned int fib_heap<TYPE,COMP>::size() const
{
    return heapSize;
}

template<typename TYPE,typename COMP>
bool fib_heap<TYPE,COMP>::empty() const
{
    return heapSize==0;
}

template <typename TYPE, typename COMP>
void fib_heap<TYPE, COMP>::link(Node *y, Node *x)
{
	if (x->child == NULL)
	{
		y->left = y->right = y;
		y->parent = x;
		x->child = y;
	}
	else
	{
		y->left = x->child;
		y->right = x->child->right;
		x->child->right->left = y;
		x->child->right = y;
		y->parent = x;
	}
	x->degree++;
}

template <typename TYPE, typename COMP>
void fib_heap<TYPE, COMP>::consolidate()
{
    using namespace std;
	//int tmp_size = int(log(heapSize) / log((1 + sqrt(5)) / 2));
    int tmp_size = int(size());
	vector<Node *> array(tmp_size, NULL);
	Node *itr = min;
	while (1)
	{
		Node *x = itr;
		itr = itr->right;
		int d = x->degree;
		while (array[d] != NULL)
		{
			Node *y = array[d];
			if (compare(y->val,x->val))
			{
				Node *tmp = x;
				x = y;
				y = tmp;
			}
			link(y, x);
			array[d] = NULL;
			d++;
		}
		array[d] = x;
		if (itr == min)
		{
			break;
		}
	}
	min = NULL;
	for (auto &p : array)
	{
		if (p != NULL)
		{
			if (min == NULL)
			{
				min = p;
				p->left = p->right = p;
			}
			else
			{
				p->left = min;
				p->right = min->right;
				min->right->left = p;
				min->right = p;
				if (compare(p->val, min->val))
				{
					min = p;
				}
			}
		}
	}
}

template <typename TYPE, typename COMP>
void fib_heap<TYPE, COMP>::clear(Node* x)
{
    if(x == NULL)
    {
        return;
    }
    Node* p = x;

    while(true)
    {
        Node* q = p->right;
        clear(p->child);
        delete p;
        p = q;
        if(p == x)
        {
            break;
        }
    }
}


#endif //FIB_HEAP_H
