#include <stdio.h>
void main()
{
    int i,space,j,n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(space=1;space<=n-i;space++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("%d",j);
        for(j=i-1;j>=1;j--)
            printf("%d",j);
        printf("\n");
    }
    for(i=n-1;i>=1;i--)
    {
        for(space=1;space<=n-i;space++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("%d",j);
        for(j=i-1;j>=1;j--)
            printf("%d",j);
        printf("\n");
    }
}
