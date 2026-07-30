#include<stdio.h>
int main()
{
	int a,b,c;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	c=(a>b)?a:b;
	printf("\n Big number is :%d \n",c);
	return 0;
}
