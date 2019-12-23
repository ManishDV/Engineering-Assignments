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
template <class T>
Queue<T>::~Queue() {
	// TODO Auto-generated destructor stub

	while(!isEmpty())
		deQueue();

}
template<class T>
bool Queue<T>::isEmpty(){

	if(front == NULL && rear == NULL)
	   return true;
	return false;
}

template<class T>
void Queue<T>::enQueue(T obj,int priority){

	if(isEmpty())
	{
		struct queue *temp = new struct queue;
		temp->ob = obj;
		temp->priority = priority;
		temp->next = NULL;

		front = temp;
		rear = temp;

	}
	else
	{
		rear->next = new struct queue;
		rear = rear->next;
		rear->ob = obj;
		rear->priority = priority;
		rear->next = NULL;
	}

}

template<class T>
T Queue<T>::deQueue(){

	T obj;
	struct queue *temp;
	struct queue *max;
	struct queue *tempPrev;
	struct queue *maxPrev;

	max = front;
	temp = front->next;
	tempPrev = front;
	maxPrev = NULL;
	while(temp != NULL)
	{
		if(temp->priority > max->priority)
		{
			maxPrev = tempPrev;
			max = temp;
		}
		tempPrev = temp;
		temp = temp->next;
	}


	if(max == front)
	{
		if(front->next == NULL)
		{
			obj = max->ob;
		   front = front->next;
		   rear = NULL;
		}
		else
		{

			obj = max->ob;
		   front = front->next;


		}

	}

    else if(max->next == NULL)
	{

	     obj = max->ob;
		maxPrev->next = NULL;
		rear = maxPrev;


	}
    else if(maxPrev == NULL)
	{

	     obj =  max->ob;
		front = max->next;
		rear =  max->next;
	}
	else{

	     obj = max->ob;
		maxPrev->next = max->next;
	}


	return obj;
}

template <class T>
int Queue<T>::NodeCount()
{
	struct queue *temp;
	temp = front;
	int i=0;
	while(temp != NULL)
	{
		i++;
		temp = temp->next;
	}

	return i;
}





template<class T>
T *Queue<T>::display(){
	struct queue *temp;
	temp = front;
	int count = NodeCount();
	T *list = new T[count];

	int i=0;
	while(temp != NULL)
	{
		list[i] = temp->ob;
		i++;
		temp=temp->next;
	}
	return list;
}
