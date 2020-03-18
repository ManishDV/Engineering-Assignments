#include <iostream>
#include <climits>
using namespace std;

struct Edge
{
	int s=0;
	int d=0;
	int weight=0;

}edges[20];
int k = 0;

	
void accept(int *graphMat,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j){
				*(graphMat+i*n+j) = 0;
				continue;
			}else{
				
					cout<<"\nEnter Weight For Edge ["<<i+1<<"] --> ["<<j+1<<"] : ";
					edges[k].s = i;
					edges[k].d = j;
					cin>>*(graphMat+i*n+j);

					if(*(graphMat+i*n+j) != 0){
						edges[k].weight = *(graphMat+i*n+j);
						k++;	
					}
				
			}
		}
	}
}



// void display(int *graphMat,int n){

// 	cout<<"\nAdjacency Matrix For Graph: \n\n";
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<n;j++){
// 			cout<<*(graphMat+i*n+j)<<"\t";
// 		}
// 		cout<<"\n";
// 	}
// }
void bellmon(int *graphMat,int n,int src){

// cout<<"\nNumber Of Edges In The Graph: "<<k;
// for (int i = 0; i < k; ++i)
// {
// 	cout<<"\t"<<edges[i].s<<" --> "<<edges[i].d<<" = "<<edges[i].weight<<"\n";
// }
	int u=0,v=0;
	int weight = 0;
	int dist[n];
	for(int i=0;i<n;i++){
		if(i==src){
			dist[i] = 0;
		}else{
			dist[i] = INT_MAX;
		}
	}	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<k;j++){
			u = edges[j].s;
			v = edges[j].d;
			weight = edges[j].weight;
			if(dist[u] != INT_MAX && (dist[u] + weight) < dist[v]){
				dist[v] = dist[u] + weight;
			}
		}
	}

	// Negative Cycle Checking
	int flag = 0;
	for(int j=0;j<k;j++){
			u = edges[j].s;
			v = edges[j].d;
			if(dist[v] > (dist[u] + edges[j].weight)){
				dist[v] = dist[u] + edges[j].weight;
				flag = 1;
		}
	}

	if(flag == 1){
		cout<<"\nCannot Find Path Because Graph Contains Negative Cycle\n";
	}else{
		cout<<"\nShortest Path From Single Source To Every Other Vertex Is \n";

		for(int i=0;i<n;i++){
			cout<<"\t"<<i+1<<" ---> "<<"["<<dist[i]<<"]\n";
		}
	}
}


int main(int argc, char const *argv[])
{
	int *graphMat;
	int n = 0;

	cout<<"\nEnter The Number Of Nodes In Graph: ";
	cin>>n;

	graphMat = new int[n*n];
	accept(graphMat,n);
	// display(graphMat,n);
	bellmon(graphMat,n,0);
	return 0;
}