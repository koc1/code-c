//#include<stdio.h>
////����������1��������������0
//int is_prime(int n)
//{
//	int a=2;
//	for (a = 2; a < n; a++)
//	{
//		if (n % a == 0)
//		return 0;
//	}
//	return 1;
//}
//int main()
//{
//	//��ӡ100-200֮�������
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d	", i);
//	}
//	return 0;
//}
//#include<stdio.h>
//int binary_search(int arr[], int k,int se)
//{
//	//int se = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right =se - 1;
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	//���ֲ���
//	//��һ�����������в��Ҿ����ĳ����
//	//����ҵ��˷��أ���������±ꡣ�Ҳ�������-1
//	//
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int se = sizeof(arr) / sizeof(arr[0]);
//	int k=7;
//	int ret=binary_search(arr,k,se);
//	if (ret == -1)
//	{
//		printf("�Ҳ���ָ��������");
//	}
//	else
//	{
//		printf("�ҵ�ָ�������֣��±���%d\n", ret);
//	}
//
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int len = 0;
//	//1
//	len = strlen("abc");
//	printf("%d\n", len);
//	//2
//	printf("%d\n", strlen("abc"));
//	return 0;
//}
#include<stdio.h>
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	return 0;
}