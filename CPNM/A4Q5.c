#include <stdio.h>
void main()
{
    char str[100];
    printf("Enter a string = ");
    scanf("%[^\n]s",str);
    int length=0;
    while(str[length] !='\0')
    {
        length++;
    }
    printf("The length of the string = %d",length);
}
