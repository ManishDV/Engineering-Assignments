#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){


	int pd[2],pd2[2];
	char path[50];
	char readPipe[50];
	int pid;int i =0;
	char content[1000];
	char content2[1000];
	
	
	printf("\n----------------------------------------");
	printf("\n[INFO.... IN PARENT] \n\nEnter Path Name: ");
	scanf("%s",&path);
	
	pipe(pd);
	pipe(pd2);
	
	
	pid = fork();
	
	
	if(pid == 0){
		sleep(2);
		printf("\n[INFO.... IN CHILD]");
		close(pd[1]);
		read(pd[0],readPipe,50);
		FILE *fptr;
		fptr = fopen(readPipe, "r");
		close(pd[0]);
	
    if (fptr == NULL)

    {

        printf("Cannot open file \n");

        exit(0);

    }

    char ch = fgetc(fptr);

    while (ch != EOF)

    {
    	content[i] = ch;
    	ch = fgetc(fptr);
        i++;
    }
    
    fclose(fptr);

    close(pd2[0]);
    write(pd2[1],content,strlen(content)+1);
	close(pd2[1]);
    
    printf("\n[INFO] Data Wriiten By Child On Second PIPE");
	printf("\n----------------------------------------");
		
	
	}else if(pid > 0){
		
		close(pd[0]);
		write(pd[1],path,strlen(path)+1);
		close(pd[1]);
		
		sleep(5);

		printf("\n[INFO] PARENT WRITING DATA TO STDOUT.....\n");
		close(pd2[1]);
		read(pd2[0],content2,1000);
		printf("\n%s\n",content2);
		close(pd2[0]);
		

	}else{
	
		printf("\nFork Failed\n");
	}
		


	return 0;

}
