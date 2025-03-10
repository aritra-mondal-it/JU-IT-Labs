#include <stdio.h>
#include <malloc.h>
void main()
{
	int i,n,sum=0;
	int *a;
	printf("Enter the no of elements of the array = \n");
	scanf("%d",&n);
	a=(int *)malloc(n * sizeof(int));
	printf("Enter the elements =\n");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
		sum=sum+*(a+i);
	printf("Sum of all elements =%d",sum);
}

