#include <stdio.h>
int sum_of_digits(int num);
void main()
{
    int n;
    printf("Enter a number = ");
    scanf("%d",&n);
    printf("The sum of digits = %d",sum_of_digits(n));
}
int sum_of_digits(int num)
{
    if (num == 0)
        return 0;
    else
        return ((num%10)+ sum_of_digits(num/10));
}
