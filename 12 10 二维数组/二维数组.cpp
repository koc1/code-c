#include<stdio.h>
int main()
{
	int arr[]={1,2,3,4,5,6,7};
	printf("%p\n",arr);
	printf("%p\n",&arr[0]);
	printf("%d\n",*arr);
	int sz=sizeof(arr)/sizeof(arr[0]);
	printf("%p\n",&arr); //(ȡ����������ĵ�ַ)
	//1.sizeof(����)--�����ʾ�������飬sizeof����������
	//2.&�������������������������飬&��������ȡ��������������ĵ�ַ
	return 0;
}