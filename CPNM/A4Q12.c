#include <stdio.h>
void main()
{
    char str[100];
    printf("Enter a number = ");
    scanf("%s",str);
    int i=0,num=0;
    while(str[i]!='\0'){
        num=num*10+((str[i])-48);
        i++;
    }
    printf("The number in integer = %d",num);
}
