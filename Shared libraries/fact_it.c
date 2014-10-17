#include <stdio.h>
int main()
{
	//int n;
	//printf("Enter the no.\n");
	//scanf("%d",&n);
	printf("%d\n",fact_it(15));
	return 0;
}
//We have to create a shared object which contain fact_it() .
//gcc -c it_fact.c -o libfactit.so
//After that we have to link it in the command line.
//gcc fact_it.c -L . -lfactit

