#include<stdio.h>
void Swap(int x,int y)
{
	int tmp=0;
	tmp=x;
	x=y;
	y=tmp;
}
int main()
{
	int a=10;
	int b=20;
	//int tmp=0;
	printf("a=%d",a);
	printf("b=%d\n",b);
	/*                                                              plan 1   error
	tmp=a;
	a=b;
	b=tmp;
	*/
	Swap(a,b);
	printf("a=%d",a);
	printf("b=%d\n",b);
	
	return 0;
}
