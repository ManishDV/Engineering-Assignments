
//Importing Required Header Files
#include <stdlib.h>
#include <stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include <unistd.h>

//Declaring Flags To Control The Flow
#define CONSUMED_BY_CLIENT -1
#define DATA_IS_NOT_FILLED_BY_SERVER 0
#define DATA_FILLED_BY_SERVER 1


#define CONSUMED_BY_SERVER 2
#define DATA_IS_NOT_FILLED_BY_CLIENT 3
#define DATA_FILLED_BY_CLIENT 4

//Structure for Shared memory
typedef struct mem{

	int status;
	int data[4];
}SHARED_MEMORY;


int main(){

	//Creating Object Of Structure
	SHARED_MEMORY *shm_ptr;
	int shmid ;

	//Creating Key to pass to the shmget()
	key_t key = ftok("A",1);

	//Calling shmget() to get shared memory identifier
	shmid = shmget(key,sizeof(SHARED_MEMORY),IPC_CREAT | 0666);

	//Checking For Errors In Creating Shared Memory
	if(shmid == -1){
		printf("Error In Creating Shared Memory\n");
	}else{
		printf("Shared Memory Created\n");
	}

	//Attaching Program To The Shared Memory
	shm_ptr = shmat(shmid,NULL,0);

	//Checking For Errors In Attaching To Shared Memory
	if((int)shm_ptr == -1){
		printf("Error In Attaching To The Memory\n");
	}else{
		printf("Attached To The Shared Memory\n");
	}

	//Making Status Of Shared Variable as DATA
	shm_ptr->status = DATA_IS_NOT_FILLED_BY_SERVER;

	for(int i=0;i<4;i++){
		sleep(1);
		int value = (rand() % 13);
		printf("\nValue : %d\n",value);
		printf("\n%d Is Written By SERVER\n",value);
		shm_ptr->data[i] = value;
	}	

	shm_ptr->status = DATA_FILLED_BY_SERVER;

	while(shm_ptr->status != CONSUMED_BY_CLIENT){
		sleep(1);
		printf("Server Is Waiting\n");
	}

	while(shm_ptr->status != DATA_FILLED_BY_CLIENT){
		sleep(1);
		printf("Server Is Waiting For Client To Write DATA\n");	
	}

	if(shm_ptr->status == DATA_FILLED_BY_CLIENT){
		for(int i=0;i<4;i++){
			sleep(1);
			printf("\n%d Read By Server\n",shm_ptr->data[i]);
		}	
	}

	shm_ptr->status = CONSUMED_BY_SERVER;
	shmdt(shm_ptr);
	shmctl(shmid,IPC_RMID,0);
	printf("Exiting The Server Program\n");
	return 0;
}


