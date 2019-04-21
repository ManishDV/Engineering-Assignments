/*
 * queueADT.h
 *
 *  Created on: 19-Apr-2019
 *      Author: neo
 */

#ifndef QUEUEADT_H_
#define QUEUEADT_H_
template<class T>
class queueADT {

	struct node{
		T data;
		int priority;
		struct node *next;
	};

	struct node *rear;
	struct node *front;

public:
	queueADT();
	virtual ~queueADT();
	void enqueue(T data,int priority);
	T dequeue();
	T* display();
	bool isEmpty();
	int nodeCount();
};

#endif /* QUEUEADT_H_ */
