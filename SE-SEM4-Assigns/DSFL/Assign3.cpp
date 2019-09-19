//============================================================================
// Name        : Assign3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "queueADT.cpp"
#include "queueADT.h"

#include <iostream>
using namespace std;


struct treenode{
	char data;
	struct treenode *left;
	struct treenode *right;
};
class BTree{
	struct treenode *root;
public:
	BTree(){
		root = new struct treenode;
		root = NULL;
	}

	struct treenode * getRoot(){
		return root;
	}

	void setRoot(struct treenode *dummy){
			root = dummy;
	}


	struct treenode* insert(struct treenode *root){

		if(root == NULL)
		{
			struct treenode *temp = new struct treenode;
			cout<<"\nEnter Root Node Data: ";
			cin>>temp->data;

			temp->left = NULL;
			temp->right = NULL;
			root = temp;
			cout<<"\nNode Added";
			return root;
		}else
		{
			int choice = 0;
			struct treenode *temp = new struct treenode;
			cout<<"\nEnter Node Data: ";
			cin>>temp->data;
			struct treenode *temp1 = root;
			do{
				cout<<"\nTo Add Left of "<<temp1->data<<" Press 1 AND To Add Right of "<< temp1->data<<" Press 2: ";
				cin>>choice;

				if(choice == 1 && temp1->left == NULL){
					temp1->left = temp;
					temp1 = NULL;

				}
				else if(choice == 1 && temp1->left != NULL){
					temp1 = temp1->left;
				}

				else if(choice == 2 && temp1->right == NULL){
					temp1->right = temp;
					temp1 = NULL;
				}
				else{
					temp1 = temp1->right;
				}
			}while(temp1 != NULL);

			cout<<"\nNode Added";
		}
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

	void levelOrder(){

		struct treenode *temp = root;
		queueADT<struct treenode*> q;
		while(1){
			cout<<"  "<<temp->data;
			if(temp->left != NULL)
			{
				q.enqueue(temp->left, 1);
			}

			if(temp->right != NULL){
				q.enqueue(temp->right,1);
			}

			if(q.isEmpty())
				return;

			temp = q.dequeue();
		}

	}
	void display(){
		cout<<"\nInorder Display   : ";
		inorder(root);
		cout<<"\nPreorder Display  : ";
		preorder(root);
		cout<<"\nPostorder Display : ";
		postorder(root);
		cout<<"\nLevelorder Display: ";
		levelOrder();

	}

	int height(struct treenode *root){
		if(root == NULL)
			return 0;

		return 1+max(height(root->left),height(root->right));
	}

	void displayLeaves(struct treenode *root){

		if(root->left == NULL && root->right == NULL)
		{
			cout<<" "<<root->data;
			return;
		}else{
			displayLeaves(root->left);
			displayLeaves(root->right);
		}
	}
	struct treenode* copy(struct treenode *root){
		struct treenode *temp = NULL;
		if(root != NULL){
			temp = new struct treenode;
			temp->data = root->data;
			temp->left = copy(root->left);
			temp->right = copy(root->right);
		}
		return temp;
	}
};
int main() {

	char choice = 0;
	BTree b;
	struct treenode *dummy = b.getRoot();
	do {
			cout << "\n\n ----- MENU --------";
			cout << "\n1.Insert In Tree";
			cout << "\n2.Display Tree Elements.";
			cout << "\n3.Height Of The Tree";
			cout << "\n4.Display Leaf Nodes Of The Tree";
			cout << "\n5.Copy The Content Of Tree";
			cout << "\n6.Exit";
			cout << "\n---------------------";

			cout << "\nEnter Your choice: ";
			cin >> choice;

			switch (choice) {
			case '1':
				dummy = b.insert(dummy);
				b.setRoot(dummy);
				break;

			case '2':
				if (b.getRoot() == NULL) {
					cout << "\nTree Is Empty...";
				} else {
					b.display();
				}
				break;
			case '3':
				if (b.getRoot() == NULL) {
					cout << "\nTree Is Empty...";
				} else {
					cout<<"\nHeight Of The Tree Is: "<<b.height(b.getRoot());
				}
				break;
			case '4':
				if (b.getRoot() == NULL) {
					cout << "\nTree Is Empty...";
				} else {
					cout<<"\n Leaf Nodes Are: ";
					b.displayLeaves(b.getRoot());
				}
				break;

			case '5':
				if (b.getRoot() == NULL) {
					cout << "\nTree Is Empty...";
				} else {
					dummy = b.copy(b.getRoot());
					cout<<"Contents Of Copied Tree Are: ";
					b.inorder(dummy);

				}
				break;
			}
		} while (choice != 6);
	return 0;
}
