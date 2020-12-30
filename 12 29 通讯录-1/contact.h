#include<stdio.h>
#include<string.h>
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

//
void Save(struct Contact* ps);

