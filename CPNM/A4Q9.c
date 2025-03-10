#include<stdio.h>
int length(char str[100])
{
    int length=0;
    while(str[length] != '\0')
        length++;
    return length;
}
char capital(char ch)
{
    int ascii=(int)ch;
    if ((ascii >=65 && ascii <=90) || ascii==32)
        return (char)ascii;
    else
        return (char)(ascii-32);
}
void main()
{
    char str[100];
    printf("Enter a string = ");
    scanf("%[^\n]s",str);
    int i;
    printf("The new string = ");
    for(i=0;i<length(str);i++)
        printf("%c",capital(str[i]));
}
