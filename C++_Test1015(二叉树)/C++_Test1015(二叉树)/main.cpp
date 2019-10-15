#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x),
		left(NULL),
		right(NULL)
	{}
};

class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		TreeNode* cur = root;
		vector<int> vres;
		stack<TreeNode*> stmp;
		if (!cur)
		{
			return vres;
		}

		stmp.push(cur);//把根先压进去

		do{
			vres.push_back(cur->val);

			if (cur->right)//右孩子存在，右孩子入栈
			{
				stmp.push(cur->right);
			}

			if (cur->left)//左孩子存在，左孩子的值push进容器中,左孩子入栈
			{
				stmp.push(cur->left);
			}

			cur = stmp.top();//取栈顶访问
			stmp.pop();//取完栈顶pop掉栈顶元素
		} while (cur != root);//出栈至只有一个根时，退出

		cout << "[";
		for (auto& i : vres)
		{
			cout << i << ",";
		}
		cout << "]";
		return vres;
	}
	vector<int> preorderTraversal2(TreeNode* root)//递归版
	{
		static vector<int> res;
		if (root)
		{
			res.push_back(root->val);
			preorderTraversal2(root->left);
			preorderTraversal2(root->right);
		}
		return res;
	}
	vector<int> inorderTraversal(TreeNode* root)
	{
		TreeNode* cur = root;
		vector<int> vres;
		stack<TreeNode*> stmp;

		if (!cur)
		{
			return vres;
		}
		stmp.push(cur);

		while (cur || !stmp.empty())//根和栈都为空时跳出
		{
			for (; cur && cur->left; cur = cur->left)//先把左孩子都入栈
			{
				stmp.push(cur->left);
			}

			if (!stmp.empty())//栈不为空，取栈顶，push进vres，并pop.
			{
				cur = stmp.top();
				vres.push_back(cur->val);
				stmp.pop();
			}

			else //若栈为空，说明树的根节点左孩子已访问完毕，直接给vres push进根的值，访问右孩子
			{
				vres.push_back(cur->val);
			}

			cur = cur->right;//进入左孩子
			if (cur) //右孩子入不为空，先把右孩子的根push进，否则
			{
				stmp.push(cur);
			}
		}

		cout << "[";
		for (auto& i : vres)
		{
			cout << i << ",";
		}
		cout << "]";
		return vres;

	}
	vector<int> inorderTraversal2(TreeNode* root)//递归版
	{
		static vector<int> vres;
		if (root)
		{
			inorderTraversal2(root->left);
			vres.push_back(root->val);
			inorderTraversal2(root->right);
		}
		return vres;
	}

};





int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* rootl = new TreeNode(2);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;
	TreeNode* rootll = new TreeNode(39);
	TreeNode* rootlr = new TreeNode(48);
	rootl->left = rootll;
	rootl->right = rootlr;
	TreeNode* rootlrl = new TreeNode(12);
	TreeNode* rootlrll = new TreeNode(43);
	rootlr->left = rootlrl;
	rootlrl->left = rootlrll;
	TreeNode* rootrl = new TreeNode(9);
	TreeNode* rootrr = new TreeNode(90);
	rootr->left = rootrl;
	rootr->right = rootrr;
	Solution s;
	vector<int> iv;
	//s.preorderTraversal(root);
	//iv = preorderTraversal2(root);
	//iv = s.inorderTraversal(root);
	iv = s.inorderTraversal2(root);
	for (auto& i : iv)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}//


