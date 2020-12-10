#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7};
	printf("%p\n",arr);
	printf("%p\n",&arr[0]);
	printf("%d\n",*arr);
	int sz=sizeof(arr)/sizeof(arr[0]);
	printf("%p\n",&arr); //(取出的是数组的地址)
	//1.sizeof(数组)--数组表示整个数组，sizeof（数组名）
	//2.&数组名，数组名代表整个数组，&数组名，取出的是整个数组的地址
	return 0;
}