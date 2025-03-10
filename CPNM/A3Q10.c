#include <stdio.h>
#include <stdlib.h>

int kaprekar();
void decompose(int no,int list[4]);
void sort(int list[4]);
int calnum1(int list[4]);
int calnum2(int list[4]);

int main()
{
        kaprekar();
        return 0;
}
int kaprekar()
{
        int kaprekar,num;
	int list[4];
        printf("Enter a 4 digit number = ");
        scanf("%d",&num);
        kaprekar=num;
        do
        {
                num=kaprekar;
                decompose(num,list);
                sort(list);
                int n1,n2;
                n1=calnum1(list);
                n2=calnum2(list);
                kaprekar=n2-n1;
                printf("%d - %d = %d\n",n2,n1,kaprekar);
        }
        while(kaprekar !=0 && kaprekar !=num);
}
void decompose(int num,int list[4])
{
        int i;
        while(i<4)
        {
                list[i]=num%10;
                num=num/10;
                i++;
        }
}
void sort(int list[4])
{
        int i,j,min;
        for(i=0;i<=2;i++)
        {
                min=i;
                for(j=i+1;j<=3;j++)
                {
                        if(list[j] < list[min])
                                min=j;
                }
                if(min!=i)
                {
                        int temp;
                        temp=list[i];
                        list[i]=list[min];
                        list[min]=temp;
                }
        }
}
int calnum1(int list[4])
{
        int i,n1;
        n1=list[0];
        for(i=1;i<=3;i++)
                n1=(n1*10)+list[i];
        return n1;
}
int calnum2(int list[4])
{
        int i,n2;
        n2=list[3];
        for(i=2;i>=0;i--)
                n2=(n2*10)+list[i];
        return n2;
}
