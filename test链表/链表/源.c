#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;
typedef enum Status
{
	OK = 1
}Status;

typedef struct LNode   //构造结点
{

	ElemType data;
	struct LNode *next;
}LNode,*LinkList;



LinkList CreatLink()   //创建链表
{
	LinkList  p, s, head;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	printf("请输入数值(输入-1结束):\n");
	while (1){
		s = (LinkList)malloc(sizeof(LNode));        //创建新节点
		scanf("%d", &s->data);                      //输入结点数据
		if (s->data < 0)                            //输入负数 则结束
		{
			break;  
		}                     
		p->next = s;
		p = s;
	}
	p->next = NULL;        //最后一个节点链域指向为空
	return head;
}

void PutLink(LinkList L)             //输出链表
{
	int count = 0;
	if (L == NULL)
	{
		printf("此链表为空！！！\n\n");
	}
	LinkList p;
	p = L->next;                //L为表头结点，P为第一个有效结点
	if (p==NULL)
	{
		printf("此链表为空！！！\n\n");
	}
	while (p != NULL)
	{
		printf("\n链表的数据%d：",count);
		++count;
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
Status InsertLink(LinkList L)
{
	int i = 0;  //位置
	ElemType e = 0;   //数据
    int count = 0;   //记数器
	LinkList s=L, p;
	printf("请输入要插入的位置和数据：");
	scanf("%d%d", &i, &e);
	
	while (count != i)
	{
		s = s->next;
		++count;
	}
	p = (LinkList)malloc(sizeof(LNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
	return OK;
}

Status DeleteLink(LinkList L)
{
	int i = 0;  //位置
	ElemType e = 0;   //数据
	int count = 0;   //记数器
	LinkList s=L, p;
	printf("请输入要删除数据的位置：");
	scanf("%d", &i);
	while (count != i)
	{
		s = s->next;
		++count;
	}
	p = s->next;
	s->next = s->next->next;
	free(p);
	return OK;
}

Status DestoryLink(LinkList L)
{
	LinkList p=L ,q= L;
	L->next= NULL;
	while (p)
	{
		p = q->next;
		q->next = NULL;
		free(q);
		q = p;
	}
	free(p);
	p = q = NULL;
	return OK;
}

int menu()
{
	int choice = 0;
	printf("\t\t\t\t********************\n");
	printf("\t\t\t\t*****1.录入数据*****\n");
	printf("\t\t\t\t*****2.插入数据*****\n");
	printf("\t\t\t\t*****3.删除数据*****\n");
	printf("\t\t\t\t*****4.删除链表*****\n");
	printf("\t\t\t\t*****5.退出    *****\n");
	printf("\t\t\t\t********************\n\n");
	printf("\t\t\t\t输入你的选择:");
	scanf("%d", &choice);
	return choice;
}
int main()
{
	LinkList L=NULL;
	while (1)
	{
	int choice = menu();
		switch (choice)
		{
		case 1:
			system("cls");
			L = CreatLink();
			PutLink(L);
			break;
		case 2:
			system("cls");
			InsertLink(L);
			PutLink(L);
			break;
		case 3:
			system("cls");
			DeleteLink(L);
			PutLink(L);
			break;
		case 4:
			system("cls");
			DestoryLink(L);
			PutLink(L);
			break;
		case 5:
			exit(1);
		default:system("cls"); printf("输入错误！！！"); /*goto loop;*/
		}
	}
	system("pause");
	return 0;
}

