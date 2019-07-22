//Including All Header Files

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>


//Function to Swap two values
int swap(int *a,int *b){

		int temp = *a;
		*a = *b;
		*b = temp;
}

//Function for bubble sort
void bubble_sort(int *num,int n){

	int i=0,j=0;
	for(i=0;i<n-1;i++){

		for(j=0;j<n-i-1;j++){

			if(num[j] > num[j+1])
			{
					swap(num+j,num+j+1);
			}
		}
	}
}

//Defining Main Function
int main(int argc,char *argv[]){
	//Declaring Variables
	int *num;
	int pid;
	int n = 0;
	int i = 0;
	char *rst,*array[10];



	printf("\n[INFO] Main Process Id: %d",getpid());
	printf("\n[INFO] Taking User Input");
	
	//Taking Total Number Of Elements From User	
	printf("\n\nEnter The Number Of Elements: ");
	scanf("%d",&n);
	printf("\n");

	//Assigning Memory To Array
	num = malloc(n*sizeof(int));
	
	//Taking Array Elements From User
	for(i = 0;i< n;i++){
		printf("Enter Number %d: ",(i+1));
		scanf("%d",num+i);
	}

	
	printf("\n[INFO] Parent Is Sorting The Data");

	//Calling Bubble Sort Function
	bubble_sort(num,n);
	printf("\n[INFO] Parent Waiting For Child Process Completion");

		//Creating New Child Process
		pid=fork();
		
		//Assigning Task to Child	
		if(pid == 0){

					printf("\n[INFO] Child Process Id: %d",getpid());
					printf("\n[INFO] Childs Parent Process Id: %d",getppid());	
				
				
				//Converting Integer To String
				printf("\n[INFO] Child Converting Integer Values to Strings");
			for(i = 0;i<n;i++){
					rst = (char *)malloc(sizeof(int));
					sprintf(rst,"%d",num[i]);
					array[i] = (char *)malloc(sizeof(int));
					array[i] = rst;
				}
				array[i]=NULL;


		    printf("\n[INFO] Calling EXECV");
			//Calling Execv()	
			execvp("./exec2",array);

		}
		//Remaining Parent Code Will Go HERE	
		else{
			
			printf("\n[INFO] Parent Process Id in pid > 0: %d",getpid());

			wait(NULL);
		}


}
