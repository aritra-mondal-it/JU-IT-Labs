#include <stdio.h>
void main()
{
    int m,n,i,j;
    printf("Enter the no of rows and columns = ");
    scanf("%d %d",&m,&n);
    int a[m][n],b[n][m];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("a[%d][%d] = ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Matrix is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            b[j][i]=a[i][j];
    }
    printf("\n");
    printf("Transpose matrix is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
}
