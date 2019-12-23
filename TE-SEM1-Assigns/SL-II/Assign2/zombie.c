#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void bubble_sort(int num[10],int n){

	int i=0,j=0;
	int temp;
	
	for(i=0;i<n-1;i++){
		
		for(j=0;j<n-i-1;j++){
		
			if(num[j] > num[j+1])
			{
				temp = num[j];
				num[j] = num[j+1] ;
				num[j+1] = temp;
				
			}
		}
	}
	
	printf("\nSorted Array : \n");
	for(i=0;i<n;i++){
		
		printf("%3d\t",num[i]);	
	}		
	
}

void insertion_sort(int num[10], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = num[i]; 
        j = i - 1; 
        while (j >= 0 && num[j] > key) { 
            num[j + 1] = num[j]; 
            j = j - 1; 
        } 
        num[j + 1] = key; 
    } 
    
    
	printf("\nSorted Array : \n");
	for(i=0;i<n;i++){
		
		printf("%3d\t",num[i]);	
	}		
	
}
 
int main(int argc,char *argv[]){
	//Calling Fork To Create Process	
	
	int num[10];
	int n = 0;	
	int i = 0;	
	printf("\nEnter The Number Of Elements: ");
	scanf("%d",&n);
	printf("\n");
	for(i = 0;i< n;i++){
		printf("Enter Number %d: ",(i+1));
		scanf("%d",&num[i]);
	}	
	int pid = fork();
	
	//Checking if pid =0 then it is chile process
	if(pid == 0){
			printf("\nSorting Using Child Process\n");
			bubble_sort(num,n);		
	}else{
			printf("\nParent Is Running...............\n");
			sleep(5);
			printf("\nSorting Using Parent Process\n");
			insertion_sort(num,n);
			printf("\n");							
			wait(NULL); //Adding Sleep in parent Process execution
	}



}
