//Give currency notes of 10,50 100 according to money given
# include<stdio.h>
int main()
{
	int amount,hundreds,fifty,tens;
	printf("Enter the amount in rupees :");
	scanf("%d",&amount);
	if (amount >100)
	{
		hundreds= amount/100;
		fifty= (amount- hundreds*100)/50;
		tens=(amount- hundreds*100 - fifty*50)/10;
	}
	else if (amount <100 && amount >=50)
	{
		hundreds= 0;
		fifty= amount/50;
		tens=(amount-fifty*50)/10;
	}
	else if (amount >10 && amount < 50)
	{
		hundreds= 0;
		fifty= 0;
		tens=amount/10;
	}
	else{
		printf("Please enter a higher amount !!");
		return 0;
	}
	printf("The no of hundreds=%d, fifties=%d and tens =%d",hundreds,fifty,tens);
	return 0;
}
		
