#include "stdafx.h"
#include "Collection.cpp"
#include "DoublePointerNode.cpp"
#include "Iterator.cpp"

#pragma once

template<class T>
class DoubleLinkedList : public Collection<T> {
private:
	DoublePointerNode<T>* front;
	DoublePointerNode<T>* back;
	int size;

public:
	DoubleLinkedList(): front(NULL), back(NULL), size(0) {}

	bool empty() {
		return item == NULL;
	}

	bool insert(int n, T item) {
		DoubleIterator<T> it = this->iterator();
		if (n > size) {
			return false;
		}
		for (int i = 0; i < n; i++)
		{
			it++;
		}
		DoublePointerNode<T>* to_be_inserted = new DoublePointerNode<T>(item, (*it)->get_previous(), (*it));
		if (n == 0) {
			front = to_be_inserted;
		}
		else {
			(*it)->get_previous()->point_next(to_be_inserted);
		}
		if (n == size) {
			back = to_be_inserted;
		}
		(*it)->point_previous(to_be_inserted);
		size++;
		return true;
	}

	DoubleIterator<T>& iterator() {
		DoubleIterator<T> begin(front);
		return begin;
	}

	void print() const {
		DoubleIterator<T> it = const_cast<DoubleLinkedList<T>*>(this)->iterator();
		if (size == 0) {
			std::cout << "Empty list." << std::endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			it.print();
			it++;
			std::cout << ", ";
		}
		std::cout << std::endl;
	}

	void add(T new_item) {
		DoublePointerNode<T>* to_be_inserted = new DoublePointerNode<T>(new_item, NULL, NULL);
		if (size == 0) {
			front = to_be_inserted;
		}
		else {
			to_be_inserted->point_previous(back);
			back->point_next(to_be_inserted);
		}
		back = to_be_inserted;
		size++;
	}

	void remove() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete front;
			front = NULL;
			back = NULL;
		}
		else {
			DoublePointerNode<T>* last = back->get_previous();
			last->point_next(NULL);
			delete back;
			back = last;
		}
		size--;
	}

	int find(T item) {
		DoubleIterator<T> it = this->iterator();
		for (int i = 0; i < size; i++)
		{
			if ((*it)->value() == item) {
				return i;
			}
			it++;
		}
		return -1;
	}

	bool remove(T item) {
		if (size == 0) {
			return false;
		}
		int index = this->find(item);
		if (index == -1) {
			return false;
		}
		if (index == 0 && size == 1) {
			this->remove();
			return true;
		}
		if (index == size-1) {
			this->remove();
			return true;
		}
		DoubleIterator<T> it = this->iterator();
		for (int i = 0; i < index; i++)
		{
			it++;
		}
		(*it)->get_next()->point_previous(NULL);
		if (index == 0) {
			front = (*it)->get_next();
		}
		else {
			(*it)->get_previous()->point_next((*it)->get_next());
		}
		delete (*it);
		size--;
		return true;
	}

	T& peek() const {
		if (back != NULL) {
			return back->value();
		}
	}

	DoubleLinkedList<T>* clone() const {
		return NULL;
	}
};