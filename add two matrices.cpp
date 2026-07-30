#include<stdio.h>
int main()
{
	int a[2][2],b[2][2],c[2][2],i,j,n;
	printf("enter elements \n");
	scanf("%d",&n);
	printf("first matrices element \n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
	printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("second matrices element \n");
for(i=0;i<2;i++)
{
for(j=0;j<2;j++)
{
		printf("%d\t",b[i][j]);
}
printf("\n");
}
printf("resultant matrices \n");
for(i=0;i<2;i++)
{
	for(j=0;j<2;j++)
	{
		c[i][j]=a[i][j]+b[i][j];
		printf("%d\t",c[i][j]);
	}
	printf("\n");
}
return 0;
}
