#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
void PrintGenerate(vector<vector<int>>& v, size_t Rows)
{
	int i, j;
	for (i = 0; i < Rows; i++)
	{
		
		for (int row = i; row < Rows; row++)
			{

				cout<<" ";
			}

		cout<<"[";

		for (j = 0; j < v[i].size(); j++)
		{
			
			cout<<v[i][j];
			if (i > 0 && j < v[i].size() - 1)
			{
				cout << ",";
			}

		}
		cout << "]" << endl;
	}
}

void generate(vector<int>& v, size_t n);//一维打印
vector<vector<int>>generate(int numRows) //二维打印杨辉三角
{
	vector<vector<int> >res;
	if (numRows < 1)
	{
		return res;
	}
	
	for (int i = 0; i < numRows; i++)
	{
		res.push_back(vector<int>());
	}
	res[0].push_back(1);
	for (int i = 1; i < numRows; i++)
	{
		res[i].push_back(1);
		for (int j = 1; j < i; j++)
		{
			res[i].push_back(res[i-1][j] + res[i-1][j-1]);
		}
		res[i].push_back(1);
	}
	PrintGenerate(res, numRows);
	return res;
}


//
//vector<string> letterCombinations(string digits) {
//	if (digits.size()>0)
//	{
//		vector<string>vs;
//		digits.size--;
//		letterCombinations(digits);
//	}
//	return ;
//}

int main()
{
	/*string Str("hello");
	string::iterator ps = Str.begin();
	for (ps; ps != Str.end(); ps++)
	{
		cout << *ps;
	}*/

	/*vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator pv;
	for (pv = v.begin(); pv != v.end(); pv++)
	{
		cout << *pv<<" ";
	}*/
   // generate(0);

   //begin()函数返回值为r容器的首地址。
	//void swap (vector& x);(交换两个容器的里的所有值)
	/*vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 10; i < 20; i++)
	{
		v2.push_back(i);
	}*/

	/*cout << "v1 = ";
	for (auto& i : v1)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "v2 = ";
	for (auto& i : v2)
	{
		cout << i << " ";
	}
	cout << endl;


	v1.swap(v2);

	cout << "v1 = ";
	for (auto& i : v1)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "v2 = ";
	for (auto& i : v2)
	{
		cout << i << " ";
	}
	cout << endl;*/
	//reference operator[] (size_type n);	//[]的重载
	//cout << v1[7] << " " << v2[7] << endl;

	//迭代器失效
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator iv = v.end();
    v.erase(iv-1);//end()-1是最后一个位置的值
	cout << *iv << endl;

	//iv = v.insert(iv, 10, 8);//用返回值接她，解决
	//cout << *iv << endl;
	//cout << v[v.size()-1] << endl;
	//v.erase(iv+2);

    system("pause");
    return 0;
}