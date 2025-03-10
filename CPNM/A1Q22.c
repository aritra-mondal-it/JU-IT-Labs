#include <stdio.h>
int main()
{
	char ch;
	printf("Enter an character=");
	scanf("%c",&ch);
	int ascii=(int)ch;
	if (ascii >=65 && ascii <=90)
		printf("Capital letter");
	else if (ascii >=97 && ascii <=122)
		printf("Small letter");
	else if (ascii >=48 && ascii <=57)
		printf("Number");
	else
		printf("Special symbol");
	return 0;
}
