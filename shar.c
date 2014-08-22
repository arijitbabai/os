#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <pthread.h>

void *thread1(void *var); 
void *thread2(void *var);
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

	segment_id = shmget(IPC_PRIVATE,size, S_IRUSR | S_IWUSR);

	//attach the shared memory segment 

	shared_memory = (char* ) shmat(segment_id,NULL, 0);

	pthread_create(&tid1,NULL,thread1, &segment_id);
	pthread_create(&tid2,NULL,thread2, &segment_id);
	pthread_join(&tid2,NULL);
	pthread_join(&tid1,NULL);

	//write a message to shared memory
	//sprintf(shared_memory,"Hi! I am Arijit");




	//now print out the string from shared memory
	//printf("%s\n",shared_memory);

	//now detatch the shared meomry
	shmdt(shared_memory);

	//now remove the shared memory segment
	shmctl(segment_id,IPC_RMID,NULL);

	return 0;

}

void *thread1(void *var)
{
	//int i;
	char* shared_memory;
	//i = (int *)var;

	shared_memory = (char* ) shmat(var,NULL, 0);
	sprintf(shared_memory,"Hi! I am Arijit");
	printf("Writting in thread1\n");
	return NULL;
}

void *thread2(void *var)
{
	int i;
	char* shared_memory;
	i =(int *)var;

	shared_memory = (char* ) shmat(i,NULL, 0);
	printf("%s\n", shared_memory);
	return NULL;


}