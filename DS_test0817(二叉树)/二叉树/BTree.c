#include"BTree.h"
#include"Queue.h"
#include"stack.h"


BTNode* BinaryTreeCreate(BTDataType* src)//创建二叉树
{
	static int s_n = 0;
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode *cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreate(src);
	cur->rchild = BinaryTreeCreate(src);
	return cur;
}

void BinaryTreeDestory(BTNode* root)//后序遍历销毁
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		free(root);
	}
}

int BinaryTreeDeep(BTNode* root)//求树深度
{
	if (root == NULL) //次节点为空返回0
	{
		return 0;
	}
	int LeftlChildDeth = BinaryTreeDeep(root->lchild);//递归进入左孩子
	int RightChildDeth = BinaryTreeDeep(root->rchild);//递归进入右孩子
	return LeftlChildDeth > RightChildDeth ? LeftlChildDeth + 1 : RightChildDeth + 1;
	//左右孩子都为空则return 0+1（以度为2的树为例）
    //左孩子为空，右孩子不为空，则return 1+1
	//左孩子不为空，右孩子为空，则return 1+1
	//左右孩子都不为空，则return 1+1
}

int BinaryTreeSize(BTNode* root)//求节点个数
{
	int count = 0;
	BTNode *cur = root;
	if (cur == NULL)
	{
		return 0;
	}
	count++;
	count += BinaryTreeSize(cur->lchild);
	count += BinaryTreeSize(cur->rchild);
	return count;
}

int BinaryTreeLeafSize(BTNode* root)//求叶子节点个数
{
	int count = 0;
	BTNode *cur = root;
	if (cur == NULL)
	{
		return 0;
	}
	if (cur->lchild == NULL && cur->rchild == NULL)
	{
		count++;
		return count;
	}
	count += BinaryTreeLeafSize(cur->lchild);
	count += BinaryTreeLeafSize(cur->rchild);
	return count;
}

//int BinaryTreeLevelKSize(BTNode* root, int k)//求出第K层节点个数(非递归)
//{
//	assert(root);
//	if (k < 1 ||  k > BinaryTreeDeep(root))//判断输入的层数是否合法
//	{
//		return 0;
//	}
//	if (k == 1)//若求第一层，由第一行可知，程序能执行到这一步，说明根节点存在，第一层只有一个根节点返回1
//	{
//		return 1;
//	}	
//	Dequeue qu;//定义一个队列变量
//	BTNode *cur;//二叉树的中间变量
//	int flag = 1;
//	int ret = 1;//计数这层的节点个数，做为下一层的循环次数（第一次初始化为1，加完左右孩子后减掉）
//	dequeueInit(&qu);
//	dequeuePush(&qu, root);//根节点先入队
//	while (k - 2 > 0)//根已入，循环k-2次到k-1层，输出k-1层的所有节点的左右孩子即为本函数的目的(这个while只求出k-1层节点的个数)
//	{
//		int tmp = ret;//中间变量tmp,记录ret的值(上一层节点个数)作为循环次数,数出下层节点个数
//		for (int i = 0; i < tmp;i++)//通过ret记录的上层节点个数
//		{
//			cur = dequeueTop(&qu);//取队首
//			if (cur->lchild)//左孩子存在，左孩子入队，并记录这一层次节点的孩子数
//			{
//				dequeuePush(&qu, cur->lchild);
//				ret++;
//			}
//			if (cur->rchild)//右孩子存在，右孩子入队，并记录这一层次节点的孩子数
//			{
//				dequeuePush(&qu, cur->rchild);
//				ret++;
//			}
//			if (flag)//第一次进入ret--，否则循环不能进入，所以第二层节点个数为ret=1+1+1-1=2(根节点的左右孩子都存在)
//			{
//				ret--;
//				flag = 0;
//			}
//			dequeuePop(&qu);//根节点出队。
//		} 
//		k--;
//	}
//	int count = 0;//第K层节点个数
//	while (dequeueIsEmpty(&qu))//队列不为空
//	{
//		cur = dequeueTop(&qu);//取队首
//		if (cur->lchild)//左孩子存在count++
//		{
//			count++;
//		}
//		if (cur->rchild)//右孩子存在count++
//		{
//			count++;
//		}
//		dequeuePop(&qu);//队首出队
//
//	}
//	dequeueDestory(&qu);
//	return count;
//}//
int BinaryTreeLevelKSize(BTNode* root, int k)//求出第K层节点个数
{
	static int i = 1, size;//，定义两个静态变量记录树的层数，防止每次递归都调用BinaryTreeDeep函数，大大减小了栈的开辟
	if (i)
	{
		size = BinaryTreeDeep(root);
		i = 0;
	}
	if (k < 1 || k >size || root == NULL)//判断输入的层数和次节点是否合法
	{
		return 0;
	}
	if (k == 1)//若求第一层，由第一行可知，程序能执行到这一步，说明根节点存在，第一层只有一个根节点返回1
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->lchild, k - 1) + BinaryTreeLevelKSize(root->rchild, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode *cur = NULL;
	if (root != NULL)
	{
		if (root->_data == x)
		{
			return root;
		}
		cur = BinaryTreeFind(root->lchild, x);
		cur = BinaryTreeFind(root->rchild, x);
	}
	return cur;
}



// 遍历
void BinaryTreePrevOrder(BTNode* root)//先序遍历
{
	if (root != NULL)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}
void BinaryTreeInOrder(BTNode* root)//中序遍历
{
	if (root != NULL)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->_data);
		BinaryTreeInOrder(root->rchild);
	}
}

void BinaryTreePostOrder(BTNode* root)//后序遍历
{
	if (root != NULL)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->_data);
	}
}

// 非递归遍历 // 
void BinaryTreeLevelOrder(BTNode* root)// 层序遍历
{
	Dequeue qu;
	BTNode *cur;
	dequeueInit(&qu);
	dequeuePush(&qu, root->_data);
	while (dequeueIsEmpty(&qu))
	{
		cur = dequeueTop(&qu);
		putchar(cur->_data);
		if (cur->lchild)
		{
			dequeuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			dequeuePush(&qu, cur->rchild);
		}
		dequeuePop(&qu);
	}
	dequeueDestory(&qu);
}
 
int BinaryTreeComplete(BTNode* root)//判断是否为完全二叉树
{

	Dequeue qu;
	BTNode *cur;
	dequeueInit(&qu);
	int tag = 0;
	dequeuePush(&qu, root);
	while (dequeueIsEmpty(&qu))
	{
		cur = dequeueTop(&qu);
		
		if (!cur->lchild && cur->rchild)
		{
			return 0;
		}
		if (tag && ((cur->lchild) || (cur->rchild)))
		{
			return 0;
		}
		if (cur->lchild)
		{
			dequeuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			dequeuePush(&qu, cur->rchild);
		}
		else
		{
			tag = 1;
		}
		dequeuePop(&qu);
	}
	dequeueDestory(&qu);
	return 1;	
}

void BinaryTreePrevOrderNonR(BTNode* root) // 先序遍历(非递归)
{
	Stack st;
	BTNode *cur = root;//从根开始
	StackInit(&st,100);
	while (cur)
	{
		putchar(cur->_data);
		cur = StackTop(&st);
		
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild)
		{
			cur = cur->lchild;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}
	}
	StackDestory(&st);
}

void BinaryTreeInOrderNonR(BTNode* root)// 中序遍历(非递归)
{
	Stack st;
	BTNode *cur = root;
	StackInit(&st, 100);
	while (1)
	{
		for (; cur; cur = cur->lchild)   
		{
			StackPush(&st, cur);
		}
		cur = StackTop(&st);
		putchar(cur->_data);
		StackPop(&st);
		cur = cur->rchild;
	}
	StackDestory(&st);
}

void BinaryTreePostOrderNonR(BTNode* root)// 后序遍历(非递归)
{
	char tag[64];
	Stack st;
	BTNode *cur = root;
	StackInit(&st, 100);
	
	do{
		for (; cur; cur = cur->lchild)
		{
			StackPush(&st, cur);
			tag[st._size - 1] = 0;
		}
		while (StackIsEmpty(&st) && tag[st._size - 1])
		{
			cur = StackTop(&st);
			putchar(cur->_data);
			StackPop(&st);
		}
		if (cur != NULL)
		{
			cur = StackTop(&st);
			tag[st._size - 1] = 1;
			cur = cur->rchild;
		}
	} while (StackIsEmpty(&st));
	StackDestory(&st);
}

void BinaryTreeTest()
{
	char src[] = "ABD##E#H##CF##G##";//AB##C##
	BTNode *cur;
	BTNode *root = BinaryTreeCreate(src);
	BinaryTreePrevOrder(root);
	putchar('\n');
	BinaryTreeInOrder(root);
	putchar('\n');
	BinaryTreePostOrder(root);
	putchar('\n');
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeSize(root));
	cur = BinaryTreeFind(root, 'C');
	if (cur == NULL)
	{
	printf("not Find\n");
	}
	else
	{
	printf("find value is %c\n", cur->_data);
	}
	printf("%d\n", BinaryTreeDeep(root));
	printf("%d\n", BinaryTreeComplete(root));
	printf("%d\n", BinaryTreeLevelKSize(root, 4));
	BinaryTreeDestory(root);
}