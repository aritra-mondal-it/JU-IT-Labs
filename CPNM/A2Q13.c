#include <stdio.h>
int main()
{
	int n,a=-1,b=1;
	printf("Enter a number = ");
	scanf("%d",&n);
	printf("The Fibonacci Series is as follows :\n");
	for(int i=0;i<n;i++)
	{
		int c=a+b;
		a=b;
		b=c;
		printf("%d ,",c);
	}
}
