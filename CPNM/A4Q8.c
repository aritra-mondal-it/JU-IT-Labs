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
    printf("The new string = ");
    for(i=0;i<length(str);i++)
    {
        if(str[i]==(char)(32))
            printf("|");
        else
            printf("%c",str[i]);
    }
}
