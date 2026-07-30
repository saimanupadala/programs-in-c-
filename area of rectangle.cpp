#include<stdio.h>
int main()
{
float len,wid,area;
printf("Enter length&width of rectangle(in cm):");
scanf(" %f%f",&len,&wid);
area=len*wid;
printf("Area of rectangle=%3fcm² \n",area);
return 0;	
}

