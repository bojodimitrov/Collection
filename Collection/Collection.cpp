// Collection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template<class T>
class Collection
{
public:
	virtual void print() = 0;
	virtual void add(T) = 0;
	virtual void remove() = 0;
	virtual T peek() = 0;
	virtual Collection<T>* clone() const = 0;
};

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

	Stack<T> operator = (const Stack<T> &_s) {
		if (top != NULL) {
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

	void print() {
		if (bottom == NULL) {
			std::cout << "empty" << std::endl;
		}
		else {
			std::cout << bottom->value() << std::endl;
		}
	}

	T peek() {
		return bottom->value();
	}

	Queue<T>* clone() const {
		return new Queue<T>(*this);
	}

	~Queue() {
		delete_queue();
	}
};

void stack_examples() {
	Collection<int>* s = new Stack<int>();
	s->add(20);
	s->print();
	s->add(4);
	s->print();
	s->add(111);
	s->print();
	Collection<int>* r = s->clone();
	r->print();
	r->add(97357);
	r->print();
	s->print();
	std::cout << s->peek() << std::endl;
}

int main()
{
	Collection<int>* s = new Queue<int>();

	s->remove();
	s->print();
	s->add(1);
	s->add(2);
	s->add(3);
	s->print();
	s->remove();
	s->print();
	Collection<int>* r = s->clone();
	r->print();
	r->add(97357);
	r->remove();
	r->remove();
	r->print();
	s->print();
	std::cout << s->peek() << std::endl;
	return 0;
}
