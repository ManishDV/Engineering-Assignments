//============================================================================
// Name        : Prims.cpp
// Author      : Tanvi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

struct GRAPH
{
    int count;
    struct VERTEX *first;
};

struct VERTEX
{
    struct VERTEX *nextvertex;
    char name[40];
    bool intree;
    struct ARC *ptrarc;
};

 struct ARC
{
    struct VERTEX *destination;
    int weight;
    struct ARC *nextArc;
    bool intree;
};

class A
{
  GRAPH *graph;
   public :
       A()
       {
           graph= new GRAPH;
           graph->first=NULL;
           graph->count=0;
       }
      void insertvertex();
      int insertedge(char [], char [],int);
      VERTEX* data(VERTEX *);
      void display();
      void prims();
};

VERTEX* A::data(VERTEX *t1)
{
	cout<<"\nVERTEX :  ";
	cout<<"\nEnter name of vertex  : ";
	cin>>t1->name;
	t1->intree=false;
	t1->nextvertex=NULL;
	t1->ptrarc=NULL;
	return t1;
}
void A::insertvertex()
{
    VERTEX *newptr;
    VERTEX *temp;
    newptr= new VERTEX;
    newptr=data(newptr);
    temp=graph->first;
    if(temp==NULL)
    {
        graph->first=newptr;
    }
    else
    {
        while(temp->nextvertex!=NULL)
        {
            temp=temp->nextvertex;
        }
        temp->nextvertex=newptr;
    }
}

int A::insertedge(char source[30],char desti[30],int weight)
{
  VERTEX *from,*to;
  ARC *newptr, *temp, *walk;
  newptr= new ARC;

  from=graph->first;
  while(from!=NULL && strcmp(from->name,source)!=0)
  {
      from=from->nextvertex;
  }
  if(from==NULL)
    return -1;

  to=graph->first;
  while(to!=NULL && strcmp(to->name,desti)!=0)
  {
      to=to->nextvertex;
  }
  if(to==NULL)
    return -2;

  newptr->destination=to;
  if(from->ptrarc==NULL)
  {
      from->ptrarc=newptr;
      newptr->weight=weight;
      newptr->nextArc=NULL;
      return 1;
  }
  temp=from->ptrarc;
  while(temp->nextArc!=NULL && strcmp(temp->destination->name,desti)!=0 )
  {
      temp=temp->nextArc;
  }
  if(strcmp(temp->destination->name,desti)==0)
  {
      return 2;
  }
  temp->nextArc=newptr;
  newptr->weight=weight;
  newptr->nextArc=NULL;
  return 1;
}
void A::prims()
{
    VERTEX *temp;
    ARC *walk,*minloc;
    int minedge,sum=0;
    bool treecomp=false;
    temp=graph->first;
    if(temp==NULL)
        return;
    while(temp!=NULL)
    {
        temp->intree=false;
        walk=temp->ptrarc;
        while(walk!=NULL)
        {
            walk->intree=false;
            walk=walk->nextArc;
        }
        temp=temp->nextvertex;
    }

    temp=graph->first;
    temp->intree=true;

    treecomp=false;
    while(!treecomp)
    {
    	 temp=graph->first;
        treecomp=true;
        minedge=999;

        minloc=NULL;
        while(temp!=NULL)
        {
            if(temp->intree==true)
            {
                walk=temp->ptrarc;
                while(walk!=NULL)
                {
                    if(walk->destination->intree==false)
                    {
                        treecomp=false;
                        if(walk->weight < minedge )
                        {
                            minedge=walk->weight;
                           //
                            minloc=walk;
                        }
                    }
                    walk=walk->nextArc;
                }
            }
            temp=temp->nextvertex;
        }

        if(minloc!=NULL)
        {
            minloc->intree=true;
            minloc->destination->intree=true;
            sum=sum+minedge;
            cout<<" "<<minedge;
        }
    }

   cout<<endl<<sum;
}
void A::display()
{
	cout<<"\nADJACENECY LIST \n";
	VERTEX *temp;
	ARC *te;
	temp=graph->first;
	while(temp!=NULL)
	{
		cout<<"\n[ "<<temp->name<<" ]";
		te=temp->ptrarc;
		while(te!=NULL)
		{
			cout<<" -> ["<<te->destination->name<<" , "<<te->weight<<" ] ";
			te=te->nextArc;
		}
		temp=temp->nextvertex;
	}
}

int main()
{
    A f;
    char s[10],d[10];
	int choice,p,q;
	do
	{
		cout<<"\n----------------------MENU---------------------------"<<endl;
		cout<<"1.Insert Vertices "<<endl;
		cout<<"2.Insert Edges "<<endl;
		cout<<"3.Display Adjecencey list "<<endl;
		cout<<"4.Prims to find minimum spanning tree"<<endl;
		cout<<"5.EXIT"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"CHOICE : ";
		cin>>choice;
		switch(choice)
		{
		   case 1: int n;
		          cout<<"\nEnter number of vertices you want to enter\n";
		          cin>>n;
		          for(int i=0;i<n;i++)
		          f.insertvertex();
			      break;

		   case 2:
        	       cout<<"Enter name of START vertex  : ";
		           cin>>s;
		           cout<<"Enter name of END vertex  : ";
		           cin>>d;
		           cout<<"Enter Weight between START And END  vertex : ";
		           cin>>q;
                   p=f.insertedge(s,d,q);
		           if(p==-1)
                    cout<<"\nSOURCE NOT FOUND";
                   else if(p==-2)
                     cout<<"\nDESTINATION NOT FOUND\n";
                   else if(p==1)
                     cout<<"\nEDGE IS ADDED SUCCESFULLY\n";

                   else if(p==2)
                     cout<<"\nAREADY ADDED\n";
                      p=f.insertedge(d,s,q);
                   break;

		   case 3: f.display();
			       break;

		   case 4:f.prims();
			       break;

		   case 5: return 0;
			       break;
        default : cout<<"\n!!....Please Enter The Valid Choice....!!";

		}
	}while(1);
	return 0;
}
