#include"goods.h"

int Goods::s_kinds = 0;
double Goods::s_discount = 1;
Goods * Goods::s_point = NULL;

void Goods::GoodsSet(char *name,double price, int amount)
{
	strcpy_s(m_name, name);
	m_price = price * s_discount;
	m_amount = amount;
}

void Goods::PushGoods()//进货
{
	Goods *goods = s_point;
	int choice;
	char tmp_name[20];
	double tmp_price;
	int tmp_amount;
	while(1)
	{
		cout << "\t\t\t\t输入1进货，0退出\n";
		cin >> choice;
		if (choice == 0)
		{
			break;
		}
		
		goods = (Goods*)realloc(goods, sizeof(Goods)*(s_kinds + 1));
		s_point = goods;//realloc开辟空间可能会改变原来的地址，所以每次都让s_point指向第一个对象的地址
		cout << "\t\t\t\t输入商品名称：";
		cin >> tmp_name;
		cout << "\t\t\t\t输入商品价格：";
		cin >> tmp_price;	
		cout << "\t\t\t\t输入商品数量：";
		cin >> tmp_amount;

		goods[s_kinds].GoodsSet(tmp_name, tmp_price , tmp_amount );
		s_kinds++;
	}
}

void Goods::Purchase(Goods *goods)//打折
{
	double discount;
	cout << "t\t\t\t输入你要打的折扣：(8折-8,9.5折-9.5)";
	cin >> discount;
	s_discount = discount * 0.1;
	for (int i = 0; i < s_kinds; i++)
	{
		goods[i].m_price *= s_discount;
	}
}

void Goods::ShowGoods(Goods *goods)//显示所有商品信息
{
	if (!goods)
	{
		cout << "\t\t\t\t还没进货\n";
		return ;
	}
	int i;
	printf("\n\n\n\t\t\t\t\t\t本店所有商品信息\n\n");
	printf("\t\t\t\t商品名称\t   单价(Kg/元)\t\t数量 \n\n");
	for (i = 0; i < s_kinds; i++)
	{
		printf("\t\t\t\t%-20s%-20f%-20d\n", goods[i].m_name, goods[i].m_price, goods[i].m_amount);
	}
	cout<<"\n\n\t\t\t\t共计"<<s_kinds<<"件商品\n";
}
Goods* Goods::ReturnAdr()
{
	return  s_point;
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
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:Goods::PushGoods(); break;
		case 2:Goods::ShowGoods(Goods::ReturnAdr()); break;
		case 3:Goods::Purchase(Goods::ReturnAdr()); break;
		case 4: exit(0); break;
		default: printf("错误输入!!!"); break;
		}
	}
}

