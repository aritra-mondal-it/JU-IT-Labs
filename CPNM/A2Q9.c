#include <stdio.h>
int isPrime(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if (n%i== 0)
			cnt++;
	}
	if (cnt ==2)
		return 1;
	else
		return 0;
}
void main()
{
	int n;
	printf("Enter a no = ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int cnt =0;
		if (n%i ==0)
		{
			if (isPrime(i) == 1)
				printf("%d is a prime factor of n\n",i);
		}
	}
}
