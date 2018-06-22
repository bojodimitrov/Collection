#include "stdafx.h"
#include "Collection.cpp"
#include "Node.cpp"

template<class T>
class Stack : public Collection<T>
{
	Node<T>* top;

	Node<T>* copy_stack(Node<T>* _node) {
		if (_node == NULL) {
			return NULL;
		}
		Node<T>* next_node = new Node<T>(_node->value(), this->copy_stack(_node->get_next()));
		return next_node;
	}

	void delete_stack() {
		Node<T>* tmp;
		while (top != NULL) {
			tmp = top->get_next();
			delete top;
			top = tmp;
		}
	}

	Node<T>* get_top() const {
		return this->top;
	}

public:
	Stack()
	{
		top = NULL;
	}

	Stack(const Stack<T> &_s) {
		Node<T>* cur_top = _s.get_top();
		if (cur_top != NULL)
			top = new Node<T>(cur_top->value(), this->copy_stack(cur_top->get_next()));
	}

	Stack<T>& operator =(const Stack<T> &_s) {
		if (this != &_s) {
			delete_stack();
			Node<T>* cur_top = _s.get_top();
			if (cur_top != NULL)
				top = new Node<T>(cur_top->value(), this->copy_stack(cur_top->get_next()));
		}
		return *this;
	}

	void add(T new_item) {
		this->top = new Node<T>(new_item, top);
	}

	void remove() {
		if (top != NULL) {
			Node<T>* tmp = top->get_next();
			delete top;
			top = tmp;
		}
	}

	void print() {
		if (top == NULL) {
			std::cout << "empty" << std::endl;
		}
		else {
			std::cout << top->value() << std::endl;
		}
	}

	T peek() {
		return top->value();
	}

	Stack<T>* clone() const {
		return new Stack<T>(*this);
	}

	~Stack() {
		delete_stack();
	}
};
