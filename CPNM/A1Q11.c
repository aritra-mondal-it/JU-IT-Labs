//Find aggregate and percentage marks of a student in 5 subjects
# include<stdio.h>
int main()
{
	float s1,s2,s3,s4,s5;
	printf("enter marks out of 100 of 5 students :");
	scanf("%f%f%f%f%f",&s1,&s2,&s3,&s4,&s5);
	if (s1 >100 || s2>100 || s3>10|| s4>100 || s5>100)
	{
		float agg=s1+s2+s3+s4+s5;
		float per=(agg/500.0)*100.0;
		printf("Aggregate marks = %.2f and Percentage marks = %.2f",agg,per);
		return 0;
	}
	else
	{
		printf("Invalid Input !!");
		return 0;
	}
}	
