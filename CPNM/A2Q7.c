#include <stdio.h>
void main()
{
	int n;
	printf("Enter a no = ");
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int fact=1;
		for(int j=1;j<=i;j++)
		{		
			fact=fact*j;
		}
		sum=sum+fact;
	}
	printf("Factorial of the number = %d",sum);
}
