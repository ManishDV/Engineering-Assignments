#ifndef STACK_H_
#define STACK_H_

template<class T>
class Stack {

	struct node{
		T data;
		struct node *next;
	};


	struct node *top;

public:

	Stack();
	virtual ~Stack();
	void push(T x);
	T pop();
	T Top();
	bool isEmpty();
};

#endif /* STACK_H_ */
