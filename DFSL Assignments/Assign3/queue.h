/*
 * queue.h
 *
 *  Created on: 05-Feb-2019
 *      Author: neo
 */

#ifndef QUEUE_H_
#define QUEUE_H_
template <class T>

class Queue {

	struct queue {
		T obj;
		struct queue *next;
	};
	struct queue *front;
	struct queue *rear;
public:

	void enque(T data);
	T dequeue();
	bool isEmpty();
	Queue();
	virtual ~Queue();
};
#endif /* QUEUE_H_ */
