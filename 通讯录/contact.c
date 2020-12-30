#include<stdio.h>
#include<string.h>
#include<errno.h>
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

//�����ļ��е���Ϣ��ͨѶ¼
void LoadContact(struct Contact* ps);



void InitContact(struct Contact*ps)
{
	memset(ps->date, 0, sizeof(ps->date));                          //��ʼ������
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
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
	//��ȡ�ļ�����ŵ�ͨѶ¼��
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
	if (ps ->size == MAX)                     //�ж�ͨѶ¼���������Ƿ�����
		printf("\nͨѶ¼�������޷�����\n");
	else
	{
		printf("\n���������֣�>");
		scanf("%s", ps->date[ps->size].name);
		printf("���������䣺>");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�>");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰��>");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������ַ��>");
		scanf("%s", ps->date[ps->size].addr);

		ps->size++;
		printf("\n��ӳɹ�\n\n");
		
	}
}





void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("\nͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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


static int FindByName(const struct Contact*ps,char name[MAX_NAME])      //  �ӹ��ܺ���  static���ξֲ����������Լ����ڵ�ԭ�ļ��ڿ���  ���ᱩ¶��ȥ
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))   //�����ַ����Ƚ��õ���strcmp
		{
			return i;
		}
	}
	return -1;        //�Ҳ��������
}







void DelContact(struct Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("\n������Ҫɾ���˵�����;>");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	pos=FindByName(ps,name);      //�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1
	//2.ɾ��
	if (pos==-1)
	{
		printf("\nҪɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j <ps->size-1 ; j++)
		{
			ps->date[j] = ps->date[j + 1];                            //ɾ������

		}
		ps->size--;
		printf("\nɾ���ɹ�\n");                                         //2.ɾ��

	}
	
}







void SearchContact( struct Contact* ps)
{
	int pos;
	char name[MAX_NAME];
	printf("\n������Ҫ�����˵�����:>");
	scanf("%s", name);
	pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("\nҪ���ҵĵ��˲�����");
	}
	else
	{ 
		printf("\n%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "סַ");
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
	printf("\n������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	pos=FindByName(ps, name);
	if (pos == -1)
	{
		printf("\nҪ�޸��˵���Ϣ������\n");
	}
	else
	{
		printf("\n����������:>");
		scanf("%s", ps->date[pos].name);
		printf("����������:>");
		scanf("%d", &(ps->date[pos].age));
		printf("�������Ա�:>");
		scanf("%s", ps->date[pos].sex);
		printf("������绰:>");
		scanf("%s", ps->date[pos].tele);
		printf("�������ַ:>");
		scanf("%s", ps->date[pos].addr);


		printf("\n�޸����\n");
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
	printf("\nͨѶ¼�Ѿ����������С����");
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
	//дͨѶ¼�е����ݵ��ļ���
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
	//����ͨѶ¼
	struct Contact con;//con����ͨѶ¼���������:1000��Ԫ�ص������size
	printf("\n           �ѽ���ͨѶ¼");
	InitContact(&con);    //   <---- ��ʼ��ͨѶ¼
	
	do
	{
		menu();
		printf(" \n��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);             //����һ���˵���Ϣ--->(�ı�ͨѶ¼)
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
			ShowContact(&con);           //��ʾͨѶ¼�������ϵ��        ���Դ���ַҲ���Դ���   ����ַ��Ч�ʸ�
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			//Save(&con);
			break;
		case EXIT:
			printf("\n�˳�ͨѶ¼\n");
			break;
		default:
			printf("\nѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
