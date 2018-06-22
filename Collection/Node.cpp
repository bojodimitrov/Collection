#include "stdafx.h"

#pragma once

template<class T>
class Node
{
	T item;
	Node* next_node;

public:
	Node()
	{
		next_node = NULL;
	}

	Node(T _item) : item(_item), next_node(NULL) {}
	Node(T _item, Node* _next) : item(_item), next_node(_next) {}

	T value()
	{
		return this->item;
	}

	void point_to(Node* target) {
		next_node = target;
	}

	Node* get_next() {
		return next_node;
	}
};