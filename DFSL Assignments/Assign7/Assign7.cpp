//============================================================================
// Name        : Assign7.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//Represent any real world graph using adjacency list /adjacency matrix find minimum spanning
//tree using Kruskal’s algorithm.
//============================================================================

#include <iostream>
#include <string.h>

#include<bits/stdc++.h>
using namespace std;

struct graphEdge{
	int weight;
	struct graphVertex *vertex;
	struct graphEdge *edge;
};

struct graphVertex
{
	int nodeVal;
	int edgecount;
	bool visited;
	struct graphVertex *downlink;
	struct graphEdge *edgeLink;
};

struct start{
	int count;
	struct graphVertex *first;
};

struct edgelist
{
	int u;
	int v;
	int weight;
};


class Test_Kruskal{
	struct start *first1;
	int *a;
	int size;
public:
	Test_Kruskal()
	{
		first1 = new struct start;
		first1->count = 0;
		first1->first = NULL;
	}


	void set(int n)
	{
		a = new int(n+1);
		size = n;
		for(int i = 0;i <= n;i++)
			a[i] = i;
	}

	  void setStart(struct start *first)
	  {
		   first1 = first;
	  }


	  struct start * getStart()
	  {
		   return first1;
	  }

	  struct start *insertNode(struct start *first2)
	  {
		if(first2->first == NULL)
		{

			  struct graphVertex *temp = new struct graphVertex;
			  cout<<"\nEnter Node Value: ";
			  cin>>temp->nodeVal;
			  first2->first = temp;
			  first2->count++;
			  temp->downlink = NULL;
			  temp->edgeLink = NULL;
			  temp->edgecount = 0;

//			  return first2;
		}
		else{
			struct graphVertex *temp = new struct graphVertex;
			cout<<"\n\nEnter Node Value: ";
			cin>>temp->nodeVal;
			struct graphVertex *temp1 = first2->first;
			while(temp1->downlink != NULL)
			{
				temp1 = temp1->downlink;
			}
			temp1->downlink = temp;
			temp->edgeLink = NULL;
			temp->edgecount = 0;
			first2->count++;
		}
			cout<<"NODE Is Added.";
		  	  return first2;
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

	  		   cout<<first->nodeVal<<"  ";

	  		   struct graphEdge *g = first->edgeLink;

	  		   while(g!=NULL)
	  		   {
	  			   if(g->vertex->visited != true)
	  			   {
	  				   DFS(g->vertex);
	  			   }
	  				   g = 	g->edge;
	  			}

	  			   if(g == NULL)
	  			   {
	  				   if(first->downlink != NULL && first->downlink->visited != true)
	  					   	   DFS(first->downlink);
	  				   else
	  				   {
//	  					   if(first->downlink == NULL && first->downlink->visited != true)
//	  						   cout<<" NULL ";
	  				   }
	  			   }
	  	  }

	  void addEdge(struct graphVertex *first)
	  	 {
	  		 int name;
	  		 int name1;

	  		 struct graphVertex *temp = first;
	  		 struct graphVertex *firstIndicator = NULL;
	  		 struct graphVertex *friendIndicator = NULL;

	  		 bool userExists = false;
	  		 bool friendExists = false;
	  		 bool hasConnection = false;
	  		 cout<<"\nEnter Starting Node: ";
	  		 cin>>name;

	  		 cout<<"\nEnter Destination Node: ";
	  		 cin>>name1;



	  		 while(temp != NULL)
	  		 {
	  			 if(name == temp->nodeVal)
	  			 {
	  				 userExists = true;
	  				 firstIndicator = temp;
	  			 }
	  			 if(name1 == temp->nodeVal)
	  			 {
	  				 friendExists = true;
	  				 friendIndicator = temp;
	  			 }
	  			 temp = temp->downlink;
	  		 }

	  		 struct graphEdge *tempEdge = firstIndicator->edgeLink;

	  		 while(tempEdge != NULL)
	  		 {
	  			 if(tempEdge->vertex->nodeVal == name1)
	  			 {
	  				 hasConnection = true;
	  			 }
	  			 tempEdge = tempEdge->edge;
	  		 }

	  		 if(hasConnection)
	  		 {
	  			 cout<<"\n Edge Already Exists";
	  			 return;
	  		 }

	  		 if(userExists == true && friendExists == true)
	  		 {
	  			 hasConnection = false;
	  			 int weight = 0;
	  			 cout<<"\nEnter The Weight Of The Edge: ";
	  			 cin>>weight;
	  			 struct graphEdge *g = new struct graphEdge;
	  			 struct graphEdge *t = new struct graphEdge;
	  			 g->edge = NULL;
	  			 g->weight = weight;

	  			 t->weight = weight;
	  			 t->edge = NULL;
	  			 if(firstIndicator->edgeLink == NULL)
	  			 {
	  				 g->edge = NULL;
	  				 g->vertex = friendIndicator;
	  				 firstIndicator->edgeLink = g;
	  				 firstIndicator->edgecount++;
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
	  				 firstIndicator->edgecount++;
	  			 }
	  			 if(friendIndicator->edgeLink == NULL)
	  			 {
	  				 t->edge = NULL;
	  				 t->vertex = firstIndicator;
	  				 friendIndicator->edgeLink = t;
	  				 friendIndicator->edgecount++;
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
	  				 friendIndicator->edgecount++;
	  			 }

	  			 cout<<"\nEdge Is Added.";
	  		 }
	  		 else
	  		 {
	  			 cout<<"\nEither "<<name<<" or "<<name1<<" Does Not Exists In GRAPH";
	  		 }
	  	 }

//	  	 void kruskalMST(struct graphVertex *first)
//	  	 {
//	  		 struct graphVertex *temp = first;
//	  		 struct graphVertex *startVertex[20];
//	  		 struct graphVertex *destVertex[20];
//	  		 int weights[20];
//	  		 struct graphEdge *one;
//
//  			 int i = 0;
//
//  			 while(temp != NULL)
//	  		 {
//	  			one = temp->edgeLink;
//	  			while(one != NULL)
//	  			{
//	  				startVertex[i] = temp;
//	  				destVertex[i] = one->vertex;
//	  				weights[i] = one->weight;
//	  				i++;
//	  				one = one->edge;
//	  			}
//	  			temp = temp->downlink;
//	  		 }
//
//  			 int temp1 = 0;
//  			 struct graphVertex *two;
//  			 struct graphVertex *three;
//
//  			 for(int j = 0;j < i - 1; j++)
//  			 {
//  				 for(int k = 0;k < i - j -1;k++)
//  				 {
//  					 if(weights[k] > weights[k+1])
//  					 {
//  						 temp1 = weights[k];
//  						 weights[k] = weights[k+1];
//  						 weights[k+1] = temp1;
//
//  						 two = startVertex[k];
//  						 startVertex[k] = startVertex[k+1];
//  						 startVertex[k+1] = two;
//
//  						three = destVertex[k];
//  						destVertex[k] = destVertex[k+1];
//  						destVertex[k+1] = three;
//  					 }
//  				 }
//  			 }
//
//  			 struct graphVertex *finalstartMST[20];
//  			 struct graphVertex *finaldestMST[20];
//  			 int finalWeights[20];
//  			 int k = 0;
//  			 int w = weights[0];
//  			 finalstartMST[0] = startVertex[0];
//  			 finaldestMST[0] = destVertex[0];
//  			 finalWeights[0] = weights[0];
//  			 k = 1;
//  			 for(int j=2;j<i;j++)
//  			 {
//  				 startVertex[j]->visited = true;
//  				 destVertex[j]->visited = false;
//  				 if(startVertex[j+1]->visited != true)
//  				 {
//  					finalstartMST[k] = startVertex[j];
//  					finaldestMST[k] = destVertex[j];
//  					finalWeights[k] = weights[j];
//  					w += weights[j];
//  					k++;
//  					j++;
//  				 }
//  			 }
//
//  			 cout<<"\n\nMST CONTAINS FOLLOWING EDGES AND HAS MINIMUM COST: "<<w;
//  			 for(int j = 0;j<k;j++)
//  			 {
//  				cout<<"\n\n"<<finalstartMST[j]->nodeVal<<" --> "<<finaldestMST[j]->nodeVal<<" with cost "<<finalWeights[j];
//  			 }
//	  	 }

	  static bool edgelistcomparator(struct edgelist e1,struct edgelist e2)
	  {
	  	return (e1.weight<e2.weight);
	  }

	  int find(char x)
	  {
	  	return a[int(x)];
	  }

	  bool isConnected(int x,int y)
	  {
	  	return find(x) == find(y);
	  }

	  void Union(int x,int y)
	  {
	  	int p = find(x);
	  	int q = find(y);

	  	for(int i = 0;i <= size; i++)
	  		if(a[i] == p)
	  			a[i] = q;
	  }

	  void kruskalMST(struct graphVertex *network,int nodes)
	  {
	  	if(network == NULL)
	  		cout<<"\nNetwork Is Empty";
	  	else
	  	{
	  			set(nodes);
	  			int size = 0;
	  		  	int edges = 0;
	  		  	int network_cost = 0;
	  		  	struct graphVertex *cur = network;
	  		  	while(cur != NULL)
	  		  	{
	  		  		size += cur->edgecount;
	  		  		cur = cur->downlink;
	  		  	}
	  		  	struct edgelist el[size];
	  		  	graphEdge *e;
	  		  	cur = network;
	  		  	int i=0;
	  		  	while(cur != NULL)
	  		  	{
	  		  		e = cur->edgeLink;
	  		  		while(e != NULL)
	  		  		{
	  		  			el[i].u = cur->nodeVal;
	  		  			el[i].v = e->vertex->nodeVal;
	  		  			el[i++].weight = e->weight;
	  		  			e=e->edge;
	  		  		}
	  		  		cur = cur->downlink;
	  		  	}
	  		  	sort(el,el+size,edgelistcomparator);
	  		  	i = 0;
	  		  	cout<<endl;
	  		  	while(edges != nodes - 1)
	  		  	{
	  		  		edgelist temp = el[i];
	  		  		if(!isConnected(temp.u,temp.v))
	  		  		{
	  		  			cout<<"Edge Added "<<temp.u<<"-"<<temp.v<<"\nWeight = "<<temp.weight<<"\n\n";
	  		  			network_cost += temp.weight;
	  		  			edges ++;
	  		  			Union(temp.u,temp.v);
	  		  		}
	  		  		i++;
	  		  	}

	  		  	cout<<"\nThe Cost Of Minimum Spanning Tree: "<<network_cost;
	  		  	//return network_cost;

	  	}
	  }

};
int main() {

	int choice = 0 ;
	Test_Kruskal sn;
	int n = 0;

	struct start *dummy = NULL;

	do{

		cout<<"\n\n-------------- MENU ----------------";
		cout<<"\n1. ADD NODE";
		cout<<"\n2. DISPLAY GRAPH";
		cout<<"\n3. ADD EDGES";
		cout<<"\n4. Find MST Using Kruskal's Algorithm";
		cout<<"\n5. EXIT";
		cout<<"\n------------------------------------";

		cout<<"\n\nEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\n\nHow Many Nodes You Want To Insert: ";
				cin>>n;
				for(int i = 0; i < n;i++)
				{
					dummy = sn.insertNode(sn.getStart());
					sn.setStart(dummy);
				}
				break;
			case 2:
				dummy = sn.getStart();

				if(dummy->first == NULL)
					cout<<"\nNo User Is Added.";
				else
				{
					sn.makeFalse(dummy->first);
					cout<<"\n";
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
					 sn.addEdge(dummy->first);
				 }
				 break;

			 case 4:
				 dummy = sn.getStart();

				 if(dummy->first == NULL)
					 cout<<"\nNo User Is Added.";
				 else
				 {
					 sn.makeFalse(dummy->first);
					 sn.kruskalMST(dummy->first,dummy->count);
				 }
				 break;

		}
	}while(choice != 5);
	return 0;
}
