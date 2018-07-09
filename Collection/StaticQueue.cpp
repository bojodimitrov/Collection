#include "stdafx.h"
#include "Collection.cpp"

#define BASE_SIZE 20

template<class T>
class StaticQueue : public Collection<T> {
private:
	T data[BASE_SIZE];
	int front, rear;

public:
	StaticQueue() {
		front = 0;
		rear = 0;
	}

	StaticQueue(const StaticQueue& _sq) {
		front = 0;
		rear = 0;
		for (int i = _sq.front; i < _sq.rear; i++) {
			this->add(_sq.data[i]);
		}
	}

	StaticQueue& operator = (const StaticQueue& _sq) {
		if (*this != _sq) {
			front = 0;
			rear = 0;
			for (int i = _sq.front; i < _sq.rear; i++) {
				this->add(_sq.data[i]);
			}
		}
		return *this;
	}

	void add(T new_data) {
		if (BASE_SIZE == rear) {
			if (front > 0) {
				for (int i = front; i < rear; i++)
				{
					data[i - front] = data[i];
				}
				rear -= front;
				front = 0;
			}
			else {
				std::cout << "Queue is full." << std::endl;
			}
		}

		data[rear] = new_data;
		rear++;
	}

	bool empty() const {
		return front == rear;
	}

	void remove() {
		if (rear == front) {
			std::cout << "Queue is empty." << std::endl;
		}
		else {
			front++;
		}
	}

	bool operator == (const StaticQueue& _sq) const {
		if ((this->empty() && !_sq.empty()) || (!empty() && _sq.empty())) {
			return false;
		}
		if ((this->empty() && _sq.empty())) {
			return true;
		}
		int delta = _sq.front - this->front;
		for (int i = front; i < rear; i++)
		{
			if (_sq.data[i + delta] != this->data[i] || i + delta == BASE_SIZE) {
				return false;
			}
		}
		return true;
	}

	T& peek() const {
		if (front == rear) {
			return {};
		}
		return data[front];
	}

	void print() const {
		if (rear == front) {
			std::cout << "Queue is empty." << std::endl;
			return;
		}
		for (int i = front; i < rear; i++) {
			std::cout << data[i] << ", ";
		}
		std::cout << "END_Q" << std::endl;

	}

	StaticQueue<T>* clone() const {
		return new StaticQueue(*this);
	}
};