#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
//二、某老板想要一个能快速计算订单价格的程序，请你帮他设计一个类：
//1、这个类里需要原价和数量，原价从一个数组中读出即可（自行定义数组），数量需要初始化。
//2、老板会不定期调整价格，调整的方式是通过调整一个价格系数，这个系数乘以原价即为最终价格，
//这个折扣会影响到所有产品。请你设计出一个类能让老板轻松搞定这一切。
class Goods
{
private:
	static double s_discount;//折扣
	static int s_kinds;//商品种类
	static Goods *s_point;//第一个成员的地址
	char m_name[20];//商品名称
	double m_price;//单价
	int m_amount;//数量
public:	
	static void Purchase(Goods *);//打折
	static void ShowGoods(Goods *);//显示所有商品信息
	static void PushGoods();//进货
	void GoodsSet(char *name , double price, int amount);
	static Goods* ReturnAdr();
};
void BossMenu();

