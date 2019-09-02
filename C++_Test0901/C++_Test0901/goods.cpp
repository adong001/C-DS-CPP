#include"goods.h"

Goods::Goods(float price, int amount)
{
	m_price = price;
	m_amount = amount;
}

void Goods:: Discount(int discount)
{
	m_price *= discount;
}

void BossMenu()
{
	int choice;
	while (1)
	{
		printf("\n\n\n\t\t\t\t欢迎来到超市商品管理系统--BOSS模式\n\n\n\n");
		printf("\t\t\t\t1.进货\n\n");
		printf("\t\t\t\t2.显示所有商品信息\n\n");
		printf("\t\t\t\t3.活动打折\n\n");
		printf("\t\t\t\t4.退出\n\n");
		switch (choice)
		{
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: exit(1); break;
		default: printf("错误输入!!!"); break;
		}
		system("cls");
	}
}

