#include<stdio.h>
#include<errno.h>
#include<string.h>
//int main()
//{

	//打开文件test.txt
	//..表示上一级路径
	//.表示当前路径
	//fopen("../../test.txt","r");
	//fopen("test.txt","r");

//	FILE*pf=fopen("E:\\rs.txt", "r");          //绝对路径
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputc('b',pf);
//	int ch=fgetc(pf);
//	printf("%c", ch);
//	//打开成功
//	//读文件
//	//关闭文件
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
//	//读文件
//	fgets(buf,1024,pf);
//	//printf("%s\n", buf);  //buf里面有一个换行
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
//	//从键盘读取一行文本信息
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//从标准输入流读取
//	fputs(buf, stdout);//输出到标准输出流
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
	////格式化的形式文件
	//fprintf(pf, "%d %f %s", s.n, s.score, s.arr);
	
	fclose(pf);
	pf = NULL;
}




