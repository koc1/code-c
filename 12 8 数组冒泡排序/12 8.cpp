//将一个整形数组排序（冒泡排序）
#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i=0;
	//int sz=sizeof(arr)/sizeof(arr[0]);//假设是10
	for(i=0;i<sz;i++)
	{
		int flag=1;//假设这一趟要排序的的数据已经有序
		//每一堂冒泡排序
		int j=0;
		for(j=0;j<sz-i;j++)//9 8 7 6 5...0 次比较
		{
			if(arr[j]>arr[j+1])
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=0;//本趟排序的数据其实不完全有序
			}
		}
		if(flag==1)
		{
			break;
		}
	}
}
int main()
{
	int arr[]={9,8,7,6,5,4,3,2,1,0};
	int i=0;
	int sz=sizeof(arr)/sizeof(arr[0]);
	//arr是数组，我们对数组进行传参，实际上传过去的是数组arr首元素的的地址&arr【0】
	//对arr进行排序，排成升序
	bubble_sort(arr,sz);//冒泡排序函数
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}