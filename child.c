#include <stdio.h>
#include <unistd.h>


int main(void)
{
	int i;
	pid_t n[10];
	for(i = 0 ; i < 10 ; i++)
		n[i] = fork();
	for(i = 0 ; i < 10 ; i++)
	{
		if( n[i]==0 )
			printf("I am in child\n %d",getpid());

		else
			printf("I am in parent\n %d",getpid());
	}

}