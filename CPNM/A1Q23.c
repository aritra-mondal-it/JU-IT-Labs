#include <stdio.h>
int main()
{
	int s;
	printf("Enter the time in seconds = ");
	scanf("%d",&s);
	int h=s/3600;
	int m=(s-h*3600)/60;
	int sec=s- h*3600 - m*60;
	printf("The time is %d hours %d minutes and %d seconds.",h,m,sec);
	return 0;
}
