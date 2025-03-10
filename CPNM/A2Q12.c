#include <stdio.h>
void main()
{
	for(int i=1;i<=100;i++)
	{
		int n;
		printf("Enter a no = ");
		scanf("%d",&n);
		if (n >0)
			printf("%d is a postive integer.\n",n);
		else if( n < 0)
			printf("%d is a negative integer.\n",n);
		else
			printf("%d is zero.\n",n);
	}
}
