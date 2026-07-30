#include<stdio.h>
#define PI 3.14
int main()
{
float radius,area;
printf("Enter Radius of circle(in cm):");
scanf("%f",&radius);
area=PI*radius*radius;
printf("Area of circle=%2f cm\n",area);
return 0;	
}
