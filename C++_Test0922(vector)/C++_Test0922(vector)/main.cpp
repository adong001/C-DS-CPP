#include"Vector.h"
#include"Vector.cpp"
#include<cstdlib>
int main()
{
	int ar[] = { 1, 2, 3, 4, 5 };
	Bit::vector<int>V(4,7);
	//Bit::vector<int>V1(V);
	Bit::vector<int>V2(ar,ar+5);
	V.insert(V.begin() + 2, 19);

	V.push_back(13);
	V.pop_back();
	for (auto& i : V)
	{
		cout << i << " ";
	}
	cout << endl;
	/*for (auto& i : V1)
	{
		cout << i << " ";
	}
	cout << endl;*/
	//V2.insert(V2.begin() + 2, ar+1, ar+3);
	//for (auto& i : V2)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;
	//V2.erase(V2.begin() + 2);

	//for (auto& i : V2)
	//{
	//	cout << i << " ";
	//}
	//cout << endl;

	//V2.erase(V2.begin() + 3,V2.end()-1);

	//for (auto& i : V2)
	//{
	//	cout << i << " ";
	//}
	cout << endl;
    system("pause");
    return 0;
}