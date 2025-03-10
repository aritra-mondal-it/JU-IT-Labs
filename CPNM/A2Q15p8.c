#include <stdio.h>
void main()
{
    int i,j,n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    for(i=1;i<=n+1;i++)
    {
        for (j=1;j<=2*n+1;j++)
        {
            if (j<=6-i || j>=4+i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (i = n ; i>= 1 ; i-- ) {
        for (j = 1 ; j<= 2*n+1 ; j++){
            if ( j<= n+2-i || j>=n+i )
                printf("*") ;
            else
                printf(" ") ; 
                }
        printf("\n");
    }
}
