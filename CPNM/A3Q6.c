#include <stdio.h>
void main()
{
	int m[5][5];
	int tm[5];
	int i,j,stm;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter the marks in %d subject = ",j);
			scanf("%d",&m[i][j]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
			tm[i]+=m[i][j];
		stm+=tm[i];
	}
	printf("Total marks = ",stm);
	int highest=tm[0];
	for(i=1;i<2;i++)
	{
		if(tm[i]>highest)
			highest=tm[i];
	}
	printf("Highest marks =%d",highest);
}

