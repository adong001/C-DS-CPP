#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//给定一个二叉树，返回其节点值自底向上的层次遍历。 
//（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//例如：
//给定二叉树[3, 9, 20, null, null, 15, 7],
//
//3
/// \
//9  20
/// \
//15   7
//
//
//返回其自底向上的层次遍历为：
//
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]
//


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x),
		left(NULL),
		right(NULL)
	{}
};
//1.二叉树层序遍历
class Solution {
public:
	vector<vector<int>> levelOrderBottom1(TreeNode* root)
	{
		vector<vector<int>> vres;
		queue<TreeNode*> qu;
		TreeNode* cur = root;

		int level;//层数
		if (!root)
		{
			return vres;
		}

		qu.push(cur);

		for (level = 0; !qu.empty(); level++)//层
		{
			int len = qu.size();
			vres.push_back(vector<int>());
			for (int i = 0; i < len; i++)//len为每一层的个数
			{
				
				vres[level].push_back(cur->val);
				if (cur->left)//先看左孩子存在->入队
				{
					qu.push(cur->left);
				}

				if (cur->right)//再看右孩子存在->入队
				{
					qu.push(cur->right);
				}
				qu.pop();//pop掉，下次访问后面的元素
				if (!qu.empty())
				{
					cur = qu.front();//取队首
				}
			}
		}

		vector<vector<int>> vtmp;//将而二叉树从最后一层向上赋值给vtmp
		for (int i = level - 1; i >= 0; i--)
		{
			vtmp.push_back(vector<int>());
			for (int j = 0; j < vres[i].size(); j++)
			{
			
				vtmp[vres.size() - i - 1].push_back(vres[i][j]);
			}
		}

		for (int i = 0; i < level; i++)
		{
			cout << "[";
			for (int j = 0; j < vtmp[i].size(); j++)
			{
				cout << vtmp[i][j];
				if (j < vtmp[i].size() - 1)
				{
					cout << ",";
				}
			}
			cout << "]" << endl;
		}
		return vtmp;//返回镜像的二叉树
	}
};

int main1()
{
	TreeNode* root = new TreeNode(100);
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(17);
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
	Solution su;
	vector<vector<int>> iv;
	iv = su.levelOrderBottom1(root);
	system("pause");
	return 0;
}