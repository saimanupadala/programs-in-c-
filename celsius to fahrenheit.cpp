#include<stdio.h>
int main()
{
	float celsius,fahrenheit;
	printf("Enter temp in celsius");
	scanf("%f",&celsius);
	fahrenheit=(1.8*celsius)+32;
	printf("temperature in fahrenheit:%2f",fahrenheit);
	return 0;
}
