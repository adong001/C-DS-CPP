#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
#include<stdbool.h>
enum menu
{
	EXIT,
	ADD,
	DELETE,
	MODIFY,
	SEARCH,
	SORT,
	EMPTY,
	SHOW
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 100
#define TELE_SIZE 20
#define STUDENT_MAX 2
typedef struct student
{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	short int age;
	char addr[ADDR_SIZE];
	char tele[TELE_SIZE];
}stu;
typedef struct MailList
{
	//stu p_data[STUDENT_MAX];
	stu *p_data;
	int capacity;
	int size;
}MailList;
void menu()//打印菜单
{
	printf("\n\n\n");
	printf("\t\t\t\t             通讯录\n");
	printf("\t\t\t\t****************************\n");
	printf("\t\t\t\t*    1.add     2.delete    *\n");
	printf("\t\t\t\t*    3.modify  4.search    *\n");
	printf("\t\t\t\t*    5.sort    6.empty     *\n");
	printf("\t\t\t\t*    7.show    0.exit      *\n");
	printf("\t\t\t\t****************************\n");
}
bool InCapacity(MailList *Mail)
{
	stu *temp = NULL;
	assert(Mail != NULL);
	Mail->capacity = Mail->capacity + STUDENT_MAX;
	temp = realloc(Mail->p_data, sizeof(stu)*Mail->capacity);
	if (temp != NULL)
	{
		Mail->p_data = temp;
		return true;
	}
	return false;
}

void InitMailList(MailList *Mail)//初始化函数
{
	assert(Mail != NULL);
	Mail->size = 0;
	Mail->capacity = STUDENT_MAX;
	Mail->p_data = (stu*)malloc(sizeof(stu)*Mail->capacity);
	//calloc(Mail->p_data,STUDENT_MAX*sizeof(stu))
	memset(Mail->p_data, 0,STUDENT_MAX*sizeof(stu));
}

void AddMailList(MailList *Mail)//添加信息函数
{
	assert(Mail != NULL);
	if (Mail->size >= Mail->capacity && !InCapacity(&Mail))
	{
		printf("\t\t\t\t通讯录已满，不能插入！！！");
		return;
	}
	printf("\t\t\t\t请输入：\n");
	printf("\t\t\t\t姓名：");
	scanf("%s", Mail->p_data[Mail->size].name);
	printf("\t\t\t\t性别：");
	scanf("%s", Mail->p_data[Mail->size].sex);
	printf("\t\t\t\t年龄：");
	scanf("%d", &Mail->p_data[Mail->size].age);
	printf("\t\t\t\t地址：");
	scanf("%s", Mail->p_data[Mail->size].addr);
	printf("\t\t\t\t电话：");
	scanf("%s", Mail->p_data[Mail->size].tele);
	++Mail->size;
}

int FindName(MailList *Mail,char *name)
{
	int i;
	for (i = 0; i < Mail->size; i++)
	{
		if (strcmp(name,Mail->p_data[i].name )==1)
		{
			return i;
		}
	}
	return -1;
}

int Is_empty(MailList *Mail)
{
	return Mail->size ? 0 : 1 ;
}
void DelMailList(MailList *Mail)
{

	char name[NAME_SIZE];
	assert(Mail != NULL);
	if (Is_empty(&Mail))
	{
		printf("\t\t\t\t通讯录为空！\n");
	}
	printf("\t\t\t\t请输入要删除的姓名");
	scanf("%s", name);
	int n = FindName(Mail, name);
	if (n == -1)
	{
		return;
	}
	for (int i = n; i < Mail->size - 1; i++)
	{
		Mail->p_data[i] = Mail->p_data[i + 1];
	}
	Mail->size--;
}
void ShowMailList(MailList *Mail)
{
	assert(Mail != NULL);
	printf("%15s %5s %3s %10s %12s", "姓名" ,"性别", "年龄" ,"住址","电话\n");
	int i;
	for (i = 0; i < Mail->size; i++)
	{
		printf("%15s %5s %3d %10s %12s\n", Mail->p_data[i].name, Mail->p_data[i].sex,
			Mail->p_data[i].age, Mail->p_data[i].addr, Mail->p_data[i].tele);
	}
}

void SortMailList(MailList *Mail)
{
	assert(Mail != NULL);
	int i, j;
	stu temp;
	for (i = 0; i < Mail->size; i++)
	{
		for (j = 0; j < Mail->size - 1 - i; j++)
		{
			if (strcmp(Mail->p_data[j].name, Mail->p_data[j + 1].name)>0)
			{
				temp = Mail->p_data[j];
				Mail->p_data[j] = Mail->p_data[j + 1];
				Mail->p_data[j + 1] = temp;
			}
		}
	}
}
void Test()
{
		MailList mail;
		int input;
		InitMailList(&mail);
		menu();
		printf("\t\t\t\t请输入您的选择:");
		do
	{
			scanf("\t\t\t\t%d", &input);
			switch (input)
			{
			case ADD:AddMailList(&mail); break;
			case DELETE:DelMailList(&mail); break;
			/*case MODIFY:ModifyMailList(&mail); break;
			case SEARCH:SearchMailList(&mail); break;*/
			case SORT:SortMailList(&mail); break;
		/*	case EMPTY:EmptyMailList(&mail); break;*/
			case SHOW:ShowMailList(&mail); break;
			default:printf("输入选择不正确，请重新输入：");
			break;
			}
		} while (input);
}
//typedef struct st_type {
//
//	int i;    
//	int a[];//柔性数组成员 
//}type_a;
// 

int main1()
{
	Test();
}

//
//int main()
//{
//	int num;
//	int ret = 1;
//	int *p, *q;
//	p = (int *)malloc(sizeof(int)*ret);
//	q = p;
//	while (scanf("%d", &num) == 1 && q)
//	{
//		q = (int *)realloc(p, ret*sizeof(int));
//		q[ret-1] = num;
//		ret++;
//	}
//	printf("%d\n", ret-1);
//	for (int i = 0; i < ret - 1; i++)  
//	{
//		printf("%d ", p[i]);
//	}
//	free(p);
//	p = NULL;
//	system("pause");
//	return 0;
//}

//int main1()
//{
//	int a = 123;
//	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int c = 456;
//	printf("%p %p %p %p\n", &a, b, &b[9],&c);
//	printf("%d %d", b[-1], b[10]);
//}

int main()
{
	char c;
	int a = 10000;
	//FILE* fp1 = fopen("C:\\Users\\杨冬\\Desktop\\1.txt", "r");//FILE是文件类型(结构体名)
	//FILE* fp2 = fopen("C:\\Users\\杨冬\\Desktop\\2.txt", "w");
	FILE* fp2 = fopen("test.txt", "wb");
	/*while ((c = fgetc(fp1)) != EOF)

	
	{
		fputc(c, fp2);
	}*/
	fwrite(&a, 4, 1, fp2);
	fclose(fp2);
}