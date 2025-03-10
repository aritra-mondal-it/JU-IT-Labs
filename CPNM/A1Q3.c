//WAP to print sum of digits of a 3 digit no
# include<stdio.h>
int main()
{
	int n;
	printf("Enter a 3 digit number = ");
	scanf("%d",&n);
	if (n>99 && n<1000)
	{
		int sum=0;
		while (n>0)
		{
			int d=n%10;
			sum=sum+d;
			n=n/10;
		}
		printf("Sum of digits = %d",sum);
		return 0;
	}
	else{
		printf("Invalid input");
		return 0;
	}
}
