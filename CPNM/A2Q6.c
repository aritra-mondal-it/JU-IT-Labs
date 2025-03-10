#include <stdio.h>
void main()
{
	int n;
	printf("Enter a no = ");
	scanf("%d",&n);
	int fact=1;
	for(int i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	printf("Factorial of the number = %d",fact);
}
