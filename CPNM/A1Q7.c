//Wap to find avergae and display below and above average
# include <stdio.h>
int main()
{
	float a,b,c;
	printf("enter 3 numbers:");
	scanf("%f%f%f",&a,&b,&c);
	float avg=(a+b+c)/3.0;
	if (a> avg)
		printf("Above averge value");
	else
		printf("Below average value");
	if (b> avg)
		printf("Above averge value");
	else
		printf("Below average value");
	if (c> avg)
		printf("Above averge value");
	else
		printf("Below average value");
	return 0;
}

