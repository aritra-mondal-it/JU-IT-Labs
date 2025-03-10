#include <stdio.h>
int isamicable(int n1,int n2);
void main()
{
    int n1,n2;
    printf("Enter two numbers to check if they are amicable or not : ");
    scanf("%d%d",&n1,&n2);
    if (isamicable(n1,n2) == 1 )
        printf("%d and %d is amicable!",n1,n2);
    else    
        printf("%d and %d are not amicable!!",n1,n2);
}
int isamicable(int n1,int n2)
{
    int i,sum1=0,sum2=0;
    for(i=1;i<n1;i++)
    {
        if (n1%i==0)
            sum1+=i;
    }
    for(i=1;i<n2;i++)
    {
        if (n2%i==0)
            sum2+=i;
    }
    if (sum1==n2 && sum2==n1)
        return 1;
    else    
        return 0;
}
