# include<stdio.h>
# include<math.h>
int main()
{
	int n;
	printf("Enter a number =");
	scanf("%d",&n);
	int nno=0;
	int cnt=0;
	while (n!=0)
	{
		int d=n%10;
		int rem=(d+1)%10;
		nno=nno+rem*pow(10,cnt);
		cnt++;
		n=n/10;
	}
	printf("New number = %d",nno);
	return 0;
}

