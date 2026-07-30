#include<stdio.h>
int main(){
	float side,area;
	printf("Enter side of square(in cm):");
	scanf("%f",&side);
	area=side*side;
	printf("Area of square=%2f cm² \n",area);
	return 0;
}

