#include<stdio.h>
#include<errno.h>
#include<string.h>
//int main()
//{

	//���ļ�test.txt
	//..��ʾ��һ��·��
	//.��ʾ��ǰ·��
	//fopen("../../test.txt","r");
	//fopen("test.txt","r");

//	FILE*pf=fopen("E:\\rs.txt", "r");          //����·��
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputc('b',pf);
//	int ch=fgetc(pf);
//	printf("%c", ch);
//	//�򿪳ɹ�
//	//���ļ�
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("E:\\rs.txt", "r");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//���ļ�
//	fgets(buf,1024,pf);
//	//printf("%s\n", buf);  //buf������һ������
//	puts(buf);
//	fgets(buf, 1024, pf);
//	//printf("%s\n", buf);
//	puts(buf);
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("E:\\rs.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	fputs("hello", pf);
//	fputs("world", pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	//�Ӽ��̶�ȡһ���ı���Ϣ
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//�ӱ�׼��������ȡ
//	fputs(buf, stdout);//�������׼�����
//	return 0;
//}
struct s
{
	int n;
	float score;
	char arr[10];
};
int main()
{
	struct S s={0};
	FILE* pf = fopen("E:\\rs.txt", "w");
	if (pf == NULL)
	{
		return 0;
	}
	////��ʽ������ʽ�ļ�
	//fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	
	fclose(pf);
	pf = NULL;
}




