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
    char name[100];
    int initials[3];
    name[0]=(char)(32);
    printf("Enter a string = ");
    scanf("%[^\n]s",str);
    int i,cnt=0;
    for(i=1;i<length(str)+1;i++)
        name[i]=str[i-1];
    for(i=0;i<length(str);i++)
    {
        if(name[i]==(char)(32))
        {
            initials[cnt]=i+1;
            cnt++;
        }
    }
    printf("The initials of the name = ");
    for(i=0;i<3;i++)
        printf("%c",name[initials[i]]);
}
