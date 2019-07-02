//============================================================================
// Name        : cpp.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//Implement  BST and Perform:
//1.insert
//2.Delete
//3.Search
//4.Mirror Image
//5.Display
//6.Display Level wise
//7.Height Of Binary Tree
//============================================================================

#include <iostream>
#include "queue.cpp"
#include "queue.h"

using namespace std;

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};
class BST{

	struct tree *root;

public:

	BST()
	{

		root = new struct tree;
		root = NULL;
	}

	struct tree * getRoot()
	{
		return root;
	}

	void setRoot(struct tree *temp){
		root = temp;
	}

	struct tree *insert(int data,struct tree *root)
	{

		if(root == NULL)
		{
			struct tree *temp = new struct tree;
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;

			root = temp;
			return root;
       }
	   else
	   {
		   if(data < root->data)
		   {
			   root->left = insert(data,root->left);

		   }
		   else if(data > root->data)
		   {
			   root->right = insert(data,root->right);
		   }
		   else
		   {
			   cout<<"\n\nDuplication Is Not Allowed";
		   }
		   return root;
	   }

		return root;
	}


	void inOrder(struct tree *root)
	{
		if(root != NULL)
		{
			inOrder(root->left);
			cout<<" "<<root->data;
			inOrder(root->right);
		}
	}
	void preOrder(struct tree *root)
	{
		if(root != NULL)
		{
			cout<<" "<<root->data;
			inOrder(root->left);
			inOrder(root->right);

		}
	}
	void postOrder(struct tree *root)
	{
		if(root != NULL)
		{
			inOrder(root->left);
			inOrder(root->right);
			cout<<" "<<root->data;

		}
	}

	void levelOrder() {
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


	void search(int data)
	{
		struct tree *temp = root;

		while(temp != NULL){
			if(data < temp->data && temp->left != NULL){
				temp = temp->left;
			}else if(data > temp->data && temp->right != NULL){
				temp = temp->right;
			}else if(temp->data == data){
				cout<<"\n\nData Is Present";
				return;
			}
			else
			{
					cout<<"\n\nData Is NOT Present";
					return;
			}
		}
	}

	struct tree* deleteNode(struct tree* root, int key)
	{
	    if (root == NULL) return root;
	    if (key < root->data)
	        root->left = deleteNode(root->left, key);
	    else if (key > root->data)
	        root->right = deleteNode(root->right, key);
	    else
	    {
	        if (root->left == NULL)
	        {
	            struct tree *temp = root->right;
	            delete root;
	            return temp;
	        }
	        else if (root->right == NULL)
	        {
	            struct tree *temp = root->left;
	            delete root;
	            return temp;
	        }

	        struct tree* temp = minValueNode(root->right);
	        root->data = temp->data;
	        root->right = deleteNode(root->right, temp->data);

	    }


	    return root;
	}

	struct tree * minValueNode(struct tree* node)
	{
	    struct tree* current = node;

	    while (current->left != NULL)
	        current = current->left;

	    return current;
	}

	struct tree* mirrorImage(struct tree *root){
		struct tree *temp;
		if(root != NULL)
		{
			temp = root->left;
			root->left = root->right;
			root->right = temp;
			mirrorImage(root->left);
			mirrorImage(root->right);
		}
		return root;
	}

	int height(struct tree *root)
	{
		if (root == NULL)
				return 0;
			return 1 + max(height(root->left), height(root->right));
	}
};
int main() {

	int choice = 0,choice1 = 0;
	BST bst;
	struct tree *dummy;


	do{
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

		switch(choice)
		{
			case 1:
					int data;
					cout<<"\n\nEnter Data To Insert In BST: ";
					cin>>data;
					dummy = bst.insert(data,bst.getRoot());
					bst.setRoot(dummy);
					break;
			case 2:

				    if(bst.getRoot() == NULL){
				    	cout<<"\n\nTree Is Empty!!!!";
				    }else
				    	{
				    		do{
				    			cout << "\n\n ----- Display Choice --------";
				    			cout << "\n1.Inorder";
				    			cout << "\n2.Preorder";
				    			cout << "\n3.Postorder";
				    			cout << "\n4.Exit";
				    			cout << "\n-----------------------------";

				    			cout << "\nEnter Your choice: ";
				    			cin >> choice1;

				    			switch(choice1)
				    			{
				    			case 1:

				    				bst.inOrder(bst.getRoot());
				    				break;
				    			case 2:
				    				bst.preOrder(bst.getRoot());
				    				break;
				    			case 3:
				    				bst.postOrder(bst.getRoot());
				    				break;
				    			case 4:
				    				break;
				    			default:
				    				cout<<"\n\nPlease Enter Valid Choice.";
				    			}
				    		}while(choice1 != 4);
				    	}
				      break;
			case 3:

				if(bst.getRoot() == NULL){
					cout<<"\n\nTree Is Empty!!!!";
				}else{
					bst.levelOrder();
				}

				break;
			case 4:
				if(bst.getRoot() == NULL){
					cout<<"\n\nTree Is Empty!!!!";
				}else{
					int data;
					cout<<"\n\nEnter Data To Be Searched In BST: ";
					cin>>data;

					bst.search(data);
				}

				break;
			case 5:
				if(bst.getRoot() == NULL){
					cout<<"\n\nTree Is Empty!!!!";
				}else{
					int data;
					cout<<"\n\nEnter Data To Be Deleted From BST: ";
					cin>>data;

					dummy = bst.deleteNode(bst.getRoot(),data);
					bst.setRoot(dummy);
				}

				break;
			case 6:
				if(bst.getRoot() == NULL){
					cout<<"\n\nTree Is Empty!!!!";
				}else{
					dummy = bst.mirrorImage(bst.getRoot());
					cout<<"\n\nData Of Mirrored Tree Is: ";
					bst.inOrder(dummy);
				}
				break;
			case 7:
				if(bst.getRoot() == NULL){
					cout<<"\n\nTree Is Empty!!!!";
				}else{
					int i = bst.height(bst.getRoot());
					cout<<"\n\nHeight Of Binary Tree Is: "<<i;
				}

				break;

		}
	}while(choice != 8);
return 0;
}

