#include <stdio.h>
void main()
{
	int a[3][3],b[3][3];
	int i,j,k,sum[3][3],diff[3][3],pro[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("Enter value of a[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	{
	for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("Enter value of a[%d][%d] = ",i,j);
                        scanf("%d",&b[i][j]);
                }
        }
	for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        printf("Enter value of a[%d][%d] = ",i,j);
                        scanf("%d",&a[i][j]);
                }
        }		sum[i][j]=a[i][j]+b[i][j];
			diff[i][j]=a[i][j]-b[i][j];
			int temp=0;
			for(k=0;k<3;k++)
				temp=temp+(a[i][k]*b[k][j]);
			pro[i][j]=temp;
		}
	}
