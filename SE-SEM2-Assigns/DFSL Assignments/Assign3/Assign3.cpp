//============================================================================
// Name        : Assignment3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "queue.cpp"
#include "queue.h"

using namespace std;

struct tree {
	char data;
	struct tree *left;
	struct tree *right;
};

class BinaryTree {

	struct tree *root;
public:

	BinaryTree() {
		root = NULL;
	}
	struct tree* insert(struct tree *root);
	void levelOrder(struct tree *root);
	int height(struct tree *root);
	void dispLeaves(struct tree *root);
	struct tree *copy(struct tree *root);

	struct tree * getRoot() {
		return root;
	}

	void setRoot(struct tree * temp) {
		root = temp;
	}

};
struct tree * BinaryTree::insert(struct tree *root) {
	if (root == NULL) {
		char x;
		root = new struct tree;
		cout << "\nEnter Data In Root Node: ";
		cin >> x;

		root->data = x;
		root->left = NULL;
		root->right = NULL;
		return root;
	} else {
		struct tree *t, *p;
		t = root;
		char x;
		int choice = 0;
		do {
			cout << "\nEnter 1 to add Left of " << t->data
					<< " or 2 to add Right of " << t->data << ": ";
			cin >> choice;

			if (choice != 1 && choice != 2)
				cout << "\nPlease Enter Valid Choice";
			if (choice == 1 && t->left == NULL) {
				cout << "\n\nEnter Data To Be Inserted: ";
				cin >> x;

				p = new struct tree;
				p->data = x;

				p->left = NULL;
				p->right = NULL;

				t->left = p;
				return root;
			} else {
				if (choice == 1)
					t = t->left;
			}

			if (choice == 2 && t->right == NULL) {
				cout << "\n\nEnter Data To Be Inserted: ";
				cin >> x;

				p = new struct tree;
				p->data = x;

				p->left = NULL;
				p->right = NULL;

				t->right = p;
				return root;
			} else {
				if (choice == 2)
					t = t->right;
			}

		} while (1);

	}
	return root;
}
void BinaryTree::levelOrder(struct tree *root) {
	cout << "\n";
	struct tree *temp = root;
	Queue<struct tree *> q;

	while (temp != NULL) {
		cout << temp->data << " ";

		if (temp->left != NULL) {
			q.enque(temp->left);
		}
		if (temp->right != NULL) {
			q.enque(temp->right);
		}
		if (q.isEmpty())
			temp = NULL;
		else
			temp = q.dequeue();

	}
}
int BinaryTree::height(struct tree *root) {

	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

void BinaryTree::dispLeaves(struct tree *root) {

	//cout<<"\n";
	struct tree *temp = root;
	if (temp != NULL) {
		if (temp->left == NULL && temp->right == NULL) {
			cout << temp->data << " ";
		}
		dispLeaves(temp->left);
		dispLeaves(temp->right);
	}
}

struct tree * BinaryTree::copy(struct tree *root) {
	struct tree *temp = NULL;

	if (root != NULL) {
		temp = new struct tree;

		temp->data = root->data;
		temp->left = copy(root->left);
		temp->right = copy(root->right);
	}

	return temp;
}
int main() {

	int choice = 0;
	BinaryTree bt;

	struct tree * dummyRoot;

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
		case 1:
			dummyRoot = bt.getRoot();
			dummyRoot = bt.insert(dummyRoot);
			bt.setRoot(dummyRoot);
			break;

		case 2:
			if (bt.getRoot() == NULL) {
				cout << "\nTree Is Empty...";
			} else {
				bt.levelOrder(bt.getRoot());
			}
			break;
		case 3:
			if (bt.getRoot() == NULL) {
				cout << "\nTree Is Empty...";
			} else {
				int depth;
				depth = bt.height(bt.getRoot());
				cout << "\nDepth Of The Tree Is: " << depth;
			}
			break;
		case 4:
			if (bt.getRoot() == NULL) {
				cout << "\nTree Is Empty...";
			} else {
				bt.dispLeaves(bt.getRoot());
			}
			break;

		case 5:
			if (bt.getRoot() == NULL) {
				cout << "\nTree Is Empty...";
			} else {
				struct tree *node = new struct tree;
				node = bt.copy(bt.getRoot());

				cout<<"\n\nCopied Tree Is: ";
				bt.levelOrder(node);
			}
			break;
		}
	} while (choice != 6);
	return 0;
}
