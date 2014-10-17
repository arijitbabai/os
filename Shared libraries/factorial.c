int fact_re(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact_re(n-1);
}

int fact_it(int n)
{
	int i,r=1;
	if(n == 0 || n ==1)
		return 1;
	else
	{
		for(i = 1; i <= n; i++)
		{
			r = r*i;
		}
		return r;
	}
}