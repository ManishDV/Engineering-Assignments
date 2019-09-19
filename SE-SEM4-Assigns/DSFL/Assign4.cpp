//============================================================================
// Name        : Assign4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;

struct treenode{
	char data;
	struct treenode *left;
	struct treenode *right;

};
class ExpressionTree{
	char exp[40];
	struct treenode *root;

public:
	ExpressionTree(){
		root = NULL;
		exp[0] = '\0';
	}
	bool isOperator(char c) {
		if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '%' || c == '!')
			return true;
		return false;
	}

	struct treenode* getNconvert(){
		cout<<"\n\nEnter Postfix Expression: ";
		cin>>exp;

		Stack<struct treenode*> s;

		for(int i = 0;exp[i]!='\0';i++){
			if(isalpha(exp[i])){
				struct treenode *temp = new struct treenode;
				temp->data = exp[i];
				temp->left = NULL;
				temp->right = NULL;
				s.push(temp);
			}
			if(isOperator(exp[i])){
				struct treenode *temp = new struct treenode;
				temp->data = exp[i];
				temp->right = s.pop();
				temp->left = s.pop();
				s.push(temp);
			}
		}

		return s.pop();
	}

	void setRoot(struct treenode *dummy){
		root  = dummy;
	}

	struct treenode* getRoot(){
		return root;
	}

	void inorder(struct treenode *root)
	{
		if(root != NULL)
		{
		inorder(root->left);
		cout<<"  "<<root->data;
		inorder(root->right);
		}
	}

	void preorder(struct treenode *root)
	{
		if(root != NULL)
		{
				cout<<"  "<<root->data;
				preorder(root->left);
				preorder(root->right);
		}
	}

	void postorder(struct treenode *root)
	{
		if(root != NULL)
		{
				postorder(root->left);
				postorder(root->right);
				cout<<"  "<<root->data;

		}
	}

	void displayR(){
		cout<<"\nInorder Display   : ";
		inorder(root);
		cout<<"\nPreorder Display  : ";
		preorder(root);
		cout<<"\nPostorder Display : ";
		postorder(root);
	}

	void inorderNR(struct treenode *root){
		struct treenode *temp = root;
		Stack<struct treenode*> s;
		while(true){

			while(temp != NULL){
				s.push(temp);
				temp = temp->left;
			}

			if(s.isEmpty())
				return;

			temp = s.pop();
			cout<<" "<<temp->data;
			temp = temp->right;
		}
	}
	void preorderNR(struct treenode *root){
		struct treenode *temp = root;
		Stack<struct treenode*> s;
		while(true){

			while(temp != NULL){

				cout<<" "<<temp->data;
				s.push(temp);
				temp = temp->left;
			}

			if(s.isEmpty())
				return;

			temp = s.pop();
			temp = temp->right;
		}
	}
	void postorderNR(struct treenode *root){
		struct treenode *temp = root;
		Stack<struct treenode*> s;
		Stack<struct treenode*> s1;
		s.push(temp);
		struct treenode *temp1;
		while(!s.isEmpty()){
			temp1 = s.pop();
			s1.push(temp1);

			if(temp1->left != NULL)
				s.push(temp1->left);
			if(temp1->right != NULL)
				s.push(temp1->right);
		}

		while(!s1.isEmpty())
			cout<<" "<<s1.pop()->data;
	}
	void displayNR(){
			cout<<"\nInorder Display   : ";
			inorderNR(root);
			cout<<"\nPreorder Display  : ";
			preorderNR(root);
			cout<<"\nPostorder Display : ";
			postorderNR(root);
	}




};
int main() {

	int choice = 0;
	ExpressionTree et;
	struct treenode *dummy;
	do{
		cout<<"\n\n--------------- MENU ------------------";
		cout<<"\n\n1.Input Expression And Convert";
		cout<<"\n2.Display Using Recursive Function.";
		cout<<"\n3.Display Using Non-Recursive Algorithms.";
		cout<<"\n4.EXIT";
		cout<<"\n\n---------------------------------------";

		cout<<"\nEnter Your Choice: ";
		cin>>choice;

		switch(choice){
		case 1:
			dummy = et.getNconvert();
			et.setRoot(dummy);
			break;
		case 2:
			et.displayR();
			break;
		case 3:
			et.displayNR();
			break;
		case 4:
			return 0;
		default:
			cout<<"\nPlease Enter Valid Choice";
		}
	}while(choice != 4);
	return 0;
}
