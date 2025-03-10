#include <stdio.h>
void main()
{
	int n;
	printf("Enter a no to divide by = ");
	scanf("%d",&n);
	for(int i=1;i<=100;i++)
	{
		if (i%n ==0)
			printf("%d is divisible by %d \n",i,n);
	}
}
