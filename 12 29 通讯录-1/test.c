#include<stdio.h>
#include"contact.h"
#define MAX 1000
void menu()
{
	printf("\n\n\n");
	printf("*****************************************\n");
	printf("******** 1.add            2.del  ********\n");
	printf("******** 3.search         4.modify  *****\n");
	printf("******** 5.show           6.sort  *******\n");
	printf("******** 7.save           0.exit  *******\n");
	printf("*****************************************\n");

}
int main()
{
	printf("\n           已进入通讯录");
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含:1000的元素的数组和size
	InitContact(&con);    //   <---- 初始化通讯录
	
	do
	{
		menu();
		printf(" \n请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);             //增加一个人的信息--->(改变通讯录)
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);           //显示通讯录里面的联系人        可以传地址也可以传参   传地址的效率高
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			Save(&con);
			break;
		case EXIT:
			printf("\n退出通讯录\n");
			break;
		default:
			printf("\n选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
//25 40