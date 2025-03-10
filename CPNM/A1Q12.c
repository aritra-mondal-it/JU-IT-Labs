# include<stdio.h>
# include<math.h>
int main()
{
	float l,b;
	printf("Enter the length and breadth of a rectangle : ");
	scanf("%f%f",&l,&b);
	int ch;
	printf("Enter your choice : \n");
	printf("1.For area of rectangle and circle are equal. \n") ;
	printf("2.For perimeter of rectangle and circle are equal.\n");
	scanf("%d",&ch);
	if (ch ==1)
	{
		float r=sqrt((l*b)/M_PI);
		float peri= 2*(l+b);
		float circum= 2*M_PI*r;
		printf("Ratio of perimeter of rectangle to circumference of circle =%.2f",(peri/circum));
	}
	else if (ch ==2)
	{
		float r=(l+b)/(2*M_PI);
		float rarea=l*b;
		float rcircle=M_PI*(pow(r,2));
		printf("Ratio of area of rectangle to area of circle =%.2f",(rarea/rcircle));
	}
	else
		printf("Invalid choice !!");
	return 0;
}

