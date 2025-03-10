#include <stdio.h>
void main()
{
	int n;
	printf("Enter the number = ");
	scanf("%d",&n);
	int i=0,len=0,n1=n,n2=n;
	while(n1>0){
		n1=n1/10;
		len++;
	}
	char str[len];
	while (n2>0)
	{
		str[len-i-1]=(char)(n2%10+48);
		i++;
		n2=n2/10;
	}
	printf("%s",str);
}
