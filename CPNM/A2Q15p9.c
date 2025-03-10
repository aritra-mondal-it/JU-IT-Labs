#include <stdio.h>
void main()
{
    int rows,columns,n;
    printf("Enter the value of n = ");
    scanf("%d",&n);
    for(rows=1;rows<=n;rows++)
    {
        for(columns=n;columns>rows;columns--)
            printf(" ");
        printf("+");
        for(columns=1;columns<2*(rows-1);columns++)
            printf(" ");
        if (rows == 1)
            printf("\n");
        else
            printf("+\n");        
    }
    for(rows=n-1; rows >=1;rows--)
    {
        for(columns=n;columns>rows;columns--)
            printf(" ");
        printf("+");
        for(columns=1;columns<2*(rows-1);columns++)
            printf(" ");
        if(rows == 1)
            printf("\n");
        else
            printf("+\n"); 
    }
}
