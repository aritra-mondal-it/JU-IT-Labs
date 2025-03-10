#include <stdio.h>
#include <math.h>
int main()
{
	int x,y,d;
	printf("Enter the value of X and Y = ");
	scanf("%d%d",&x,&y);
	int num=y;
	while(num>0)
	{
		d++;
		num=num/10;
	}
	int nno=x*pow(10,d)+y;
	printf("New number = %d",nno);
	return 0;
}
