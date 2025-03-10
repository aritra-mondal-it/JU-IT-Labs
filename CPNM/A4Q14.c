#include<stdio.h>
void main()
{
	char str[100];
	printf("Enter a string :");
	scanf("%[^n]s",str);
	int i=0,cnt=1;
	while(str[i]!='\0')
	{
		if ((char)str[i] ==32 || (char)str[i] == '.' || (char)str[i] ==',' || (char)str[i] =='?' || (char)str[i] == '!')
			cnt++;
		i++;
	}
	printf("Total no of words in the string = %d",cnt);
}

