// C program to implement one side of FIFO 
// This side writes first, then reads 
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd; 

	// FIFO file path 
	char * myfifo1 = "myfifo1"; 

	char * myfifo2 = "myfifo2"; 

	// Creating the named file(FIFO) 
	// mkfifo(<pathname>, <permission>)
	printf("\n Creating PIPE....\n"); 
	mkfifo(myfifo1, 0777); 
 	mkfifo(myfifo2, 0777); 
 	
	char arr1[1000], arr2[180]; 
	while (1) 
	{ 
		// Open FIFO for write only 
		fd = open(myfifo1, O_WRONLY); 
		
		printf("\nEnter The Data: ");
		fgets(arr2, 180, stdin); 
		
		write(fd, arr2, strlen(arr2)); 
		close(fd); 

		sleep(3);
		
		// Open FIFO for Read only 
		fd = open(myfifo2, O_RDONLY); 

		// Read from FIFO 
		read(fd, arr1, 1000); 

		// Print the read message 
		printf("\n%s\n", arr1); 
		close(fd); 


		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		
	} 
	return 0; 
} 
