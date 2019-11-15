#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "priority_queue.h"
#include <algorithm>

// OVERVIEW: A specialized version of the 'heap' ADT implemented as a binary
//           heap.
template <typename TYPE, typename COMP = std::less<TYPE>>
class binary_heap : public priority_queue<TYPE, COMP>
{
public:
	typedef unsigned size_type;

	// EFFECTS: Construct an empty heap with an optional comparison functor.
	//          See test_heap.cpp for more details on functor.
	// MODIFIES: this
	// RUNTIME: O(1)
	binary_heap(COMP comp = COMP());

	// EFFECTS: Add a new element to the heap.
	// MODIFIES: this
	// RUNTIME: O(log(n))
	virtual void enqueue(const TYPE &val);

	// EFFECTS: Remove and return the smallest element from the heap.
	// REQUIRES: The heap is not empty.
	// MODIFIES: this
	// RUNTIME: O(log(n))
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
	// Note: This vector *must* be used in your heap implementation.
	std::vector<TYPE> data;
	// Note: compare is a functor object
	COMP compare;

private:
	virtual void percolate_up(int id);
	virtual void percolate_down(int id);

private:
	// Add any additional member functions or data you require here.
};

template <typename TYPE, typename COMP>
binary_heap<TYPE, COMP>::binary_heap(COMP comp)
{
	compare = comp;
	// Fill in the remaining lines if you need.
}

template <typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::enqueue(const TYPE &val)
{
	data.push_back(val);
	percolate_up(int(size())-1);
}

template <typename TYPE, typename COMP>
TYPE binary_heap<TYPE, COMP>::dequeue_min()
{
	TYPE res = data.front();
	data[0] = data.back();
	data.pop_back();
	if (!empty())
	{
		percolate_down(0);
	}
	return res;
}

template <typename TYPE, typename COMP>
const TYPE &binary_heap<TYPE, COMP>::get_min() const
{
	return data.front();
}

template <typename TYPE, typename COMP>
bool binary_heap<TYPE, COMP>::empty() const
{
	return data.empty();
}

template <typename TYPE, typename COMP>
unsigned binary_heap<TYPE, COMP>::size() const
{
	return data.size();
}

template <typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::percolate_up(int id)
{
	while (id > 0 && compare(data[id],data[(id-1) / 2]))
	{
		TYPE tmp = data[(id-1) / 2];
		data[(id-1) / 2] = data[id];
		data[id] = tmp;
		id = (id-1) / 2;
	}
}

template <typename TYPE, typename COMP>
void binary_heap<TYPE, COMP>::percolate_down(int id)
{
	for (int j = id*2 + 1; j < size(); j = id*2+1)
	{
		if (j < int(size())-1 && compare(data[j+1],data[j]))
		{
			j++;
		}
		if (compare(data[id],data[j]))
		{
			break;
		}
        TYPE tmp = data[id];
        data[id] = data[j];
        data[j] = tmp;
        id = j;
	}
}
#endif //BINARY_HEAP_H
