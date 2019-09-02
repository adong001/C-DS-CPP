#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;


//二、某老板想要一个能快速计算订单价格的程序，请你帮他设计一个类：
//1、这个类里需要原价和数量，原价从一个数组中读出即可（自行定义数组），数量需要初始化。
//2、老板会不定期调整价格，调整的方式是通过调整一个价格系数，这个系数乘以原价即为最终价格，
//这个折扣会影响到所有产品。请你设计出一个类能让老板轻松搞定这一切。
class Goods
{
private:
	static double m_discount;//折扣
	static int m_kinds;//商品种类
	double m_price;//单价
	int m_amount;//数量
	static void Purchase();//打折
	static void ShowMenu 
public:
	Goods(float price = 0, int amount = 0);
	void Discount(int discount);
	

};
int Goods::m_kinds = 0;
double Goods::m_discount = 1;
void BossMenu();
