#include <stdio.h>
void main()
{
	for(int i=1;i<=100;i++)
	{
		int cnt=0;
		for(int j=1;j<=i;j++)
		{
			if (i%j ==0)
			cnt++;
		}
		if(cnt ==2)
			printf("%d is a prime number\n",i);
			
	}
}
