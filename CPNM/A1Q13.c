# include<stdio.h>
int main()
{
	int men=(52*80000)/100;
	int lmen=((35)*80000)/100;
	int itotal=((100-52)*80000)/100;
	int imen=(men-lmen);
	int iwomen =itotal-imen;
	printf("Total no of illeterate men =%d and total no of illeterate women =%d",imen,iwomen);
	return 0;
}


