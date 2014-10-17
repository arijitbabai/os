int fact_re(int n)
{
	if(n==0 || n==1)
		return 1;
	else
		return n*fact_re(n-1);
}