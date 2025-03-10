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
    char str[100],revstr[100];
    printf("Enter the string =");
    scanf("%[^\n]s",str);
    int i=0;
    for(i=0;i<length(str);i++)
        revstr[length(str)-1-i]=str[i];
    int check =0;
    for(i=0;i<length(str);i++)
    {
	if(str[i] == revstr[i])
            check=1;
        else    
            check=0;
    }
    if(check ==1)
	printf("%s is a palindrome string!",str);
    else
	printf("%s is not a plaindrome string!",str);
}
