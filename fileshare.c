#include <stdio.h>
#include <string.h>

int main(void)
{
	char source[1000000],symbol;
	FILE *fp = fopen("c.txt", "r");
	if(fp != NULL)
	{
	    while((symbol = getc(fp)) != EOF)
	    {
	        strcat(source, &symbol);
	    }
	    

	}
	fclose(fp);
	printf("%s\n",source);

}