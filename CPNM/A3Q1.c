#include <stdio.h>
void main()
{
	int n,a[n],i,b[n];
	printf("Enter the number of elements = ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter value of a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
		b[n-i-1]=a[i];
	for(i=0;i<n;i++)
		printf("b[%d] = %d\n",i,b[i]);
}
		
