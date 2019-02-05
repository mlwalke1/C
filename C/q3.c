/*
q3.c
Producer-Consumer Problem
by Mathew Walker
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h>

#define NUMThreads 2
#define SIZE 6

// Semaphores
sem_t mutex;
sem_t empty;
sem_t full;

// Threads
void *producerThread(void *param);
void *consumerThread(void *param);

// Structure to be produced/consumed
typedef struct {
	int data;
}item;
item buffer[SIZE];
int in = 0;
int out = 0;


int main(int argo, const char *argv[])
{
	int i;
	sem_init(&mutex, 0, 1);
	sem_init(&empty, 0, SIZE);
	sem_init(&full, 0, 0);
	
    pthread_t workers[NUMThreads];
	pthread_create(&workers[0],0,producerThread,NULL);
	pthread_create(&workers[1],0,consumerThread,NULL);
	for (i = 0; i < NUMThreads - 1; i++)
		pthread_join(workers[i], NULL);

	return 0;
}

//Producer
void *producerThread(void *params)
{
	do {
		/* produce an item in next produced */
		item *product = (item *) malloc (sizeof(item));
		product->data = rand() % 99;
		printf("Produced: %d\n",product->data);
		
		sem_wait(&empty);
		sem_wait(&mutex);

		/* add next produced to the buffer */
		buffer[in].data = product->data;
		printf("Added: %d to BUFFER %d\n",product->data,in);
		if(in < (SIZE - 1))
		{
			in++;
		}else {in = 0;}
		sem_post(&mutex);
		sem_post(&full);
	} while (true);
}

//Consumer
void *consumerThread(void *params)
{
	item *bufferOut = (item *) malloc (sizeof(item));
	do {
		sem_wait(&full);
		sem_wait(&mutex);

		/* remove an item from buffer to next consumed */
		bufferOut->data = buffer[out].data;
		buffer[out].data = 0;
		printf("Removed: %d from BUFFER %d\n",bufferOut->data,out);
		if(out < (SIZE - 1))
		{
			out++;
		}else {out = 0;}
		
		sem_post(&mutex);
		sem_post(&empty);

		/* consume the item in next consumed */
		printf("Consumed: %d\n",bufferOut->data);
		
	} while (true);
}
