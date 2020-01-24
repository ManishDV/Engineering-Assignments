#include <iostream>
#include <stdio.h>
using namespace std;
struct programs
{
	int program_no;
	int length;
}program[20],tape[20];


int tapeIdx = 0;

void inputArray(int n){
	cout<<"\n\n===========================================\n";
	cout<<"\n\tPlease Enter The Array Elements: \n";
	cout<<"\n===========================================\n";
	for (int i = 0; i < n; ++i)
	{
		program[i].program_no = i+1;
		cout<<"\nEnter The Lenght Of Program "<<i+1<<" : ";
		cin>>program[i].length;	
	}
}

int Merge(int p, int q,int r)     
{
    int n1,n2,i,j,k; 
    n1=q-p+1;
    n2=r-q;             
    struct programs L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=program[p+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=program[q+j+1];
    }
    i=0,j=0;
   for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i].length<R[j].length)
        {
            program[k]=L[i++];
        }
        else
        {
            program[k]=R[j++];
        }
    }
    while(i<n1)             
    {
        program[k++]=L[i++];
    }
    while(j<n2)
    {
        program[k++]=R[j++];
    }
}
int Sort(int p,int r)    
{
    int q;                                
    if(p<r)
    {
        q=(p+r)/2;
        Sort(p,q);
        Sort(q+1,r);
        Merge(p,q,r);
    }
}

void storeOnTape(int n){
	int tapeSize = 0;
	cout<<"\n================================";
	cout<<"\nEnter The Capacity Of Tape: ";
	cin>>tapeSize;
	cout<<"================================\n";

	int total = 0;

	for(int i =0;i<n;i++){
		if(tapeSize >= total){
			total += program[i].length;
			tape[tapeIdx] = program[i];
			tapeIdx++;
		}
	}
	total = 0;
	for(int i=0;i<tapeIdx;i++){
		
			int sum = 0;
		if(i==0){
			total = tape[i].length;
		}else{
			for(int j=0;j<=i;j++){
				sum+=tape[j].length;
			}
			
		}	
			total = sum+total;
	}

	float MRT = float(total) / float(tapeIdx);

	cout<<"\n===========================================\n";
	cout<<"\t\tTAPE CONTENT";
	cout<<"\n===========================================\n";

	for (int i = 0; i < tapeIdx; ++i)
	{
		cout<<"P"<<tape[i].program_no<<"\t";
	}	
	cout<<"\n===========================================\n";
	cout<<"\n===========================================\n";
	cout<<"\nTOTAL MRT IS: "<<MRT<<"ms";
	cout<<"\n===========================================\n";
	


}

int main(int argc, char const *argv[])
{	

	int n = 0;
	cout<<"\nPlease Enter The Size Of Array: ";
	cin>>n;

	inputArray(n);
	Sort(0,n-1);
	storeOnTape(n);
	return 0;
}