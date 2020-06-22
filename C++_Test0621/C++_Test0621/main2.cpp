#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

int countbottle(int num)
{
	int sum = 0;
	while (num > 1)
	{
		int result = num / 3;//可以兑换几瓶
		int remainder = num % 3;//兑换后剩余几瓶没换
		sum += result;//加上已经兑换的瓶子；
		num = result + remainder;//剩余可兑换的就是已经兑换加上还没兑换的
		if (num == 2)//剩余空瓶子是2瓶可以借一瓶，换了在还回去
		{
			++sum;
			break;
		}
	}
	return sum;
}
int main2()
{
	int n;
	while (cin >> n)
	{
		cout << countbottle(n) << endl;
	}
    return 0;
}