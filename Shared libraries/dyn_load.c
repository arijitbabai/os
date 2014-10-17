#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <sys/time.h>

int main() {
	void *handle;
	int (*fact_it)(int);
	int (*fact_re)(int);
	char *error;
	struct timeval start_time, end_time;	
	double time_r, time_i;
	int resultr, resulti;

	handle = dlopen("/home/student/Arijit Das/Shared libraries/libfact.so", RTLD_LAZY);
	if (!handle) {
	   fprintf(stderr, "%s\n", dlerror());
	   exit(EXIT_FAILURE);
	}

	dlerror(); /* Clear any existing error */

	*(void **) (&fact_re) = dlsym(handle, "fact_re");
	*(void **) (&fact_it) = dlsym(handle, "fact_it");

	if ((error = dlerror()) != NULL)  {
	   fprintf(stderr, "%s\n", error);
	   exit(EXIT_FAILURE);
	}

	gettimeofday(&start_time, NULL);
	resultr = (*fact_re)(900);
	gettimeofday(&end_time, NULL);
	time_r = (double)(end_time.tv_usec - start_time.tv_usec);


	gettimeofday(&start_time, NULL);
	resulti = (*fact_it)(900);
	gettimeofday(&end_time, NULL);
	time_i = (double)(end_time.tv_usec - start_time.tv_usec);

	printf("fact_re(900) computed in %fusec: %d\n", time_r, resultr);
	printf("fact_it(900) computed in %fusec: %d\n", time_i, resulti);
	dlclose(handle);
	return 0;
}

//At first we have to create a shared libraray libfact.so which contain fact_it() and fact_re() .
//gcc -shared factorial.c -o libfact.so
//This shared libraray is dynamically opend by the programme .
// gcc dyn_load.c -ldl
