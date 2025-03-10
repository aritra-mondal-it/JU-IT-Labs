#include <stdio.h>
int length(char str[100])
{
	int length=0;
	while(str[length] !=  '\0')
		length++;
	return length;
}
void main()
{
	char str[100];
	printf("Enter a string = ");
	scanf("%[^\n]s",str);
	int i=0;
	for(i=0;i<length(str);i++)
	{
		int temp=0;
		if(str[i] == (char)32)
		{
			
		}
		else
			printf("%c",str[i]);
			
	}
}
