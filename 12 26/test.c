#include<stdio.h>
int main()
{
	printf("hehe\n");
	main();
	return 0;
}
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	 }
	printf("%d", n % 10);
}
int main()
{
	unsigned int num = 0;
	scanf_s("%d", &num);//1234
	print(num);
	return 0;
}
