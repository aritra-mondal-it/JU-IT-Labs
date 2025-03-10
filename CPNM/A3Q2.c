#include <stdio.h>
void main()
{
	int i,cnt,key,j,dup,n;
	printf("Enter the no of elements = ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Enter value of a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		cnt=0;
		key=a[i];
		for(j=0;j<n;j++)
		{	
			if(key==a[j])
				cnt++;
		}
		if(cnt >= 2)
			dup=a[i];
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=dup)
			printf("%d,",a[i]);
	}
}
