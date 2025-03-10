#include <stdio.h>
int main()
{
	int h,ts;
	float cc;
	printf("Enter the hardness, carbon content and tensile strength of steel = ");
	scanf("%d%f%d",&h,&cc,&ts);
	if (h>50 && cc<0.7 && ts >5600)
		printf("Grade 10");
	else if (h>50 && cc<0.7)
		printf("Grade 9");
	else if (cc<0.7 && ts >5600)
		printf("Grade 8");
	else if (h>50 && cc<0.7)
		printf("Grade 7");
	else if (h>50 || cc<0.7 || ts >5600)
		printf("Grade 6");
	else
		printf("Grade 5");
	return 0;
}
