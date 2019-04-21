//============================================================================
// Name        : Assign7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

struct vertex{
	char name;
	int id;
	bool visited;
	struct vertex *next;
	struct edge *edgeLink;
};

struct edge{
	int weight;
	bool visited;
	struct vertex *vnode;
	struct edge *next;
};

struct edgelist
{
	int u;
	int v;
	int weight;
};

class Test_Kruskal{
	struct vertex *start;
	int *a;
	int size = 0;
public:
	Test_Kruskal(){
		start = new struct vertex;
		start->next = NULL;
		a = new int;
		size = 0;
	}

	int nodeCount(){
		int s = 0;
		struct vertex *ver = start->next;
		while(ver != NULL)
		{
			s++;
			ver = ver->next;
		}
		return s;

	}
	void addNode(){
		int n = 0;
		cout<<"\nHow Many Nodes You Want To Add: ";
		cin>>n;
		for(int i = 0;i<n;i++){

			struct vertex *temp = new struct vertex;
			cout<<"\n----------- ENTER DATA FOR NODE "<<i+1<<"------------- \n";
			cout<<"\nEnter Value Of Node: ";
			cin>>temp->name;
			temp->id = i;
			temp->next = NULL;
			temp->edgeLink = NULL;
			if(start->next == NULL){
				start->next = temp;
			}else{
				struct vertex *temp2 = start->next;
				while(temp2->next != NULL){
					temp2 = temp2->next;
				}

				temp2->next = temp;
			}
		}
		cout<<"\n--------------------------------------------";
		cout<<"\nNodes Added Successfully";
	}

	struct vertex* getStart(){
		return start;
	}


	char findVertexById(int id){
		struct vertex *ver = start->next;
		while(ver != NULL){
			if(ver->id == id)
				return ver->name;
			ver = ver->next;
		}
	}
	void setInit(int n){
		a = new int[n+1];
		for(int i = 0;i <= n;i++)
			a[i] = i;
	}

	void connect(struct vertex *first,struct vertex *second,int weight)
		{
			struct edge *edge = first->edgeLink;
			struct edge *temp = new struct edge;
			temp->next = NULL;
			temp->weight = weight;
			temp->vnode = second;
			if(edge == NULL){
				first->edgeLink = temp;

			}else{
				while(edge->next != NULL)
					edge = edge->next;

				edge->next = temp;
			}
		}
		void addEdge(struct vertex *start){
			bool hasCon = false,Spresent = false,Dpresent = false;
			struct vertex *Sind = NULL,*Dind = NULL;

			char name1;
			char name2;

			cout<<"\nEnter Value Of Source Node: ";
			cin>>name1;
			cout<<"\nEnter Value Of Destination Node: ";
			cin>>name2;
			struct vertex *temp = start;
			while(temp != NULL){
				if(temp->name==name1)
				{
					Spresent = true;
					Sind = temp;
				}
				if(temp->name==name2)
				{
					Dpresent = true;
					Dind = temp;
				}

				temp = temp->next;
			}

			if(Spresent == true && Dpresent == true)
			{
				struct edge *edge = Sind->edgeLink;
				while(edge != NULL)
				{
					if(edge->vnode->name==name2)
						hasCon = true;
					edge = edge->next;
				}

			}else{
				cout<<"\nEither "<<name1<<" Or "<<name2<<" Is Not Present In GRAPH";
				return;
			}
			if(!hasCon){
				int weight = 0;
				cout<<"\nEnter The Weight Of Edge "<<name1<<"-"<<name2<<" :";
				cin>>weight;

				connect(Sind,Dind,weight);
				connect(Dind,Sind,weight);
				cout<<"\nEdge Added";
			}else{
				cout<<"\nEdge Already Exists";
			}
		}

		void adjacency(){
			struct vertex *temp = start->next;
			struct edge *temp1 = temp->edgeLink;
			while(temp != NULL){
				temp1 = temp->edgeLink;
				cout<<"\nNode "<<temp->name;
				if(temp->edgeLink != NULL)
					cout<<" -->";
				while(temp1 != NULL){
					cout<<" [Node: "<<temp1->vnode->name<<"]";
					if(temp1->next != NULL)
						cout<<" -->";
					temp1 = temp1->next;
				}
				temp = temp->next;
			}
		}
		bool isConnected(int x,int y){
			return find(x) == find(y);
		}

		int find(int x)
		{
			return a[x];
		}

		void Union(int x,int y){
 			int p = find(x);
			int q = find(y);

			for(int i = 0;i<nodeCount()-1;i++){
				if(a[i] == p)
					a[i] = q;
			}
		}

		void sort(struct edgelist ke[30],int n){
			struct edgelist e;
			for(int i= 0;i<n-1;i++){
				for(int j =0 ;j<n-i-1;j++){
					if(ke[j].weight > ke[j+1].weight)
					{
						e = ke[j];
						ke[j] = ke[j+1];
						ke[j+1] = e;
					}
				}
			}
		}

		void kruskal(){
			struct vertex *ver = start->next;
			struct edge *temp = ver->edgeLink;

			struct edgelist ke[30];
			int j = 0;

			while(ver != NULL){
				temp = ver->edgeLink;
				while(temp != NULL){

					ke[j].u = ver->id;
					ke[j].v = temp->vnode->id;
					ke[j].weight = temp->weight;
					j++;
					temp = temp->next;
				}
				ver = ver->next;
			}

//			for(int i = 0;i < j; i++)
//			{
//				cout<<"\nEDGE("<<findVertexById(ke[i].u)<<"-"<<findVertexById(ke[i].v)<<")  Weight = "<<ke[i].weight;
//			}
//
			sort(ke,j);
//			cout<<"\nSorted Edges: ";
//			for(int i = 0;i<j;i++){
//				cout<<"\nEDGE("<<findVertexById(ke[i].u)<<"-"<<findVertexById(ke[i].v)<<")  Weight = "<<ke[i].weight;
//
//			}
			int edges = 0;
			int cost = 0;
			int i = 0;

			setInit(j);
			while(edges != nodeCount()-1){
				if(!isConnected(ke[i].u,ke[i].v)){

					cout<<"\nEdge ("<<findVertexById(ke[i].u)<<"-"<<findVertexById(ke[i].v)<<") Weight: "<<ke[i].weight<<" Is Added In MST";
					cost += ke[i].weight;
					edges++;
					Union(ke[i].u,ke[i].v);
				}
				i++;
			}
			cout<<"\n\nMinimum Cost Of Spanning Tree: "<<cost;

		}
};

int main() {

	int choice = 0;
	class Test_Kruskal tk;
	do {
		cout<<"\n\n----------- MENU -------------";
		cout<<"\n1.ADD NODES";
		cout<<"\n2.ADD EDGES";
		cout<<"\n3.SHOW ADJACENCY LIST";
		cout<<"\n4.MST USING KRUSKAL'S ALGORITHM";
		cout<<"\n5.EXIT";
		cout<<"\n--------------------------------";
		cout<<"\nEnter Your Choice: ";
		cin>>choice;


		switch(choice){
		case 1:
			tk.addNode();
			break;
		case 2:
			tk.addEdge(tk.getStart()->next);
			break;
		case 3:
			tk.adjacency();
			break;
		case 4:
			tk.kruskal();
			break;
		case 5:
			return 0;
		default:
			cout<<"\nPlease Enter Valid Choice";
		}
	} while (choice != 5);


	return 0;
}
