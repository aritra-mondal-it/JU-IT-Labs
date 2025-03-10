#include <stdio.h>
void main()
{
    int i,j,n;
    printf("Enter the value of n =\n");
    scanf("%d",&n); 
    for(i=1;i<=2*n-1;i++)
    {
        for(j=1;j<=2*n-1-i;j++)
            printf(" ");
        if(i%2 !=0)
        {
            for(j=1;j<=(i/2 +1);j++)
            {
                printf("%d",j);
                printf(" ");
            }
            for(j=i/2;j>=1;j--)
            {
                printf("%d",j);
                printf(" ");
            }
        }
        else
        {
            for(j=1;j<=i/2;j++)
            {
                printf("%d",j);
                printf(" ");
            }
            for(j=i/2;j>=1;j--)
            {
                printf("%d",j);
                printf(" ");
            }
        }
        printf("\n");
    }
}
