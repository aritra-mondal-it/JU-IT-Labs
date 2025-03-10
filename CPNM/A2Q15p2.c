#include <stdio.h>
void main()
{
    int i,j,space,n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(space =i;space<n;space++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("%d",j);
        printf("\n");
    }
}
