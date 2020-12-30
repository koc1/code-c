
#include<stdio.h>

#include"contact.h"

void InitContact(struct Contact*ps)
{
	memset(ps->date, 0, sizeof(ps->date));                          //��ʼ������
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
	//���ļ����Ѿ���ŵ�ͨѶ¼�е���Ϣ���ص�ͨѶ¼����
	LoadContact(ps);
}

//��������

//void CheckCapacity(struct Contact* ps);

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
//void CheckCapacity(struct Contact* ps)
//{
//	if(ps->size==ps->capacity)
//}







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
	char name[MAX_NAME];
	printf("\n������Ҫɾ���˵�����;>");
	scanf("%s", name);
	//1.����Ҫɾ��������ʲôλ��
	int pos=FindByName(ps,name);      //�ҵ��˷�����������Ԫ�ص��±꣬�Ҳ�������-1
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
	char name[MAX_NAME];
	printf("\n������Ҫ�����˵�����:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
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
	char name[MAX_NAME];
	printf("\n������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	int pos=FindByName(ps, name);
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
	FILE* pfWrite = fopen("contact.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	//дͨѶ¼�е����ݵ��ļ���
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}

