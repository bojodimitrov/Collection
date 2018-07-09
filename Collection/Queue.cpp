#include "stdafx.h"
#include "Collection.cpp"
#include "Node.cpp"

template<class T>
class Queue : public Collection<T> {
	Node<T>* top;
	Node<T>* bottom;

	void delete_queue() {
		Node<T>* tmp;
		while (top != NULL) {
			tmp = top->get_next();
			delete top;
			top = tmp;
		}
		bottom = NULL;
	}

	Node<T>* copy_queue(Node<T>* _node) {
		if (_node == NULL) {
			return NULL;
		}
		Node<T>* next_node = new Node<T>(_node->value(), this->copy_queue(_node->get_next()));
		if (_node->get_next() == NULL) {
			bottom = next_node;
		}
		return next_node;
	}

	Node<T>* get_top() const {
		return this->top;
	}

public:
	Queue() {
		top = NULL;
		bottom = NULL;
	}

	Queue(const Queue<T> &_q) {
		Node<T>* cur_top = _q.get_top();
		if (cur_top != NULL)
			top = new Node<T>(cur_top->value(), this->copy_queue(cur_top->get_next()));
	}

	Queue<T> operator = (const Queue<T> &_s) {
		if (top != NULL) {
			delete_queue();
			Node<T>* cur_top = _s.get_top();
			if (cur_top != NULL)
				top = new Node<T>(cur_top->value(), this->copy_queue(cur_top->get_next()));
		}
		return *this;
	}

	void add(T new_item) {
		this->top = new Node<T>(new_item, top);
		if (bottom == NULL) {
			bottom = top;
		}
	}

	void remove() {
		if (top == NULL) {
			return;
		}

		if (top->get_next() == NULL) {
			delete bottom;
			bottom = NULL;
			top = NULL;
			return;
		}

		Node<T>* next = top->get_next();
		Node<T>* previous = top;

		while (next->get_next() != NULL) {
			previous = next;
			next = next->get_next();
		}

		if (bottom != NULL) {
			delete bottom;
			previous->point_to(NULL);
			bottom = previous;
		}
	}

	void print() const {
		if (bottom == NULL) {
			std::cout << "empty" << std::endl;
		}
		else {
			std::cout << bottom->value() << std::endl;
		}
	}

	T& peek() const {
		if (bottom != NULL) {
			return bottom->value();
		}
	}

	Queue<T>* clone() const {
		return new Queue<T>(*this);
	}

	~Queue() {
		delete_queue();
	}
};
