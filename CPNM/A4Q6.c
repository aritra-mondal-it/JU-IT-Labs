#include<stdio.h>
int length(char str[100])
{
    int length=0;
    while(str[length] != '\0')
        length++;
    return length;
}
void main()
{
    char str[100];
    printf("Enter a string = ");
    scanf("%[^\n]s",str);
    int i;
    printf("The reverse of the string = ");
    for(i=length(str)-1;i>=0;i--)
        printf("%c",str[i]);
}
