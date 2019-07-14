#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*void bubble_sort(int num[10],int n){

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
}
*/
 
int main(int argc,char *argv[]){
	//Calling Fork To Create Process	
	
	int num[10];
	int n = 0;	
	int i = 0;
	char rst[10],*array[10];	
	printf("\nEnter The Number Of Elements: ");
	scanf("%d",&n);
	printf("\n");
	
	for(i = 0;i< n;i++){
		printf("Enter Number %d: ",(i+1));
		scanf("%d",&num[i]);
	}	
	
	for (i = 0; i < n; i++)
       {
       	 sprintf(rst, "%d", num[i]); 
       	 array[i] = malloc(sizeof(int));
       	 *array[i] = rst;
       	 
	   }
		
		
	int pid = fork();
	  
	//Checking if pid =0 then it is chile process
	if(pid == 0){
			sleep(2);
			printf("\nUsing EXECV in main Program\n");
			char *args[]={'./exec2',array,NULL};
			printf("\n%s",*args[0]);
			execvp(args[0],args);
     		printf("\nReturned In Main program\n");
			 
     
	}else{
		
			printf("\nHelloo\n");
			wait(NULL); //Adding Sleep in parent Process execution
	}



}
