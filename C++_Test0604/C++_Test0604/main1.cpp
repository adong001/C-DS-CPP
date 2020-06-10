#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Board {
public:
	bool checkWon(vector<vector<int> > board) 
	{
		if (board[0][0] + board[1][1] + board[2][2] == 3)
		{
			return true;
		}
		if (board[2][0] + board[1][1] + board[0][2] == 3)
		{
			return true;
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] + board[i][1] + board[i][2] == 3)
			{
				return true;
			}
			if (board[0][i] + board[1][i] + board[2][i] == 3)
			{
				return true;
			}
		}
		return false;
	}
};
int main()
{
	string s;
	while (cin >> s)
	{
		int socre = 0;
		int Bword = 0, Sword = 0, Num = 0, sign = 0;
		int Size = s.size();
		if (Size <= 4)
		{
			socre += 5;
		}
		else if (5 <= Size && Size <= 7)
		{
			socre += 10;
		}
		else
		{
			socre += 25;
		}
		for (int i = 0; i < Size; i++)
		{
			if (isdigit(s[i]))
			{
				Num++;
			}
			else if (islower(s[i]))//Ð¡Ð´×ÖÄ¸
			{
				Sword++;
			}
			else if (isupper(s[i]))//´óÐ´×ÖÄ¸
			{
				Bword++;
			}
			else
			{
				sign++;
			}
		}
		if (Bword && Sword)
		{
			socre += 20;
		}
		else if (Bword == Size || Sword == Size)
		{
			socre += 10;
		}

		if (Num > 1)
		{
			socre += 20;
		}
		else if (Num == 1)
		{
			socre += 10;
		}

		if (sign > 1)
		{
			socre += 20;
		}
		else if (sign == 1)
		{
			socre += 10;
		}

		if (Bword && Sword && Num && sign)
		{
			socre += 5;
		}
		else if ((Bword || Sword) && Num && sign)
		{
			socre += 3;
		}
		else if ((Bword || Sword) && Num)
		{
			socre += 2;
		}

		if (socre >= 90)
		{
			cout << "VERY_SECURE" << endl;
		}
		else if (socre >= 80)
		{
			cout << "SECURE" << endl;
		}
		else if (socre >= 70)
		{
			cout << "VERY_STRONG" << endl;
		}
		else if (socre >= 60)
		{
			cout << "STRONG" << endl;
		}
		else if (socre >= 50)
		{
			cout << "AVERAGE" << endl;
		}
		else if (socre >= 25)
		{
			cout << "WEAK" << endl;
		}
		else
		{
			cout << "VERY_WEAK" << endl;
		}
	}
    return 0;
}