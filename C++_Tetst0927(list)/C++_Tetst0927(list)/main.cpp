#include"List.h"

int main()
{
	List<int> L(3,19);
	for (auto i = L.begin(); i != L.end();i++)
	{
		cout << i<<" ";
	}
    system("pause");
    return 0;
}