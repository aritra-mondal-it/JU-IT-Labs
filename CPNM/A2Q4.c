#include <stdio.h>
void main()
{
	int n;
	int sum=0;
	printf("Enter a no to divide by = ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("Sum of series = %d",sum);
}
