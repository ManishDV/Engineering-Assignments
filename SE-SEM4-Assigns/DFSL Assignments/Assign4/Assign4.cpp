//============================================================================
// Name        : Assign4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string.h>
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
struct tree {
	char data;
	struct tree *left;
	struct tree *right;
};

class ExpressionTree{
	struct tree *root;
	char *exp;
	Stack <struct tree *> s;

public:
	ExpressionTree(){
		root = new struct tree;
		root = NULL;
		exp = new char[30];
	}

   void getExpression()
   {
	   cout<<"\n\nEnter Postfix Expression: ";
	   cin>>exp;
   }

   void dispExp()
   {
	   if(strlen(exp) == 0)
		   	  cout<<"\n\nPlease Enter The Expression First";
	   else
		   cout<<"\n\nPostfix Expression Is: "<<exp;
   }

   bool isOperator(char c){
   	if(c == '+'|| c == '-' || c == '/' || c == '*' || c == '^' || c == '%')
   		return true;
   	return false;
   }

   bool isOperand(char c)
   {
	   if(isdigit(c) || isalpha(c))
		   return true;
	   return false;
   }

   struct tree * convert()
   {
	   if(strlen(exp) == 0)
	   	  cout<<"\n\nPlease Enter The Expression First";
	   else
	   {
		   int i = 0;
		   while(*(exp+i) != '\0')
		   {
			   if(isOperand(*(exp+i)))
			   {
				   struct tree *temp = new struct tree;
				   temp->data = *(exp+i);
				   temp->left = NULL;
				   temp->right = NULL;
				   s.push(temp);
				   i++;
				   continue;
			   }

			   if(isOperator(*(exp+i)))
			   {
				   struct tree *temp = new struct tree;
				   temp->data = *(exp+i);
				   temp->right = s.pop();
				   temp->left = s.pop();

				   s.push(temp);
				   i++;
				   continue;
			   }
		   }

		   cout<<"\n\nExpression Successfully Converted to Tree";
	   }
	   return s.pop();

   }

   int length()
   {
	   return strlen(exp);
   }

   struct tree * getRoot()
   {
	   return root;
   }

   void setRoot(struct tree * temp)
   {
	   root = temp;
   }
   void R_inorder(struct tree *root)
   {
	   if(root != NULL)
	   {
		   R_inorder(root->left);
	   	   cout<<" "<<root->data;
	   	   R_inorder(root->right);
	   }
   }

   void R_preorder(struct tree *root)
   {
	   if(root != NULL)
   	   {
		   cout<<" "<<root->data;
	   	   R_preorder(root->left);
   	   	   R_preorder(root->right);
   	   }
   }

   void R_postorder(struct tree *root)
   {
	   if(root != NULL)
   	   {
		   R_postorder(root->left);
   	   	   R_postorder(root->right);
   	   	   cout<<" "<<root->data;

   	   }
   }


   void NR_inorder(struct tree *root)
   {
	   struct tree * temp = root;
	   while(true)
	   {
		   while(temp != NULL)
		   {
			   s.push(temp);
			   temp = temp->left;
		   }
		   if(s.isEmpty())
		   {
			   return;
		   }

		   temp = s.pop();
		   cout<<" "<<temp->data;
		   temp = temp->right;
	   }
   }

   void NR_preorder(struct tree *root)
   {
	   struct tree * temp = root;
	   while(true)
	   {
		   while(temp != NULL)
		   {
			   cout<<" "<<temp->data;
			   s.push(temp);
			   temp = temp->left;
		   }
		   if(s.isEmpty())
		   {
			   return;
		   }

		   temp = s.pop();
		   temp = temp->right;
	   }
   }

   void NR_postorder(struct tree *root)
   {
	   Stack<struct tree *>s1;
	   struct tree * temp = root;
	   struct tree *temp1;
	   s.push(temp);
	   while(s.isEmpty() == false)
	   {
		   temp1 = s.pop();
		   s1.push(temp1);

		   if(temp1->left != NULL)
		   {
			   s.push(temp1->left);
		   }
		   if(temp1->right != NULL){
			   s.push(temp1->right);
		   }
	   }

	   while(s1.isEmpty() == false)
	   {
		   cout<<" "<<s1.pop()->data;
	   }
   }
};

int main() {

	int choice = 0,choice1 = 0;
	ExpressionTree t;

	struct tree *dummy;

	do {
		cout << "\n\n ----- MENU --------";
		cout << "\n1.Enter Postfix Expression";
		cout << "\n2.Display Postfix Expression.";
		cout << "\n3.Convert To Expression Tree";
		cout << "\n4.Display Using Recursive Algorithm";
		cout << "\n5.Display Using Non-Recursive Algorithm";
		cout << "\n6.Exit";
		cout << "\n---------------------";

		cout << "\nEnter Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
					t.getExpression();
					break;

		case 2:
					t.dispExp();
					break;
		case 3:

					dummy = t.convert();
					t.setRoot(dummy);
					break;
		case 4:

								   if(t.length() == 0)
									   cout<<"\n\nEnter Expression First";
								   else
								   {
									   if(t.getRoot() == NULL)
										    cout<<"\n\nPlease Convert The Expression To Tree";
									   else
									   {
										   do{
											   cout << "\n\n ----- Recursive Choice --------";
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

											   		   	   t.R_inorder(t.getRoot());
											   		   	   break;
											   	   case 2:
											   		   	   t.R_preorder(t.getRoot());
											   		   	   break;
											   	   case 3:
											   		   	   t.R_postorder(t.getRoot());
											   		   	   break;
											   	   case 4:
											   		   return 0;
											   	   default:
											   		    	cout<<"\n\nPlease Enter Valid Choice.";
											   }
										     }while(choice1 != 4);
									    }

								    }
								   break;

					case 5:
								if(t.length() == 0)
									cout<<"\n\nEnter Expression First";
								else
								{
									if(t.getRoot() == NULL)
										cout<<"\n\nPlease Convert The Expression To Tree";
									else
									{
										do{
											cout << "\n\n ----- Non-Recursive Choice --------";
											cout << "\n1.Inorder";
											cout << "\n2.Preorder";
											cout << "\n3.Postorder";
											cout << "\n4.Exit";
											cout << "\n-------------------------------------";

											cout << "\nEnter Your choice: ";
											cin >> choice1;

											switch(choice1)
											{
												case 1:

														t.NR_inorder(t.getRoot());
														break;
												case 2:
														t.NR_preorder(t.getRoot());
														break;
												case 3:
														t.NR_postorder(t.getRoot());
														break;
												case 4:
														return 0;
												default:
													cout<<"\n\nPlease Enter Valid Choice.";

									   }
								     }while(choice1 != 4);
							    }

						    }

						break;

					case 6:
						     return 0;
					default:
						cout<<"\n\nPlease Enter Valid Choice.";

		}
	} while (choice != 6);
	return 0;
}
