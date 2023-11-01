#pragma once
#include "DoublyLinkedList.h"

template <class T>
class Stack
{
	DoublyLinkedList<T> container{};
public:

	void push(const T& element)
	{
		container.AddToHead(element);
	}

	void pop()
	{
		container.DeleteFromHead();
	}

	const T& top() const
	{
		if (!empty())
			return container[0];
		else
			throw exception("stack is empty.");
	}

	bool empty() const
	{
		return (container.Count() == 0);
	}

	size_t size() const
	{
		return container.Count();
	}
};