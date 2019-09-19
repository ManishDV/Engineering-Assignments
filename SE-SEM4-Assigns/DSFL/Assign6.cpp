//============================================================================
// Name        : Assign6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

struct graphEdge{
//	int weight;
	struct graphVertex *vertex;
	struct graphEdge *edge;
};

struct graphVertex
{
	char name[30];
	int date;
	int month;
	int year;
	int Comments;
	int friends;
	bool visited;
	struct graphVertex *downlink;
	struct graphEdge *edgeLink;
};

class Social_Network{
public:

	struct graphVertex  *start;
	Social_Network(){
		start = new struct graphVertex;
		start->downlink = NULL;

	}

	void addUser(){
		int n = 0;
		cout<<"\nHow Many Users You Want To Add: ";
		cin>>n;

		for(int i = 0;i<n;i++){
			struct graphVertex *temp = new struct graphVertex;
			cout<<"\n----------- ENTER DATA FOR USER "<<i+1<<"------------- \n";
			cout<<"\nEnter Name Of User: ";
			cin>>temp->name;
			cout<<"\nEnter DOB Of User(dd-mm-yyyy): ";
			cin>>temp->date>>temp->month>>temp->year;
			temp->Comments = 0;
			temp->friends = 0;
			temp->visited = false;
			temp->downlink = NULL;
			temp->edgeLink = NULL;
			if(start->downlink == NULL){
				start->downlink = temp;
			}else{
				struct graphVertex *temp2 = start->downlink;
				while(temp2->downlink != NULL){
					temp2 = temp2->downlink;
				}

				temp2->downlink = temp;
			}
		}
		cout<<"\n--------------------------------------------";
		cout<<"\nUsers Added Successfully";
	}

	 void putdata(struct graphVertex *node)
	 {
			 cout<<"\nUser Name: "<<node->name;
			 cout<<"\nUser DOB: "<<node->date<<"/"<<node->month<<"/"<<node->year;
			 cout<<"\nCommented Till Now: "<<node->Comments<<" times";
			 cout<<"\nTotal Friends: "<<node->friends;

			 cout<<"\n----------------------------------------\n";
	 }

	void DFS(struct graphVertex *start){

		if(start == NULL)
			return;

		start->visited = true;
		putdata(start);
		struct graphEdge *temp = start->edgeLink;
		if(temp != NULL){
			 while(temp != NULL)
			 {
				 if(temp->vertex->visited != true)
					 DFS(temp->vertex);
				 temp = temp->edge;
			 }

		}
		else{
			if(start->downlink->visited != true)
						DFS(start->downlink);
		}

	}


	void connect(struct graphVertex *first,struct graphVertex *second)
	{
		struct graphEdge *edge = first->edgeLink;
		struct graphEdge *temp = new struct graphEdge;
		temp->edge = NULL;
		temp->vertex = second;
		if(edge == NULL){
			first->edgeLink = temp;
			first->friends++;
		}else{
			while(edge->edge != NULL)
				edge = edge->edge;

			edge->edge = temp;
			first->friends++;
		}
	}
	void addFriend(struct graphVertex *start){
		bool hasCon = false,Spresent = false,Dpresent = false;
		struct graphVertex *Sind = NULL,*Dind = NULL;

		char name1[40];
		char name2[40];

		cout<<"\nEnter User Name Who Wants To Add Friend: ";
		cin>>name1;
		cout<<"\nEnter Friend Name: ";
		cin>>name2;
		struct graphVertex *temp = start;
		while(temp != NULL){
			if(!strcmp(temp->name,name1))
			{
				Spresent = true;
				Sind = temp;
			}
			if(!strcmp(temp->name,name2))
			{
				Dpresent = true;
				Dind = temp;
			}

			temp = temp->downlink;
		}

		if(Spresent == true && Dpresent == true)
		{
			struct graphEdge *edge = Sind->edgeLink;
			while(edge != NULL)
			{
				if(!strcmp(edge->vertex->name,name2))
					hasCon = true;
				edge = edge->edge;
			}

		}else{
			cout<<"\nEither "<<name1<<" Or "<<name2<<" Is Not Present In The Network";
		}
		if(!hasCon){

			connect(Sind,Dind);
			connect(Dind,Sind);
			cout<<"\nFriend Added";
		}else{
			cout<<"\n"<<name1<<" and "<<name2<<" are already Friends";
		}
	}

	void makeFalse(struct graphVertex *start){
		struct graphVertex *temp = start;
		while(temp != NULL){
			temp->visited = false;
			temp = temp->downlink;
		}
	}

	void dispFriends(struct graphVertex *start){
		char name1[40];
		cout<<"\nEnter Name Of User To See His Friends List: ";
		cin>>name1;
		bool Upresent = false;

		struct graphVertex *temp = start;
		struct graphVertex *Uind = NULL;
		while(temp != NULL){
			if(!strcmp(temp->name,name1))
			{
				Upresent = true;
				Uind = temp;
			}
			temp = temp->downlink;
		}

		if(Upresent){
			cout<<"\n--------------------- Friend's List Of "<<name1<<" ----------------------";
			struct graphEdge *edge1 = Uind->edgeLink;
			while(edge1 != NULL)
			{
				putdata(edge1->vertex);
				edge1 = edge1->edge;
			}
		}
	}
};
int main() {
	struct graphVertex *dummy = NULL;
	int choice = 0;
	Social_Network sn;
	dummy = sn.start;
	do
	{
		cout<<"\n\n-------------- MENU ----------------";
		cout<<"\n1. ADD USER";
		cout<<"\n2. Display USER data";
		cout<<"\n3. ADD FRIEND";
		cout<<"\n4. Display Friends";
		cout<<"\n5. ADD COMMENTS";
		cout<<"\n6. FIND USER HAVING MAX FRIENDS";
		cout<<"\n7. FIND MAX AND MIN COMMENTING USER";
		cout<<"\n8. FIND USER'S BIRTHDAY";
		cout<<"\n9. EXIT";
		cout<<"\n------------------------------------";

		cout<<"\nEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
					sn.addUser();
					break;
			case 2:
					if(dummy->downlink == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->downlink);
						sn.DFS(dummy->downlink);
					}
					break;
			case 3:

					if(dummy->downlink == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.addFriend(dummy->downlink);
					}
					break;
			case 4:

					if(dummy->downlink == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->downlink);
						sn.dispFriends(dummy->downlink);

					}

					break;
			case 5:
//
//					if()
//						cout<<"\nNo User Is Added.";
//					else
//					{
//					}
//

					break;
			case 6:

//					if()
//						cout<<"\nNo User Is Added.";
//					else
//					{
//					}
					break;
			case 7:

//					if()
//						cout<<"\nNo User Is Added.";
//					else
//					{
//					}
//
						break;
			case 8:
//					if()
//						cout<<"\nNo User Is Added.";
//					else
//					{
//					}
//
						break;
			case 9:
						return 0;

			default:
					cout<<"\n\nPlease Enter Valid Choice";

		}

	}while(choice != 9);
return 0;
}
