//============================================================================
// Name        : Assign6.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description :

//Create A GRAPH and store DOB ad number of comments
//1.Find Who Is Having Maximum Friends
//2.Find Who Has Post Maximum And Minimum Comments
//3.Find Users Having Birthday This Month
//Use Adjacency List Representation and Perform BFS and DFS
//============================================================================

#include <iostream>
#include <string.h>
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

struct start{
	int count;
	struct graphVertex *first;
};



class Social_Network{
	struct start *first1;

public:

	  Social_Network()
      {
		  first1 = new struct start;
		  first1->count = 0;
		  first1->first = NULL;
	  }

	  void setStart(struct start *first)
	  {
		   first1 = first;
	  }


	  struct start * getStart()
	  {
		   return first1;
	  }

	  struct start *insertUser(struct start *first2)
	  {
		if(first2->first == NULL)
		{

			  struct graphVertex *temp = new struct graphVertex;
		      getUserData(temp);
			  first2->first = temp;
			  first2->count++;
//			  return first2;
		}
		else{
			struct graphVertex *temp = new struct graphVertex;
			getUserData(temp);
			struct graphVertex *temp1 = first2->first;
			while(temp1->downlink != NULL)
			{
				temp1 = temp1->downlink;
			}
			temp1->downlink = temp;
			first2->count++;
		}
			cout<<"\nUser Is Added.";
		  	  return first2;
	  }
	  void getUserData(struct graphVertex *node){

		  cout<<"\n\nEnter The Name Of The User: ";
		  cin>>node->name;
		  cout<<"\nEnter The DOB of User(dd/mm/yyyy): ";
		  cin>>node->date>>node->month>>node->year;
		  node->Comments = 0;
		  node->visited = false;
		  node->downlink = NULL;
		  node->edgeLink = NULL;
		  node->friends = 0;
////		  return node;
		}

	  void makeFalse(struct graphVertex *first)
	  {
		  struct graphVertex *temp = first;
		  while(temp != NULL)
		  {
			  temp->visited = false;
			  temp = temp->downlink;
		  }
	  }
	  void DFS(struct graphVertex *first)
	  {
		   first->visited = true;
		   putdata(first);
		   struct graphEdge *g = first->edgeLink;

			   while(g!=NULL)
			   {
				   if(g->vertex->visited != true)
				   {
					   DFS(g->vertex);
				   }
				   g = g->edge;
			   }

			   if(g == NULL)
			   {
				   if(first->downlink != NULL && first->downlink->visited != true)
					   DFS(first->downlink);
			   }
	  }

	 void putdata(struct graphVertex *node)
	 {
		 cout<<"\nUser Name: "<<node->name;
		 cout<<"\nUser DOB: "<<node->date<<"/"<<node->month<<"/"<<node->year;
		 cout<<"\nCommented Till Now: "<<node->Comments<<" times";
		 cout<<"\nTotal Friends: "<<node->friends;

		 cout<<"\n----------------------------------------\n";
	 }

	 void addFriend(struct graphVertex *first)
	 {
		 char name[30];
		 char name1[30];

		 struct graphVertex *temp = first;
		 struct graphVertex *firstIndicator = NULL;
		 struct graphVertex *friendIndicator = NULL;

		 bool userExists = false;
		 bool friendExists = false;
		 bool hasConnection = false;
		 cout<<"\nEnter Name Of User Which Want To Make Friend: ";
		 cin>>name;

		 cout<<"\nEnter Name of User "<<name<<" Want To add As Friend: ";
		 cin>>name1;



		 while(temp != NULL)
		 {
			 if(strcmp(name,temp->name) == 0)
			 {
				 userExists = true;
				 firstIndicator = temp;
			 }
			 if(strcmp(name1,temp->name) == 0)
			 {
				 friendExists = true;
				 friendIndicator = temp;
			 }
			 temp = temp->downlink;
		 }

		 struct graphEdge *tempEdge = firstIndicator->edgeLink;

		 while(tempEdge != NULL)
		 {
			 if(strcmp(tempEdge->vertex->name,name1) == 0)
			 {
				 hasConnection = true;
			 }
			 tempEdge = tempEdge->edge;
		 }

		 if(hasConnection)
		 {
			 cout<<"\n"<<name1<<" Is Already a friend Of "<<name;
			 return;
		 }

		 if(userExists == true && friendExists == true)
		 {
			 hasConnection = false;
			 struct graphEdge *g = new struct graphEdge;
			 struct graphEdge *t = new struct graphEdge;
			 g->edge = NULL;
			 t->edge = NULL;
			 if(firstIndicator->edgeLink == NULL)
			 {
				 g->edge = NULL;
				 g->vertex = friendIndicator;
				 firstIndicator->edgeLink = g;
				 firstIndicator->friends++;
			 }
			 else{
				 struct graphEdge *temp1 = firstIndicator->edgeLink;

				 while(temp1->edge != NULL)
				 {
					 temp1 = temp1->edge;
				 }

				 temp1->edge = g;
				 g->vertex = friendIndicator;
				 g->edge = NULL;
				 firstIndicator->friends++;
			 }
			 if(friendIndicator->edgeLink == NULL)
			 {
				 t->edge = NULL;
				 t->vertex = firstIndicator;
				 friendIndicator->edgeLink = t;
				 friendIndicator->friends++;
			 }
			 else{
				 struct graphEdge *temp2 = friendIndicator->edgeLink;

				 while(temp2->edge != NULL)
				 {
					 temp2 = temp2->edge;
				 }

				 t->vertex = firstIndicator;
				 t->edge = NULL;
				 temp2->edge = t;
				 friendIndicator->friends++;
			 }
			 cout<<"\nFriend Is Added.";
		 }
		 else
		 {
			 cout<<"\nEither "<<name<<" or "<<name1<<" Does Not Exists";
		 }
	 }

	 void displayFriend(struct graphVertex *first)
	 {
		 char name[30];
		 cout<<"\nEnter The User Name Whose Friend's List You Want To See: ";
		 cin>>name;
		 bool userExists = false;
		 struct graphVertex *userIndicator;
		 struct graphVertex *temp = first;
		 while(temp != NULL)
		 {
			 if(strcmp(temp->name,name) == 0)
			 {
				 userExists = true;
				 userIndicator = temp;
			 }
			 temp = temp->downlink;
		 }
		 if(userExists)
		 {
			 struct graphEdge *edge1 = userIndicator->edgeLink;
			 //struct graphEdge *prev;
			 if(edge1 == NULL)
			 {
				 cout<<"\n"<<name<<" Has No Friends Yet";
			 }
			 else
			 {
				 while(edge1 != NULL)
				 {
					 putdata(edge1->vertex);
					 edge1 = edge1->edge;
				 }
			 }
		 }
		 else
		 {
			 cout<<"\n"<<name<<" Does Not Exists In The Network!!";
		 }
	 }

	 void addComment(struct graphVertex *first)
	 {
		 struct graphVertex *temp = first;
		 char name[30];
		 char comment[30];
		 cout<<"\nEnter The Name Of User Which Wants To Add Comments: ";
		 cin>>name;

		 while(temp != NULL)
		 {
			 if(strcmp(temp->name,name) == 0)
			 {
				 temp->Comments++;
				 cout<<"\nEnter Comment: ";
				 cin>>comment;
				 cout<<"\nComment Added Successfully";
				 return;
			 }
			 else
			 {
				 if(temp->downlink == NULL)
				 {
					 cout<<"\n" <<name<<" Does Not Exists In Network";
				 }
			 }

			 temp = temp->downlink;
		 }
	 }

	 void findMaxFriends(struct graphVertex *first)
	 {
		 struct graphVertex *temp = first;
		 struct graphVertex *maxFriendPointer = first;
		 int max = first->friends;
		 while(temp != NULL)
		 {
			 if(max < temp->friends)
			 {
				 max = temp->friends;
				 maxFriendPointer = temp;
			 }

			 temp = temp->downlink;
		 }

		 cout<<"\n ";
		 cout<<maxFriendPointer->name<<" Has Most Friend's In Network With Total "<<max<<" Friends";
	 }

	 void findMaxMinComment(struct graphVertex *first)
	 {
		 struct graphVertex *temp = first;
		 struct graphVertex *maxPointer = first;
		 struct graphVertex *minPointer = first;
		 int max = first->Comments;
		 int min = first->Comments;

		 while(temp != NULL)
		 {
			 if(max < temp->Comments)
			 {
				 max = temp->Comments;
				 maxPointer = temp;
			 }
			 if(min > temp->Comments)
			 {
				 min = temp->Comments;
				 minPointer = temp;
			 }
			 temp = temp->downlink;
		 }
		 cout<<"\n ";
		 cout<<maxPointer->name<<" Has Commented "<<max<<" Times Maximum Of Anyone Else In The Network";
		 cout<<"\n \n";
		 cout<<minPointer->name<<" Has Commented "<<min<<" Times Minimum Of Anyone Else In The Network";


	 }


	 void findBirthDate(struct graphVertex *first)
	 {
		 struct graphVertex *temp = first;
		 struct graphVertex *birthday[30];
		 int month;
		 cout<<"\nEnter The Month Number To Find The Users Having Birthday In That Month(1-12): ";
		 cin>>month;
		 int i = 0;
		 while(temp != NULL)
		 {
			 if(temp->month == month)
			 {
				 birthday[i] = temp;
				 i++;
			 }
			 temp = temp->downlink;
		 }

		 for(int j = 0; j < i;j++)
		 {
			 cout<<"\n\n"<<birthday[j]->name<<" Has Birthday on "<<birthday[j]->date<<"th of this month";
		 }
	 }

};
int main() {
	Social_Network sn;
	struct start *dummy = NULL;
	int choice = 0;
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
					dummy = sn.insertUser(sn.getStart());
					sn.setStart(dummy);
					break;
			case 2:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						cout<<"\n-------------- USERS IN NETWORK --------------";
						sn.DFS(dummy->first);
					}
					break;
			case 3:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						sn.addFriend(dummy->first);
					}
					break;
			case 4:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						sn.displayFriend(dummy->first);
					}

					break;
			case 5:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						sn.addComment(dummy->first);
					}


					break;
			case 6:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						sn.findMaxFriends(dummy->first);
					}
					break;
			case 7:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						sn.findMaxMinComment(dummy->first);
					}

						break;
			case 8:
					dummy = sn.getStart();

					if(dummy->first == NULL)
						cout<<"\nNo User Is Added.";
					else
					{
						sn.makeFalse(dummy->first);
						sn.findBirthDate(dummy->first);
					}

						break;
			case 9:
						return 0;

			default:
					cout<<"\n\nPlease Enter Valid Choice";

		}

	}while(choice != 9);
	return 0;
}
