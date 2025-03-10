# include<stdio.h>
int main()
{
	int class,sub;
	printf("Enter the class obtained and no of subject failed  :");
	scanf("%d%d",&class,&sub);
	int grace=0;
	switch (class)
	{
	case 1:
	if (sub>3)
		printf("No grace marks");
	else 	
		grace=5*sub;
	break;
	case 2:
	if (sub>2)
		printf("No grace marks");
	else 	
		grace=4*sub;
	break;
	case 3:
	if (sub>3)
		printf("No grace marks");
	else 	
		grace=5*sub;
	break;
	deafult:
	printf("Inavlid class !!");
	}
	return 0;
}
