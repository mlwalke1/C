/*
q2.c
Multithreaded Sorting Application
by Mathew Walker
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMThreads 2
#define SIZE 10
 
int list1[SIZE] = {77, 12, 19, 43, 18, 24, 21, 62, 15, 18};
int list2[SIZE];

void *sortingThread(void *param);
void *mergingThread(void *param);

typedef struct
{
	int from_index;
	int to_index;
} parameters;

int main(int argo, const char *argv[])
{
	int i;
	pthread_t workers[NUMThreads];
	
	/*Establish first sortingThread*/
	parameters *data = (parameters *) malloc (sizeof(parameters));
	data->from_index = 0;
	data->to_index = (SIZE/2) - 1;
	pthread_create(&workers[0],0,sortingThread,data);
	/*Establish second sortingThread*/
	parameters *data1 = (parameters *) malloc (sizeof(parameters));
	data1->from_index = (SIZE/2);
	data1->to_index = SIZE - 1;
	pthread_create(&workers[1],0,sortingThread,data1);
	for (i = 0; i < NUMThreads - 1; i++)
		pthread_join(workers[i], NULL);
	/*Establish mergingThread*/
	pthread_t worker;
	pthread_create(&worker,0,mergingThread,NULL);
	pthread_join(worker, NULL);
	for(i = 0; i < SIZE; i++)
	{
		printf("%d\n",list2[i]);
	}

	return 0;
}

void *sortingThread(void *params)
{
	int j;
	int comp = 0;
	int temp = 0;
	parameters* p = (parameters *)params;
	int begin = p->from_index;
	int end = p->to_index; 
	for(j = begin; j <= end; j++)
	{
		list2[j] = list1[j];
	}
	while(comp != 1)
	{
		comp = 1;
		for(j = begin; j < end; j++)
		{
			if(list2[j] > list2[j + 1])
			{
				temp = list2[j];
				list2[j] = list2[j + 1];
				list2[j + 1] = temp;
				comp = 0;
			}
		}
		
	}

	pthread_exit(0);
}

void *mergingThread(void *params)
{
	int temp = 99;
	int comp = 0;
	int i;
	while(comp != 1)
	{
		comp = 1;
		for(i = 0; i < (SIZE - 1); i++)
		{
			if(list2[i] > list2[i + 1])
			{
				temp = list2[i];
				list2[i] = list2[i + 1];
				list2[i + 1] = temp;
				comp = 0;
			}
		}
		
	}

	pthread_exit(0);	
}
