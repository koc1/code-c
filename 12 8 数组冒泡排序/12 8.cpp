//��һ��������������ð������
#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i=0;
	//int sz=sizeof(arr)/sizeof(arr[0]);//������10
	for(i=0;i<sz;i++)
	{
		int flag=1;//������һ��Ҫ����ĵ������Ѿ�����
		//ÿһ��ð������
		int j=0;
		for(j=0;j<sz-i;j++)//9 8 7 6 5...0 �αȽ�
		{
			if(arr[j]>arr[j+1])
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=0;//���������������ʵ����ȫ����
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
	//arr�����飬���Ƕ�������д��Σ�ʵ���ϴ���ȥ��������arr��Ԫ�صĵĵ�ַ&arr��0��
	//��arr���������ų�����
	bubble_sort(arr,sz);//ð��������
	for(i=0;i<sz;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}