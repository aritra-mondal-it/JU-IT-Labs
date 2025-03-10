 #include <stdio.h>
void main()
{
	int roll[10],a[10][5];
	char *name[10];	
	for(i=0;i<10;i++)
	{
		printf("Enter the name and roll no = ");
		scanf("%s %d",&name[i],&roll[i]);
		printf("Enter the marlks in 5 subjects : ");
		for(j=0;j<5;j++)
			scanf("%d",a[i][j]);
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<5;j++)
		{
			int t=0;
			for(column =j;column<5;column++)
			{
				if(a[j][i]>a[column][i])
				{
					t=a[j][i];
					a[j][i]=a[column][i];
					a[column][i]=t;
				}
			}
		}
	}
	for(i=0;i<5;i++)
	{
		printf

		
