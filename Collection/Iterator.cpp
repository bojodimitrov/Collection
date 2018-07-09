#include "stdafx.h"
#include "DoublePointerNode.cpp"

#pragma once

template<class T>
class DoubleIterator {
private:
	DoublePointerNode<T>* current;

public:
	DoubleIterator() : current(NULL) {}

	DoubleIterator(DoublePointerNode<T>* _start) : current(_start) {}

	DoubleIterator(const DoubleIterator<T>& _i) {
		this->current = _i.current;
	}

	DoubleIterator& operator ++ (int) {
		DoubleIterator<T> tmp = *this;
		if (current->get_next() != NULL) {
			current = current->get_next();
		}
		return tmp;
	}

	DoubleIterator& operator -- (int) {
		DoubleIterator<T> tmp = *this;
		if (current->get_previous() != NULL) {
			current = current->get_previous();
		}
		return tmp;
	}

	DoubleIterator& operator = (const DoubleIterator& _i) {
		if (*this != _i) {
			this->current = _i.current;
		}
		return *this;
	}


	DoubleIterator& operator ++ () {
		if (current->get_next() != NULL) {
			current = current->get_next();
		}
		return *this;
	}

	DoubleIterator& operator -- () {
		if (current->get_previous() != NULL) {
			current = current->get_previous();
		}
		return *this;
	}

	DoublePointerNode<T>* operator *() {
		if (this->current != NULL) {
			return this->current;
		}
	}

	operator bool() const {
		return current != NULL;
	}


	bool operator == (const DoubleIterator& _i) const {
		return current == _i.current;
	}

	void print() {
		if (this->current != NULL) {
			std::cout << current->value();
		}
	}
};