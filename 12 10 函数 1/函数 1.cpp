#include<stdio.h>
//#include<string.h>
/*int Add(int x,int,y)
{
	int z=0;
	z=x+y;
	return z;
}
int main()
{
	int a=10;
	int b=20;
	int sum=Add(a,b);
	printf("%d",sum);
	return 0;
}*/
/*int main()
{
	 char arr1[]="bit";
	 char arr2[20]="############";
	 //             bit\0#######   \0字符串的结束标制
	 strcpy(arr2,arr1);// \0也会被拷贝过去
	 printf("%s\n",arr2);
	//strcpy - -string copy 字符串拷贝
	//strlen - string length
	return 0;
}*/
//memset   memory(内存)  set（设置）
/*int main()
{
	char arr[]="hello world";
		memset(arr,'*',5);
	printf("%s\n",arr);
	//***** world
	return
		0;
}*/
int get_max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int main()
{
	int a=10;
	int b=20;
	int max=get_max(a,b);
	printf("max=%d\n",max);
	return 0;
}



