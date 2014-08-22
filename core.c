#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int num;
	num = sysconf(_SC_NPROCESSORS_CONF);
	printf("%d\n",num);
	return 0;

}