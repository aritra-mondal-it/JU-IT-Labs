#include <stdio.h>
int main()
{
	char str[6];
	printf("Enter a string :");
	scanf("%s",str);
	char *str2;
	for (int i=0; str[i] !='\0';i++)
	{
		str[i]=str[i]+30;
	}
	printf("New string = %s",str);
	return 0;
}
