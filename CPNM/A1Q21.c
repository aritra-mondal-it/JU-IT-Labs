#include <stdio.h>
#include <math.h>
int main()
{
	int x,y,r,x1,y1;
	printf("Enter the x,y coordinate and the radius of the circle =");
	scanf("%d%d%d",&x,&y,&r);
	printf("Enter the x,y coordinate of the point =");
	scanf("%d%d",&x1,&y1);
	float d=sqrt(pow((x1-x),2)+pow((y1-y),2));
	if (d<r)
		printf("The point lies inside the circle");
	else if (d==r)
		printf("The point lies on the circle");
	else if (d>r)
		printf("The point lies outside the circle");
	return 0;
}
