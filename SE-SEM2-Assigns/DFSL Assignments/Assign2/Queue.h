/*
 * Queue.h
 *
 *  Created on: 07-Jan-2019
 *      Author: h11
 */

#ifndef QUEUE_H_
#define QUEUE_H_
template<class T>
class Queue{

	struct queue{
		T ob;
		int priority;
		struct queue *next;
	};

	struct queue *rear;
	struct queue *front;

public:
	Queue();
	virtual ~Queue();
	bool isEmpty();
	void enQueue(T ob,int priority);
	T deQueue();
	T* display();
	int NodeCount();



};

#endif /* QUEUE_H_ */
