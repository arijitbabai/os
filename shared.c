#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>


int i = 10;

void * thread1(int *var); 
void * thread2(int *var);
int main(void)

{
	//identifier for the shared memory segment
	int segment_id;
	pthread_t tid1,tid2;

	//a pointer to the shared memory segment

	char* shared_memory;
	//the size (int bytes) of the shared memory

	const int size = 4096;

	//allocate a shared meomry segment

	segment_id = shmget(IPC_PRIVATE,size, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

	//detatch the shared memory segment 
	shmdt(shared_memory);
	//shared_memory = (char* ) shmat(segment_id,NULL, 0);

	pthread_create(&tid1,NULL,thread1, &segment_id);
	pthread_create(&tid2,NULL,thread2, &segment_id);
	pthread_join(&tid2,NULL);
	pthread_join(&tid1,NULL);

	//remove the shared memory
	shmctl(segment_id,IPC_RMID,NULL);

	return 0;

}

void * thread1(int *var)
{
	char name[100];
	char* shared_memory;
	

	shared_memory = (char * ) shmat(*var,NULL, 0);
	printf("Enter a string\n");
	while(1)
	{
		
		fgets(name, 100, stdin);
		i = 1;
		if( strcmp(name,"q") == 0)
		{	
			i = 2;
			break;
		}
		sprintf(shared_memory,name);
		printf("Write on shared memory\n");
	}
		
	shmdt(shared_memory);	
}

void * thread2(int  *var)
{
	
	char* shared_memory;
	
	
	shared_memory = (char * ) shmat(*var,NULL, 0);
	while(1)
	{
		if(i == 1)
		{
			printf("%s","Read from shared memory : " );
			printf("%s", shared_memory);
			
			i = 0;
		}
		if( i == 2)
			break;
	}
	shmdt(shared_memory);	
}