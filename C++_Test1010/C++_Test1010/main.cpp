#include<iostream>
using namespace std;
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<cctype>
#include<cstdlib>
//1.给定一个二叉树，返回它的前序遍历。
//template<class T>
//class TreeNode
//{
//private:
//	T m_data;  //存储此节点的数据
//	TreeNode* m_lchild;  //存储左孩子的地址
//	TreeNode* m_rchild; //存储右孩子的地址
//public:
//	TreeNode() :
//		m_lchild(nullptr),
//		m_rchild(nullptr)
//	{}
//
//	TreeNode*  push(T* src);
//	//通过前序遍历的数组"ABDG##H#J###CE##FI###"构建二叉树
//	{
//		static int s_n = 0;//定义静态变量记录数组下标
//		if (src[s_n] == '#')//
//		{
//			s_n++;//下标+1，递归进入直接访问下一个
//			return nullptr;
//		}
//		TreeNode* cur = new TreeNode();
//		cur->_data = src[s_n];
//		s_n++;//下标+1，递归进入直接访问下一个
//		cur->lchild = BinaryTreeCreate(src);//左右孩子递归访问
//		cur->rchild = BinaryTreeCreate(src);
//		return cur;
//	}
//
//	~TreeNode()
//	{
//		if (root != NULL)
//		{
//			BinaryTreePostOrder(root->lchild);
//			BinaryTreePostOrder(root->rchild);
//			free(root);
//		}
//	}
//};
//class Solution 
//{
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//
//	}
//};


//vector<int> preorderTraversal(TreeNode* root)
//{
//	vector
//		static int count = 1;
//	if (count == 1)
//	{
//		cout << "[";
//	}
//
//	if (root)
//	{
//
//		count++;
//		cout << root->val;
//		if (root->left || root->right)
//		{
//			cout << ",";
//		}
//		preorderTraversal(root->left);
//		preorderTraversal(root->right);
//		cout << "]" << endl;
//	}
//}
int main1()
{
	system("pause");
	return 0;
}//



//2.根据逆波兰表示法，求表达式的值。
//
//有效的运算符包括 + , -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//
//说明：
//
//
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//
//
//示例 1：
//
//输入 : ["2", "1", "+", "3", "*"]
// 输出 : 9
//  解释 : ((2 + 1) * 3) = 9
//
//
//	   示例 2：
//
//   输入 : ["4", "13", "5", "/", "+"]
//	输出 : 6
//	 解释 : (4 + (13 / 5)) = 6
//
//
//	示例 3：
//
//	  输入 : ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//	   输出 : 22
//		解释 :
//		   ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//		   = ((10 * (6 / (12 * -11))) + 17) + 5
//		   = ((10 * (6 / -132)) + 17) + 5
//		   = ((10 * 0) + 17) + 5
//		   = (0 + 17) + 5
//		   = 17 + 5
//		   = 22


class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> tmp;
		int num1, num2;
		for (auto& i : tokens)
		{
			if (isdigit(i[0]) || i.size() > 1)
			{
				tmp.push(atoi(i.c_str()));
			}
			else
			{
				num1 = tmp.top();
				tmp.pop();
				num2 = tmp.top();
				switch (i[0])
				{
				case '+':
					tmp.top() = num2 + num1;
					break;
				case '-':
					tmp.top() = num2 - num1;
					break; 
				case '*':
					tmp.top() = num2 * num1;
					break; 
				case '/':
					tmp.top() = num2 / num1;
					break;
				}
			}
		}
		return tmp.top();
	}
};

int main()
{
	vector<string> vs{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution Solute;
	cout << Solute.evalRPN(vs) << endl;
	system("pause");
	return 0;
}