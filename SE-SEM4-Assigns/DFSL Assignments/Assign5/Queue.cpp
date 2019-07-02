/*
 * queue.cpp
 *
 *  Created on: 05-Feb-2019
 *      Author: neo
 */

#include "Queue.h"
#include <iostream>
using namespace std;

template<class T>
Queue<T>::Queue() {
	// TODO Auto-generated constructor stub

	front = new struct queue;
	rear = new struct queue;
	front = NULL;
	rear = NULL;
}
template<class T>
Queue<T>::~Queue() {
	// TODO Auto-generated destructor stub
}
template<class T>
bool Queue<T>::isEmpty() {
	if (front == NULL && rear == NULL)
		return true;
	return false;
}

template<class T>
void Queue<T>::enque(T data) {
	if (isEmpty()) {
		struct queue *temp = new struct queue;

		temp->obj = data;
		temp->next = NULL;

		front = temp;
		rear = temp;
	} else {
		rear->next = new struct queue;
		rear = rear->next;
		rear->obj = data;

		rear->next = NULL;
	}
}

template<class T>
T Queue<T>::dequeue() {
	struct queue *temp = front;
	T ob;
	if (front != rear) {
		front = front->next;
		ob = temp->obj;
		delete temp;
	} else {
		front = front->next;
		ob = temp->obj;
		delete temp;
		rear = NULL;
	}
	return ob;
}
