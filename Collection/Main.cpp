// Collection.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Collection.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "StaticQueue.cpp"
#include "List.cpp"

void stack_examples() {
	Collection<int>* s = new Stack<int>();
	std::cout << s->peek() << std::endl;
	s->add(20);
	//s->print();
	s->add(4);
	//s->print();
	s->add(111);
	//s->print();
	Collection<int>* r = s->clone();
	//r->print();
	r->add(97357);
	r->print();
	//s->print();
	std::cout << s->peek() << std::endl;

	Stack<int> ss;
	ss.add(20);
	ss.print();
	ss.add(4);
	ss.print();
	ss.add(111);
	ss.print();
	Stack<int> rr;
	rr.add(979);
	rr.print();
	rr = ss;
	ss.print();
	delete s;
	delete r;
}

void queue_examples() {
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

	delete s;
	delete r;
}

int main()
{
	DoubleLinkedList<int> L;
	L.add(5);
	L.add(143);
	L.add(420);
	L.add(69);
	std::cout << L.find(2) << std::endl;
	L.print();
	L.remove(69);
	L.print();
	return 0;
}
