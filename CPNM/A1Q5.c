//Input 2 integrs and show in fraction and decimal
# include<stdio.h>
# include<stdio.h>
int main()
{
	int a,b,max,min;
	printf("Enter two numbers =");
	scanf("%d%d",&a,&b);
	if (a>b){
		max=a;
		min=b;
	}
	else{
		max=b;
		min=a;
	}
	float divide=((float)max/(float)min);
	printf("Fraction will be %d/%d and after dividing =%.1f",max,min,divide);
	return 0;
}
