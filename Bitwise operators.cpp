#include<stdio.h>
int main()
{
	int a,b;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	printf("\n Bitwise AND(&)\n %d & %d= %d \n",a,b,a&b);
	printf("\n Bitwise OR(|) \n %d | %d= %d \n",a,b,a|b);
	printf("\n Bitwise XOR(^) \n %d ^%d=%d \n",a,b,a^b);
	printf("\n leftshift(<<) \n %d << %d=%d \n",a,b,a<<b);
	printf("\n Rightshift(>>)\n %d <<%d=%d \n",a,b,a>>b);
	return 0;
}
