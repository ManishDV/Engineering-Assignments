//============================================================================
// Name        : Assign5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.cpp"
#include "Queue.h"
using namespace std;

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

class BST {
	struct tree *root;

public:
	BST() {
		root = NULL;
	}

	struct tree *getRoot() {
		return root;
	}
	void setRoot(struct tree *dummy) {
		root = dummy;
	}

	struct tree *insert(struct tree *root, int data) {
		if (root == NULL) {
			struct tree *temp = new struct tree;
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;
			root = temp;
			return root;
		} else if (root->data > data) {
			root->left = insert(root->left, data);
		} else if (root->data < data) {
			root->right = insert(root->right, data);
		} else {
			cout << "\nDuplication Not Allowed";
		}
		return root;
	}

	void inorder(struct tree *root) {
		if (root != NULL) {
			inorder(root->left);
			cout << " " << root->data;
			inorder(root->right);
		}
	}

	void preorder(struct tree *root) {
		if (root != NULL) {
			cout << " " << root->data;
			preorder(root->left);
			preorder(root->right);
		}
	}

	void postorder(struct tree *root) {
		if (root != NULL) {
			postorder(root->left);
			postorder(root->right);
			cout << " " << root->data;

		}
	}

	void display() {
		cout << "\nInorder Display   : ";
		inorder(root);
		cout << "\nPreorder Display  : ";
		preorder(root);
		cout << "\nPostorder Display : ";
		postorder(root);

	}

	void levelorder(){

		struct tree *temp = root;
		Queue<struct tree *>q;

		while(true){

			cout<<" "<<temp->data;
			if(temp->left != NULL)
				q.enque(temp->left);
			if(temp->right != NULL)
				q.enque(temp->right);

			if(q.isEmpty())
				return;

			temp = q.dequeue();
		}

	}

	void search(struct tree *root,int data){

		if(root == NULL){
			cout<<"\nElement Is Not Present In BST";
			return;
		}


		if(root->data == data){
			cout<<"\nElement Found In BST !!!!!";
			return;
		}else if(root->data > data){
			search(root->left,data);
		}else{
			search(root->right,data);
		}

	}

	struct tree* deleteNode(struct tree *root,int key){

		if(root == NULL)
			return 0;
		else if(root->data < key)
			root->right = deleteNode(root->right,key);
		else if(root->data > key)
			root->left = deleteNode(root->left,key);
		else{
			if(root->left == NULL){
				struct tree *temp = root->right;
				delete root;
				return temp;
			}

			if(root->right == NULL){
				struct tree *temp = root->left;
				delete root;
				return temp;
			}
			if(root->right == NULL && root->left == NULL){
				delete root;
				return NULL;
			}
			struct tree *temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
		return root;

	}

	struct tree *minValueNode(struct tree *temp){
		while(temp->left != NULL)
			temp = temp->left;
		return temp;
	}

	struct tree * mirror(struct tree *root){

		if(root != NULL){
			struct tree *temp = root->left;
			root->left = root->right;
			root->right = temp;
			mirror(root->left);
			mirror(root->right);
		}

		return root;
	}

	int height(struct tree *root){
		if(root == NULL)
			return 0;
		return 1+max(height(root->left),height(root->right));
	}
};
int main() {

	int choice = 0;
	BST bst;
	struct tree *dummy;

	do {
		cout << "\n\n ----- MENU --------------------------";
		cout << "\n1.Insert In BST";
		cout << "\n2.Display BST";
		cout << "\n3.Display BST Level Wise";
		cout << "\n4.Search In BST";
		cout << "\n5.Delete From BST";
		cout << "\n6.Mirror Image Of BST";
		cout << "\n7.Height Of BST";
		cout << "\n8.Exit";
		cout << "\n-----------------------------------------";

		cout << "\nEnter Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			int data;
			cout << "\n\nEnter Data To Insert In BST: ";
			cin >> data;

			dummy = bst.insert(bst.getRoot(), data);
			bst.setRoot(dummy);
			break;
		case 2:

			if (bst.getRoot() == NULL) {
				cout << "\n\nTree Is Empty!!!!";
			} else {
				bst.display();
			}
			break;
		case 3:

			if (bst.getRoot() == NULL) {
				cout << "\n\nTree Is Empty!!!!";
			} else {
				cout << "\nLevel order Display : ";

				bst.levelorder();
			}

			break;
		case 4:
			if (bst.getRoot() == NULL) {
				cout << "\n\nTree Is Empty!!!!";
			} else {
				int data = 0;
				cout<<"\nEnter The Data You Want To Search: ";
				cin>>data;

				bst.search(bst.getRoot(),data);
			}

			break;
		case 5:
			if (bst.getRoot() == NULL) {
				cout << "\n\nTree Is Empty!!!!";
			} else {

				int data = 0;
				cout<<"\nEnter Data You Want To Delete: ";
				cin>>data;

				dummy = bst.deleteNode(bst.getRoot(),data);
				bst.setRoot(dummy);
			}

			break;
		case 6:
			if (bst.getRoot() == NULL) {
				cout << "\n\nTree Is Empty!!!!";
			} else {
				dummy = bst.mirror(bst.getRoot());
				bst.inorder(dummy);
			}
			break;
		case 7:
			if (bst.getRoot() == NULL) {
				cout << "\n\nTree Is Empty!!!!";
			} else {
				cout<<"\nHeight Of The Tree Is: "<<bst.height(bst.getRoot());
			}

			break;

		}
	} while (choice != 8);
	return 0;
}
