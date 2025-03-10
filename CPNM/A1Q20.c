#include <stdio.h>
int main()
{
	int x1,x2,x3,y1,y2,y3;
	printf("Enter The (x,y) coordinates of 1st point =");
	scanf("%d%d",&x1,&y1);
	printf("Enter The (x,y) coordinates of 2nd point =");
	scanf("%d%d",&x2,&y2);
	printf("Enter The (x,y) coordinates of 3rd point =");
	scanf("%d%d",&x3,&y3);
	float mab=(float)((y2-y1)/(x2-x1));
	float mbc=(float)((y3-y2)/(x3-x2));
	if (mab == mbc)
		printf("It falls on a straight line.");
	else
		printf("It does not fall on a straight line.");
	return 0;
}

