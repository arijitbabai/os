#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>


void *thread();

int main(void)

{
	int j;
	pthread_t tid;
	struct rlimit res;
	getrlimit(RLIMIT_NPROC,&res);
	printf("%d\n",(int) res.rlim_cur);

	for(j =0 ; ; j++ )
	{
		int k = pthread_create(&tid,NULL,thread,"Thread created");
		if(k != 0)
			break;
	}
	printf("%d\n",j);
	exit(0);

}

void *thread(void *arg)
{
	char *str;
	str = (char *)arg;
	pthread_t  j ;
	j = pthread_self();

	//printf("%s\n%u\n",str,(unsigned)j);
	getchar();
	return NULL;
}


