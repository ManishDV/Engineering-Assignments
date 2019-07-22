//Including Required Header Files

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


//Defining Function For Binary Search
void binary_search(int num[10],int first,int last){

			int key=0;


			printf("\n[INFO] Taking Input For Searching");

			//Taking Input From User For Number To Be Search
			printf("\nEnter The Value To Be Searched: ");
			scanf("%d",&key);
			int mid = 0;
			
			//Looping While First And Last Value is not same
			while(first <= last){
				 mid = (first + last) / 2 ;
				if(key < num[mid]){
					last = mid-1;
				}
				else if(key > num[mid]){
					first = mid+1;
				}else{
					printf("\nElement Found At %d Location",mid );
					return;
				}
			}

			printf("\nElement Is Not Found\n");
}

//Defining Main Function
int main(int argc,char *argv[]){
	
	//Declaring Variables
	int num[argc-1];
	int i=0;


	printf("\n[INFO] Converting Strings To Integer Values");
	//Converting Strings To Array
	for(i=0;i<argc;i++){
		num[i] = atoi(argv[i]);
	}


	printf("\n[INFO] Calling Binary Search Function");
	
	//Calling Function binary_search()
	binary_search(num,0,argc);
	printf("\n");
	return 0;
}
