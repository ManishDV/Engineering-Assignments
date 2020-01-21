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

int checkDesc(int *arr,int n){
	int k=0;
	cout<<"\nIN DESC\n";
	for(int i=0;i<n;i++){
		if(arr[i] > arr[i+1]){
			k++;
		}
	}

	if(k==n){
		MAX = arr[0];
		MIN = arr[n-1];
		
		return 1;
	}
	return 0;
}

int isAlreadySorted(int *arr,int n){
	int k=0;
	for(int i=0;i<n;i++){
		if(arr[i] < arr[i+1]){
			k++;
		}else{
			if(i==0){
				int z = checkDesc(arr,n);
				return z;
			}
		}
	}
	if(k==n-1){
		MAX = arr[n-1];
		MIN = arr[0];
		return 1;
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	int *arr;
	int n;
	cout<<"\nEnter The Number Of Elements In Array: ";
	cin>>n;
	arr = new int[n];
	
	inputArray(arr,n);

	int sorted = isAlreadySorted(arr,n);
	
	if(!sorted)
		minmax(arr,0,n-1);
	else
		cout<<"\nArray Is Already Sorted\n";

	cout<<"\n\n====================================\n";
	cout<<"\nMAXIMUM NUMBER IN ARRAY: "<<MAX<<"\n";
	cout<<"\nMINIMUM NUMBER IN ARRAY: "<<MIN<<"\n";
	cout<<"\n\n====================================\n";
	
	
	return 0;
}