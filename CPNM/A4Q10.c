#include <stdio.h>
#define vowels str[i]=='a' || str[i]=='A' || str[i]=='e' || str[i]=='E' || str[i]=='i' || str[i]=='I' || str[i]=='o' || str[i]=='O' || str[i]=='u' || str[i]=='U'
int Vowelcount(char str[100])
{
    int i,count=0;
    printf("The Vowels are : ");
    for(i=0;str[i]!='\0';i++)
    {
        if (vowels)
        {
            i++;
            if(vowels)
            {
                printf("%c%c ",str[i-1],str[i]);
                count++;
            }
        }
    }
    return count;
} 
void main() 
{
    char str[100];
    printf("Enter a string =");
    scanf("%[^/n]s",str);
    printf("\nTotal number of vowels in succession = %d",Vowelcount(str));
}  
