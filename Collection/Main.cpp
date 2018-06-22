// Collection.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Collection.cpp"
#include "Stack.cpp"
#include "Queue.cpp"


void stack_examples() {
	Collection<int>* s = new Stack<int>();
	s->add(20);
	//s->print();
	s->add(4);
	//s->print();
	s->add(111);
	//s->print();
	Collection<int>* r = s->clone();
	//r->print();
	r->add(97357);
	//r->print();
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
	stack_examples();

	return 0;
}
