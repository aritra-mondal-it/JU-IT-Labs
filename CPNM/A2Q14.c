#include <stdio.h>
#include <math.h>
void main()
{
	for(int i=1;i<=200;i++)
	{
		int num=i;
		int sum=0;
		while (num>0)
		{
			int d=num%10;
			sum=sum+pow(d,3);
			num=num/10;
		}
		if (sum ==i)
			printf("%d is an armstrong number.\n",i);
	}
}
