#ifndef _BTREE_H_
#define _BTREE_H_
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef char BTDataType;

typedef struct BinaryTreeNode 
{  BTDataType _data;  
   struct BinaryTreeNode* lchild;  
   struct BinaryTreeNode* rchild; 
}BTNode;


BTNode* BinaryTreeCreate(BTDataType* src);//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树

void BinaryTreeDestory(BTNode* root);//销毁二叉树

int BinaryTreeSize(BTNode* root);//求树的节点个数

int BinaryTreeLeafSize(BTNode* root);//求树的叶子节点个数

int BinaryTreeLevelKSize(BTNode* root, int k);//求第K层节点数

BTNode* BinaryTreeFind(BTNode* root, BTDataType x); //查找树某个值

int BinaryTreeDeep(BTNode* root);//求树的深度

// 遍历
void BinaryTreePrevOrder(BTNode* root); //先序遍历

void BinaryTreeInOrder(BTNode* root);//中序遍历

void BinaryTreePostOrder(BTNode* root);//后序遍历


void BinaryTreeLevelOrder(BTNode* root);// 层序遍历

int BinaryTreeComplete(BTNode* root); // 判断二叉树是否是完全二叉树

// 非递归遍历 
void BinaryTreePrevOrderNonR(BTNode* root);//先序遍历

void BinaryTreeInOrderNonR(BTNode* root);//中序遍历

void BinaryTreePostOrderNonR(BTNode* root);//后序遍历

void TestBinaryTree();

#endif
