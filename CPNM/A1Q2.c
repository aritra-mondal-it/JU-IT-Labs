//length and breadth of a rectangle and radius of a circle are given , calculate area and perimeter of rectangle and area and circumference of a circle
# include<stdio.h>
# include<math.h>
int main()
{
	float l,b,r;
	printf("Enter the length, breadth of a rectangle and radius of a circle:");
	scanf("%f%f%f",&l,&b,&r);
	float rec_area=l*b;
	float peri=2*(l+b);
	float circle_area=M_PI*(r*r);
	float circum=2*M_PI*r;
	printf("Rectangle's area=%.2f and perimeter=%.2f and Circle's area=%.2f and circumference=%.2f",rec_area,peri,circle_area,circum);
	return 0;
}
	
