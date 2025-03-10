#include <stdio.h>
void main()
{
	int i,n;
	printf("Enter the number of elments = ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		int temp =0;
		if(a[i]>a[i+1])
		{
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}	
	printf("Range =  %d",a[n-1]-a[0]);
}		

