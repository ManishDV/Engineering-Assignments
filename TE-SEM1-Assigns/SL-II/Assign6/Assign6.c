#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
// #define THINKING 1
// #define EATING 2
// #define HUNGRY 3

sem_t cs[N];
pthread_mutex_t mt;

enum st{THINKING,EATING,HUNGRY} state[N];

void grabFork(int i){
	printf("\nPhilosopher [%d] Is Grabbing Fork...",i);

	pthread_mutex_lock(&mt);

	state[i] = HUNGRY;
	test(i);

	if(state[i] != EATING){

		sem_wait(&cs[i]);	
	}
	pthread_mutex_unlock(&mt);


}


void putFork(int i){

	printf("\nPhilosopher [%d] Is Putting Fork...",i);

	pthread_mutex_lock(&mt);

	state[i] = THINKING;
	test((i+1)%5);
	test((i+4)%5);
	
	pthread_mutex_unlock(&mt);

}


void test(int i){

	if(state[i] == HUNGRY && state[(i+1)%5] != EATING && state[(i+4)%5] != EATING){
		printf("\nPhilosopher [%d] Is EATING...",i);
		sleep(rand()%4);
		state[i] = EATING;
		sem_post(&cs[i]);
	}

}


void *philosopher(void * args){

	int i = *(int *)args;

	while(1){

		printf("\nPhilosopher [%d] Is Thinking...",i);
		sleep(rand() % 11);
		grabFork(i);
		putFork(i);

	}

}


void main(){

	pthread_t phil[N];
	int i=0;
	int err;
	pthread_mutex_init(&mt,NULL);

	for(i=0;i<N;i++){

		state[i] = THINKING;
		sem_init(&cs[i],0,0);
	}


	for(i=0;i<N;i++){

		void *args = &i;

		pthread_create(&phil[i],NULL,philosopher,args);

		if(err != 0){

			printf("\nError In Thread Creation");
		}

	}

	for(int i=0;i<N;i++){

		err = pthread_join(phil[i],NULL);
	}

}