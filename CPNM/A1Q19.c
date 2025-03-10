#include<stdio.h>
int main()
{
	int ch;
	printf("Enter your choice:");
	scanf("%d",&ch);
	if (ch == 1)
	{
	float a,b,c;
	printf("Enter three angles of a triangle :");
	scanf("%f%f%f",&a,&b,&c);
	if ((a+b+c) == 180.00)
		printf("valid triangle !!");
	else
		printf("Not a valid triangle !!");
	}
	else if (ch ==2)
	{
	float a,b,c;
	printf("Enter three sides of a triangle :");
	scanf("%f%f%f",&a,&b,&c);
	if ((a+b)>c || (b+c)>a || (c+a)>b)
		printf("valid triangle !!");
	else
		printf("Not a valid triangle !!");
	}
	return 0;
}
