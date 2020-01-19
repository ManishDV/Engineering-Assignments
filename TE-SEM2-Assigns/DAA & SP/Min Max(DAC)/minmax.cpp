#include <iostream>
using namespace std;

int MIN = 999999;
int MAX = 0;

void inputArray(int *arr,int n){
	cout<<"\n\n===========================================\n";
	cout<<"\n\tPlease Enter The Array Elements: \n";
	cout<<"\n===========================================\n";

	for (int i = 0; i < n; ++i)
	{
		cout<<"\narr["<<i<<"]: ";
		cin>>arr[i];
	}
}

void minmax(int *arr,int start,int end){

	if(end == start){
		// cout<<"\n\n=================\n";
		// cout<<"\nEND: "<<end<<"\nSTART: "<<start<<"\n";
		// cout<<"\n\n=================\n";
		
		if(MAX < arr[end]){
			MAX = arr[end];
		}
		if(MIN > arr[end]){
			MIN = arr[end];
		}
		return;
	}else if(((end-start)+1) == 2){
		
		// cout<<"\n\n=================\n";
		// cout<<"\nEND: "<<end<<"\nSTART: "<<start<<"\n";
		// cout<<"\n\n=================\n";
		
		if(MAX < arr[end]){
			MAX = arr[end];
			// MIN = arr[start];
		}
		if(MAX < arr[start]){
			MAX = arr[start];
		}

		if(MIN > arr[start]){
			MIN = arr[start];
		}

		if(MIN > arr[end]){
			MIN = arr[end];
		}
		return;
	}else{
		int mid = (start+end)/2;
		minmax(arr,start,mid-1);
		minmax(arr,mid,end);	
	}
	
	
}

int main(int argc, char const *argv[])
{
	int *arr;
	int n;
	cout<<"\nEnter The Number Of Elements In Array: ";
	cin>>n;
	arr = new int[n];
	
	inputArray(arr,n);

	minmax(arr,0,n-1);

	cout<<"\n\n====================================\n";
	cout<<"\nMAXIMUM NUMBER IN ARRAY: "<<MAX<<"\n";
	cout<<"\nMINIMUM NUMBER IN ARRAY: "<<MIN<<"\n";
	cout<<"\n\n====================================\n";
	
	
	return 0;
}