//max and min of three numbers
# include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter 3 numbers :");
	scanf("%d%d%d",&a,&b,&c);
	int max,min;
	if (a>b &&a>c)
	{
		max=a;
		if(b>c)
			min=c;
		else
			min=b;
	}
	if (b>a &&b>c)
	{
		max=b;
		if(a>c)
			min=c;
		else
			min=a;
	}
	if (c>b &&c>a)
	{
		max=c;
		if(b>a)
			min=a;
		else
			min=b;
	}
	printf("Maximum = %d and minimu = %d",max,min);
	return 0;
}
