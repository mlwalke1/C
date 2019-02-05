/*
Lab 5
Pthread Mutex Locks
by Mathew Walker
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMThreads 6

int amount = 0;

void *depositThread(void *params);
void *withdrawThread(void *params);

int main(int argo, const char *argv[])
{
	int i;
	pthread_t workers[NUMThreads];
	
	/*create depositThread x 3 */
	for (i = 0; i < (NUMThreads/2); i++)
		pthread_create(&workers[i],0,depositThread,argv[1]);
	/*create withdrawThread x 3 */
	for (i = 3; i < NUMThreads; i++)
		pthread_create(&workers[i],0,withdrawThread,argv[2]);
	for (i = 0; i < NUMThreads - 1; i++)
		pthread_join(workers[i], NULL);
	
	printf("Final Amount: %d\n",amount);
	return 0;
}

void *depositThread(void *params)
{
	int deposit = (int *)params;
	printf("Depositing: %d\n", deposit);
	//lock
	amount += deposit;
	//unlock
	printf("New Balance: %d\n", amount);
	
	pthread_exit(0);
}

void *mergingThread(void *params)
{
	int withdraw = (int *)params;
	printf("Withdrawing: %d\n", withdraw);
	//lock
	amount -= deposit;
	//unlock
	printf("New Balance: %d\n", amount);
	
	pthread_exit(0);
}

