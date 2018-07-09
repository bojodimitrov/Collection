#include "stdafx.h"

#pragma once

template<class T>
class DoublePointerNode {
private:
	DoublePointerNode<T> *previous_node, *next_node;
	T item;

public:
	DoublePointerNode(){}

	DoublePointerNode(T _item) : item(_item), previous_node(NULL), next_node(NULL){}

	DoublePointerNode(T _item, DoublePointerNode<T>* _previous, DoublePointerNode<T>* _next): item(_item), previous_node(_previous), next_node(_next) {}

	void point_to(DoublePointerNode<T>* _previous, DoublePointerNode<T>* _next) {
		next_node = _next;
		previous_node = _previous;
	}

	void point_previous(DoublePointerNode<T>* _previous) {
		previous_node = _previous;
	}

	void point_next(DoublePointerNode<T>* _next) {
		next_node = _next;
	}

	DoublePointerNode<T>* get_previous() {
		return this->previous_node;
	}

	DoublePointerNode<T>* get_next() {
		return this->next_node;
	}

	T& value()
	{
		return this->item;
	}
};