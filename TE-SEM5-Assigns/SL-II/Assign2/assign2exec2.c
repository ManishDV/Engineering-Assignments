#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc,char *argv[]){
	//Calling Fork To Create Process	
	
	int num[10];
	int i=0;
	printf("\nIn Search Program");
	
	int size = 0;
	for(i = 0;argv[i]!='\0';i++){
		
		size++;
	}
	
	printf("\nSize Of Array: %d",size-1);
	//converting number from char to integer
	
	for(i=1;i<size;i++){
		num[i] = atoi(argv[i]);
	}
	
	printf("\nNumbers Are Successfully Converted");
	printf("\nConverted Numbers Are: ");
	
	for(i=1;i<size;i++){
	
		printf("\n%d",num[i]);
	}		
	return 0;
}
