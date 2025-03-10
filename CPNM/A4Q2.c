#include <stdio.h>
int bin(int num);
void main()
{
    int n;
    printf("Enter a number in decimal number system = ");
    scanf("%d",&n);
    printf("The number in binary system = %d",bin(n));
}
int bin(int num)
{
    if (num ==0)
        return 0;
    else
        return ((num%2)+ 10*bin(num/2));
}
