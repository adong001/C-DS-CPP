#include"mahjong.h"
#include"data.h"
#include"goods.h"

//二、某老板想要一个能快速计算订单价格的程序，请你帮他设计一个类：
//1、这个类里需要原价和数量，原价从一个数组中读出即可（自行定义数组），数量需要初始化。
//2、老板会不定期调整价格，调整的方式是通过调整一个价格系数，这个系数乘以原价即为最终价格，
//这个折扣会影响到所有产品。请你设计出一个类能让老板轻松搞定这一切。

//const char FindOnceFirstString(const char *src)
//{
//	if (!*src)
//	{
//		return NULL;
//	}
//	const char *tmp = src;
//	int arr[256] = { 0 };
//	while (*tmp)
//	{
//		arr[(int)*tmp] += 1;//将字符转为int型作为数组的下标，数组值+1，作为这个字符出现的次数
//		tmp++;
//	}
//	tmp = src;
//	while (*tmp)
//	{
//		if (arr[(int)*tmp] == 1)
//		{
//			return *tmp;
//		}
//		tmp++;
//	}
//}
//char FindFirstRepeatString(char* src)
//{
//	if (!*src)
//	{
//		return NULL;
//	}
//	const char *tmp = src;
//	int arr[256] = { 0 };
//	while (*tmp)
//	{
//		arr[(int)*tmp] += 1;//将字符转为int型作为数组的下标，数组值+1，作为这个字符出现的次数
//		tmp++;
//	}
//	tmp = src;
//	while (*tmp)
//	{
//		if (arr[(int)*tmp] == 2)
//		{
//			return *tmp;
//		}
//		tmp++;
//	}
//}

int main()
{
	//char ar[] = "ashjkqwertyuiozxcvbnmlkjhgfdrtyuzxcv";
	///*printf("%c",FindOnceFirstString(ar));*/
	//printf("%c\n", FindFirstRepeatString(ar));
	//const int i = 0;
	//printf("%d\n", &i);
	//int *j = (int*)&i;
	//*j = 1;
	//printf("%d,%d ,%d\n", i,&i, *j);
	/*Data d1(2018,11,19,43);*/
	BossMenu();
	system("pause");
	return 0;
}