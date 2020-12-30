#include<stdio.h>
#include<string.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5               //���峣�������޸���Ϣ
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option                   //ö��
{
	EXIT,	//0
	ADD,	//1
	DEL,	//2
	SEARCH,	//3                   ��Ӧtest.c�ļ��е�case���       ��ǿ����Ŀɶ���
	MODIFY,	//4
	SHOW,	//5
	SORT,	//6
	SAVE    //7 
};

struct PeoInfo
{
	char name[MAX_NAME];  //����
	int age;              //����
	char sex[MAX_SEX];    //�Ա�             //һ���˵���Ϣ
	char tele[MAX_TELE];  //�绰
	char addr[MAX_ADDR];  //��ַ
};
//ͨѶ¼����
struct Contact
{
	struct PeoInfo date[MAX];           //���1000����Ϣ                               ��������������һ��ͨѶ¼
	int size;                           //��¼��ǰ�Ѿ��е�Ԫ�ظ���
};
//��������

//��ʼ��ͨѶ¼�ĺ���                          .h ��.c�ļ���ʵ��
void InitContact(struct Contact*ps);

//����һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps);

//��ʾͨѶ¼����洢�����ݣ���Ϣ��
void ShowContact(const struct Contact* ps);

//ɾ��ָ������ϵ��
void DelContact(struct Contact* ps);

//����ָ������ϵ�˵���Ϣ
void SearchContact(struct Contact*ps);

//�޸�ָ����ϵ��
void ModifyContact(struct Contact*ps);

//����ͨѶ¼����
void SortContact(struct Contact* ps);

//
void Save(struct Contact* ps);

