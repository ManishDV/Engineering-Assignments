/*
 * queueADT.cpp
 *
 *  Created on: 19-Apr-2019
 *      Author: neo
 */

#include "queueADT.h"
#include <iostream>
using namespace std;
template<class T>
queueADT<T>::queueADT() {
	// TODO Auto-generated constructor stub
	front = NULL;
	rear = NULL;
}
template<class T>
queueADT<T>::~queueADT() {
	// TODO Auto-generated destructor stub
//	while (!isEmpty())
//		dequeue();
}

template<class T>
bool queueADT<T>::isEmpty() {
	if (rear == NULL && front == NULL)
		return true;
	return false;
}

template<class T>
void queueADT<T>::enqueue(T data, int priority) {

	struct node *temp = new struct node;
	temp->data = data;
	temp->priority = priority;
	temp->next = NULL;
	if (isEmpty()) {
		rear = temp;
		front = temp;
	} else {
		rear->next = temp;
		rear = temp;
	}
}

template<class T>
T queueADT<T>::dequeue() {

	struct node *max = front;
	struct node *temp = front->next;
	struct node *prevTemp = front;
	struct node *prevMax = NULL;

	while (temp != NULL) {

		if (temp->priority > max->priority) {
			prevMax = prevTemp;
			max = temp;
		}

		prevTemp = temp;
		temp = temp->next;
	}

	if (max == front) {
		if (front->next == NULL) {

			front = front->next;
			rear = front;
		} else {
			front = front->next;
		}

	} else if (max->next == NULL) {
		rear = prevMax;
		prevMax->next = NULL;
	} else {
		prevMax->next = prevTemp;
	}
	return max->data;
}

template<class T>
int queueADT<T>::nodeCount() {

	int count = 0;
	if (isEmpty())
		return 0;
	else {
		struct node *temp = front;
		while (temp != NULL) {
			count++;
			temp = temp->next;

		}
	}
	return count;
}

template<class T>
T* queueADT<T>::display() {

	struct node *temp = front;
	int count = nodeCount();
	T *list = new T[count];
	int i = 0;
	while (temp != NULL) {
		list[i] = temp->data;
		i++;
		temp = temp->next;
	}

	return list;
}
