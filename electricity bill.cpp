#include<stdio.h>
int main()
{
	int units;
	float amount,charge,total_amount;
	printf("enter total units conusumed:");
	scanf("%d",&units);
	if(units<=50)
	{
		amount=units*2.50;
		charge=30.0;}
		else if(units<=100)
		{
			amount=units*3.00;
			charge=50.0;
		}
		else if(units<=300)
		{
			amount=units*4.00;
			charge=100.0;
		}
		else
		{amount=units*5.00;
		charge=125.0;
		}
		total_amount=amount+charge;
		printf("electricity bill:$%.2f \n",total_amount);
		return 0;
	}
	

