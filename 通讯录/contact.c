#include<stdio.h>
#include<string.h>
#include<errno.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5               //定义常量方便修改信息
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option                   //枚举
{
	EXIT,	//0
	ADD,	//1
	DEL,	//2
	SEARCH,	//3                   对应test.c文件中的case语句       增强代码的可读性
	MODIFY,	//4
	SHOW,	//5
	SORT,	//6
	SAVE    //7 
};

struct PeoInfo
{
	char name[MAX_NAME];  //名字
	int age;              //年龄
	char sex[MAX_SEX];    //性别             //一个人的信息
	char tele[MAX_TELE];  //电话
	char addr[MAX_ADDR];  //地址
};
//通讯录类型
struct Contact
{
	struct PeoInfo date[MAX];           //存放1000个信息                               这两个足以描述一个通讯录
	int size;                           //记录当前已经有的元素个数
};
//声明函数

//初始化通讯录的函数                          .h 在.c文件中实现
void InitContact(struct Contact*ps);

//增加一个信息到通讯录
void AddContact(struct Contact* ps);

//显示通讯录里面存储的内容（信息）
void ShowContact(const struct Contact* ps);

//删除指定的联系人
void DelContact(struct Contact* ps);

//查找指定的联系人的信息
void SearchContact(struct Contact*ps);

//修改指定联系人
void ModifyContact(struct Contact*ps);

//排序通讯录内容
void SortContact(struct Contact* ps);

//加载文件中的信息到通讯录
void LoadContact(struct Contact* ps);



void InitContact(struct Contact*ps)
{
	memset(ps->date, 0, sizeof(ps->date));                          //初始化函数
	ps->size = 0;//设置通讯录最初只有0个元素
}




void LoadContact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* pfRead = fopen("contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("\nLoadContact::%s\n", strerror(errno));
		return;
	}
	//读取文件，存放到通讯录中
	while (fread(&tmp, sizeof(struct PeoInfo), 1, pfRead))
	{
		//CheckCapacity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}


	fclose(pfRead);
	pfRead = NULL;
}





void AddContact(struct Contact* ps)
{
	if (ps ->size == MAX)                     //判断通讯录函数里面是否已满
		printf("\n通讯录已满，无法增加\n");
	else
	{
		printf("\n请输入名字：>");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入年龄：>");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入性别：>");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话：>");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入地址：>");
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		printf("\n添加成功\n\n");
		
	}
}





void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("\n通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}


static int FindByName(const struct Contact*ps,char name[MAX_NAME])      //  子功能函数  static修饰局部变量，在自己所在的原文件内看到  不会暴露出去
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))   //两个字符串比较用的是strcmp
		{
			return i;
		}
	}
	return -1;        //找不到的情况
}







void DelContact(struct Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("\n请输入要删除人的名字;>");
	scanf("%s", name);
	//1.查找要删除的人在什么位置
	pos=FindByName(ps,name);      //找到了返回名字所在元素的下标，找不到返回-1
	//2.删除
	if (pos==-1)
	{
		printf("\n要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++)
		{
			ps->date[j] = ps->date[j + 1];                            //删除数据

		}
		ps->size--;
		printf("\n删除成功\n");                                         //2.删除

	}
	
}







void SearchContact( struct Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("\n请输入要查找人的名字:>");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("\n要查找的的人不存在");
	}
	else
	{ 
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "住址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}







void ModifyContact(struct Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("\n请输入要修改人的名字:>");
	scanf("%s", name);
	pos=FindByName(ps, name);
	if (pos == -1)
	{
		printf("\n要修改人的信息不存在\n");
	}
	else
	{
		printf("\n请输入名字:>");
		scanf("%s", ps->date[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->date[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->date[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->date[pos].tele);
		printf("请输入地址:>");
		scanf("%s", ps->date[pos].addr);


		printf("\n修改完成\n");
	}
}







void SortContact(struct Contact* ps)
{
	int a, b, c;
	for (a = 0; a < ps->size; a++)
	{
		for (b = 0; b < ps->size - a; b++)
		{
			if (ps->date[b].age < ps->date[b + 1].age)
			{
				c = ps->date[b].age;
				ps->date[b].age = ps->date[b + 1].age;
				ps->date[b + 1].age = c;
			}
		}
	}
	printf("\n通讯录已经按照年龄大小排序");
}






void SaveContact(struct Contact* ps)
{
	int i = 0;
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//写通讯录中的数据到文件中
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}





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
	int input = 0;
	//创建通讯录
	struct Contact con;//con就是通讯录，里面包含:1000的元素的数组和size
	printf("\n           已进入通讯录");
	InitContact(&con);    //   <---- 初始化通讯录
	
	do
	{
		menu();
		printf(" \n请选择:>");
		scanf("%d", &input);
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
			//Save(&con);
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
