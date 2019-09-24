// C program to implement one side of FIFO 
// This side reads first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd1; 
	int words=0,spac=0,lines=0,chars=0;
	// FIFO file path 	
	char * myfifo1 = "myfifo1"; 

	char * myfifo2 = "myfifo2"; 
	int i = 0;
	// Creating the named Pipe(FIFO) 
	// mkfifo(<pathname>,<permission>) 
	mkfifo(myfifo1, 0777); 
	mkfifo(myfifo2, 0777); 

	char str1[1000], str2[1000]; 
	while (1) 
	{ 
		sleep(3);
		// First open in read only and read 
		fd1 = open(myfifo1,O_RDONLY); 
		read(fd1, str1, 1000); 

		// Print the read string and close 
		printf("\nData Received: %s",str1); 
		close(fd1); 

		// Now open in write mode and write 
		// string taken from user.
		while(i < strlen(str1)){

			if(str1[i] == ' '){
				spac++;
			}

			if(str1[i] == '\n'){
				lines++;
			}

			i++;
		}
		chars = strlen(str1) - spac;
		words = spac+1;
		FILE *fptr;
		FILE *file = fopen("stats.txt", "w");
	    
	    fprintf(file, "Character Count: %d\nWord Count: %d\nSpace Count: %d\nLine Count: %d\n", chars, words, spac,lines);
	    fclose(file);
	    
	    
		fd1 = open(myfifo2,O_WRONLY);
		sprintf(str2,"Number Of Words: %d\nNumber Of Spaces: %d\nNumber Of Lines: %d\nNumber of Chars: %d",words,spac,lines,chars); 
		// fgets(str2, strlen(str2), stdin);
		
		write(fd1, str2, strlen(str2)+1); 
		close(fd1); 

		chars = 0;
		words = 0;
		lines = 0;
		spac = 0;
		
	} 
	return 0; 
} 
