#include <stdio.h>
int main()
{
	float bs;
	printf("Enter the basic salary = ");
	scanf("%f",&bs);
	float gs=((bs*60)/100)+((bs*15)/100)+bs;
	printf("Gross salary =%.2f",gs);
	return 0;
}
