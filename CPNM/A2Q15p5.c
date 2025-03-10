#include <stdio.h>
void main()
{
    int i,j,n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    for(i=n;i>=0;i=i-2)
    {
        for(j=i;j>=0;j--)
            printf("%d",j);
        printf("\n");
    }
}
