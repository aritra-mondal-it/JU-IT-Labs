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
    char newstr[100];
    newstr[0]=(char)(32);
    int i=0;
    for(i=0;i<length(str);i++)
        newstr[i+1]=str[i];
    printf("The new string = ");
    for(i=0;i<length(newstr)+1;i++)
    {
        if(newstr[i]==(char)(32) && newstr[i+4]==(char)(32))
        {
            if(newstr[i+1] == (char)(116) && newstr[i+2]==(char)(104) && newstr[i+3]==(char)(101))
                i=i+4;
        }
        //printf("%d",i);
        printf("%c",newstr[i]);
    }
}
