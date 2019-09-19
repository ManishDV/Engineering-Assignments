#include<iostream>
#include<climits>     /*Used for INT_MAX*/
using namespace std;

int minimumDist(int dist[], bool Dset[],int size)   /*A method to find the vertex with minimum distance which is not yet included in Dset*/
{
	int min=INT_MAX,index;                 /*initialize min with the maximum possible value as infinity does not exist */
	for(int v=0;v<size;v++)
	{
		if(Dset[v]==false && dist[v]<=min)
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
void dijkstra(int graph[30][30],int src,int size) /*Method to implement shortest path algorithm*/
{
	int dist[size];
	bool Dset[size];
	for(int i=0;i<size;i++)                    /*Initialize distance of all the vertex to INFINITY and Dset as false*/
	{
		dist[i]=INT_MAX;
		Dset[i]=false;
	}
	dist[src]=0;                                   /*Initialize the distance of the source vertec to zero*/
	for(int c=0;c<size;c++)
	{
		int u=minimumDist(dist,Dset,size);              /*u is any vertex that is not yet included in Dset and has minimum distance*/
		Dset[u]=true;                              /*If the vertex with minimum distance found include it to Dset*/
		for(int v=0;v<size;v++)
		/*Update dist[v] if not in Dset and their is a path from src to v through u that has distance minimum than current value of dist[v]*/
		{
			if(!Dset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
		}
	}
	cout<<"Vertex\t\tDistance from source"<<endl;
	for(int i=0;i<size;i++)                       /*will print the vertex with their distance from the source to the console */
	{
		char c=65+i;
		cout<<c<<"\t\t"<<dist[i]<<endl;
	}
}
int main()
{
	int Vertex = 0;
	cout<<"\n\nEnter The Number Of Vertex: ";
	cin>>Vertex;
	int graph[Vertex][Vertex];
	cout<<"\n\nEnter Adjacency Matrix: ";
	for(int i = 0;i < Vertex; i++)
	{
		for(int j = 0; j < Vertex ; j++)
		{
			cin>>graph[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
	dijkstra(graph,0,Vertex);
	return 0;
}
