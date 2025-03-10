//Enter temp in fahrenheit and dsiaply in centigrade
# include<stdio.h>
int main()
{
	float temp_f;
	printf("Enter temperature in Fahrenheit :");
	scanf("%f",&temp_f);
	float temp_c=((temp_f-32)*5)/9;
	printf("The temperature in centigade = %.2f",temp_c);
	return 0;
}
