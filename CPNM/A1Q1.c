//WAP to read two values and swap them
# include<stdio.h>
int main()
{
	int a,b;
	int c=0;
	printf("Enter two numbers a and b:");
	scanf("%d%d",&a,&b);
	c=a;
	a=b;
	b=c;
	printf("Value of a=%d and b= %d",a,b);
	return 0;
}

