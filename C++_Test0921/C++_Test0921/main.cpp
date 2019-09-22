#include<iostream>
#include<vector>
using namespace std;

//vector容器的insert（3种）、erase（2种）函数。

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
	//在pos1位置和pos2位置到pos3的值(只包括pos2位置的值，不包pos3的值，插入数据量为pos3-pos2)
	v1.insert(v1.begin() + 1, v1.begin() +0, v1.begin() + 1);
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

	v1.erase(v1.begin() + 1, v1.begin() + 11);
	cout << "v1.size = " << v1.size() << " " << v1.capacity() << endl;
	cout << "v1 = ";
	CoutVector(v1);
}


int main()
{
	test_vector_insert();
	//test_vector_erase();
    system("pause");
    return 0;
}