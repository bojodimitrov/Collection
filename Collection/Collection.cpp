#include "stdafx.h"
#pragma once

template<class T>
class Collection
{
public:
	virtual void print() const = 0;
	virtual void add(T) = 0;
	virtual void remove() = 0;
	virtual T& peek() const = 0;
	virtual Collection<T>* clone() const = 0;
};
