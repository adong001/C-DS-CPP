#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
void CoutVector(vector<int>& v)
{
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}
void test_vector_insert()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	cout << "v1 = ";
	CoutVector(v1);
	// 重载1: 
	//iterator insert(iterator pos1,const value_type& val)
	//在pos1位置插入val,value_type为一个模板，类型只能为vector传入的类型
	v1.insert(v1.begin() + 1, 40);
	cout << "v1 = ";
	CoutVector(v1);

	// 重载2:
	//iterator insert(iterator pos1,size_t num,const value_type& val)
	//在pos1位置插入num个val,value_type为一个模板，类型只能为vector传入的类型
	v1.insert(v1.begin() + 2, 4, 50);
	cout << "v1 = ";
	CoutVector(v1);

	// 重载3:
	//iterator insert(iterator pos1,iterator pos2,iterator pos3)
	//在pos1和pos2位置分别插入pos3的值
	v1.insert(v1.begin() + 1, v1.begin() + 2, v1.begin() + 4);
	cout << "v1 = ";
	CoutVector(v1);
}
void test_vector_erase()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(80);
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);

	//重载1：
	//iterator erase(const_iterator pos);
	//删除pos位置的元素
	v1.erase(v1.begin());
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);

	//重载2：
	//iterator erase(const_iterator first, const_iterator last);
	//删除first到last位置的元素
	//注意：1.删除时，包括first位置 但不包括last位置。
	//      2.若first越界(无论前越还是后越都会报错)  
	//      3.若last越界(无论前越还是后越都会报错)last在v1.begin()+size+1处才会越界

	v1.erase(v1.begin() +1, v1.begin() +11);
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);
}


int main()
{

	//test_vector_insert();
	test_vector_erase();
	//vector<int>v1;
	//cout << v1.size()<<endl;
	//vector<int>v2;
	////cout << v2.size() << endl;
	//for (int i = 0; i < 30; i++)
	//{
	//	v2.push_back(i);
	//	cout << "capacity=" << v2.capacity() << endl;//capacity至少扩1个，每次扩1.5倍(vs)/2倍(gcc)
	//}
	//for (auto i = v2.begin(); i != v2.end(); i++)
	//{
	//	cout << *i<<" ";
	//}
	//cout << endl;
	//for (auto i = v2.rbegin(); i != v2.rend(); i++)
	//{
	//	cout << *i << " ";
	//}

	//v2.insert()
	//	iterator insert(iterator position, const value_type& val);//在position之前插入val

	//iterator erase(iterator position);//删除position位置的数据
	//insert();//三种
	//erase()//两种
	system("pause");
	return 0;
}


int main1()
{
	char *p1;
	p1 = (char *)malloc(10);
	strcpy(p1, "hello");
	free(p1);
	printf("%s\n", p1);
	/*for (int i = 0; i < 10; i++)
	{
	printf("%d ", *(p2 + i));
	}*/
	//*(p1 + 99) = 1234;
	//printf("%d\n", *(p1 + 99));
	//p1 = (int *)realloc(p1, sizeof(int)* 10);
	//*(p1 + 9) = 1234;
	//printf("%d\n", *(p1 + 9));
	//p1 = (int *)realloc(p1, sizeof(int)* 1000);
	//*(p1 + 999) = 1234;
	//printf("%d\n", *(p1 + 999));
	//free(p1);
	//p2 = (int *)calloc(10, sizeof(int));
	//free(p2);
	/*for (int i = 0; i < 10; i++)
	{
	*(p1 + i) = i;
	}

	for (int i = 0; i < 10; i++)
	{
	printf("%d ",*(p1+i));
	}*/

	//free(p1);
	system("pause");
	return 0;
}