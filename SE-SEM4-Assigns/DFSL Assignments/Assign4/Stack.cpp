/*
 * Stack.cpp
 *
 *  Created on: 27-Dec-2018
 *      Author: neo
 */

#include "Stack.h"
#include <iostream>
using namespace std;

template<class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	top = new struct node;
	top = NULL;
}

template<class T>
Stack<T>::~Stack(){

	struct node *cur;
	cur = top;
	while(cur != NULL)
	{
		top = top->next;
		delete cur;
		cur = top;
	}
}

template<class T>
void Stack<T>::push(T x){
	struct node *temp ;
	temp = new struct node;

	temp->data = x;

	temp->next = top;
	top = temp;
}

template<class T>
T Stack<T>::pop(){
	struct node *temp ;
	if(isEmpty()){
		return 0;
	}
	else
	{
		temp = top;
		T x= temp->data;
		top = top->next;
		delete temp;
		return x;
	}
}

template<class T>
bool Stack<T>::isEmpty(){
	if(top == NULL)
		return true;
	return false;
}


template<class T>
T Stack<T>::Top(){
	if(isEmpty()){
		return 0;
	}
	else
	{
		return top->data;
	}

}
