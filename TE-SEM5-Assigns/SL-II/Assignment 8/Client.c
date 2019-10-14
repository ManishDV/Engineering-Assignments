#include <stdlib.h>
#include <stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include <unistd.h>

#define CONSUMED_BY_CLIENT -1
#define DATA_IS_NOT_FILLED_BY_SERVER 0
#define DATA_FILLED_BY_SERVER 1


#define CONSUMED_BY_SERVER 2
#define DATA_IS_NOT_FILLED_BY_CLIENT 3
#define DATA_FILLED_BY_CLIENT 4

typedef struct mem{

	int status;
	int data[4];
}SHARED_MEMORY;


int main(){

	SHARED_MEMORY *shm_ptr;
	int shmid ;

	key_t key = ftok("A",1);
	shmid = shmget(key,sizeof(SHARED_MEMORY),IPC_CREAT | 0666);

	if(shmid == -1){
		printf("Error In Creating Shared Memory\n");
	}else{
		printf("Shared Memory Created\n");
	}

	shm_ptr = shmat(shmid,NULL,0);

	if((int)shm_ptr == -1){
		printf("Error In Attaching To The Memory\n");
	}else{
		printf("Attached To The Shared Memory\n");
	}

	while(shm_ptr->status != DATA_FILLED_BY_SERVER){
		sleep(1);
		printf("\nClient Is Wating For Server To Write Data\n");	
	}


	for(int i=0;i<4;i++){
		sleep(1);
		printf("\n%d Is Read By CLIENT\n",shm_ptr->data[i]);
	}	

	shm_ptr->status = CONSUMED_BY_CLIENT;
	sleep(2);
	printf("\nData Is Condumed By Client");
	shm_ptr->status = DATA_IS_NOT_FILLED_BY_CLIENT;

	printf("\nClient Is Writing Data");
	for(int i=0;i<4;i++){
		sleep(1);
		int value = (rand() %  10);
		printf("\nValue : %d\n",value);
		printf("\n%d Is Written By CLIENT\n",value);
		shm_ptr->data[i] = value;
	}
		
	shm_ptr->status = DATA_FILLED_BY_CLIENT;
	
	while(shm_ptr->status != CONSUMED_BY_SERVER){
		sleep(1);
		printf("\nCLIENT IS WAITING FOR SERVER TO READ THE DATA\n");
	}	

	shmdt(shm_ptr);
	printf("Exiting The Client Program\n");
	return 0;
	}



