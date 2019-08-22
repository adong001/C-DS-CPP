#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"


void HeapInit(Heap* hp, HPDataType* a, int n)//堆的初始化
{
	assert(hp != NULL);
	hp->capacity = 2 * n;
	hp->size = n;
	hp->data = (HPDataType*)malloc(sizeof(HPDataType)*hp->size);
	int i;
	for (i = 0; i < n; i++)
	{
		hp->data[i] = a[i];
	}
	for (i = n/2; i >= 0; i--)//从第一个非叶子节点向上执行向下调整算法
	{
		AdjustDown(hp,i);
	}
}

void HeapDestory(Heap* hp)//销毁函数
{
	assert(hp != NULL);
	if (hp->data != NULL)
	{
		free(hp->data);
		hp->data = NULL;
	}
	hp->capacity = 0;
	hp->size = 0;
}
void HeapPush(Heap* hp, HPDataType x)//向堆中添加元素
{
	assert(hp != NULL);
	Heap *cur = hp;
	int i;
	hp->size++;//数组大小加1
	hp->data[hp->size] = x;//向数组尾添加数据
	for (i = (hp->size - 2 )/ 2; i >= 0; i--)//
	{
		AdjustDown(hp, i);
	}
}
void HeapPop(Heap* hp)//删除堆顶元素
//把最后一个叶子节点替换为堆顶，size--,再执行向下调整算法
{
	assert(hp != NULL);
	if (hp->size == 0)
	{
		return;
	}
	int tmp = hp->data[0];//交换数组首和尾的数据
	hp->data[0] = hp->data[hp->size - 1];
	hp->data[hp->size - 1] = tmp;
	hp->size--;//最大的那个元素就被删除
	AdjustDown(hp, 0);//再执行向下调整算法，得到一个新的堆
}

HPDataType HeapTop(Heap* hp)//判断堆是否为空，为空返回0，否则返回第一个元素
{
	assert(hp != NULL);
	if (hp->data == NULL)
	{
		return (HPDataType) 0;
	}
	return hp->data[0];
}

int HeapSize(Heap* hp)//计算堆的数据长度
{
	assert(hp != NULL);
	return hp->size;
}

int HeapEmpty(Heap* hp)//清空
{
	assert(hp != NULL);
	memset(&hp, 0, sizeof(HPDataType)* hp->size);
	hp->capacity = 0;
	hp->size = 0;
	return 1;
}

void HeapPrint(Heap* hp)//打印
{
	int i;
	int rn = 0;
	int bin = 1;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			bin *= 2; 
			rn += bin; 
		}
	}
	putchar('\n');
	putchar('\n');
}

void AdjustDown(Heap* hp, int num)//向下调整函数(大堆),此函数只能作用于num下标的节点
//   1.if ( 右孩子不存在)       
//        记录左孩子坐标(while循环做判断，此节点一定不会是叶子节点，并且左孩子一定存在)
//   2.else(左右孩子都存在)
//	       if ：左孩子>右孩子,记录左孩子坐标		
//         else :左孩子<=右孩子,记录右孩子坐标
//   3.if(此节点的值<过程1.2记录孩子值)       
//        则交换两者的值并记录被交换孩子的坐标，进入孩子节点，若这个节点不是叶子节点，继续循环(防止上次循环改变下面的小堆)
//     else        
//        break;
{
	int cur = num;//要往下调整的下标
	int n;
	while (cur * 2 + 1 < hp->size)//左孩子坐标不能越界
	{
		if (cur * 2 + 2 >= hp->size)//没有右孩子
		{
			n = cur * 2 + 1;//记录这个节点下标
		}
		else
		{
			if (hp->data[cur * 2 + 1] > hp->data[cur * 2 + 2])//有左右孩子且左孩子>右孩子
			{
				n = cur * 2 + 1;//记录左孩子下标
			}
			else//否则记录右孩子下标
			{
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur]< hp->data[n])//若此节点比记录的孩子值小，则交换两者的值
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;
			cur = n;//记录交换后的坐标，继续进行判断
		}
		else //根节点比孩子值大，不交换，函数结束
		{
			break;
		}
	}
}

void AdjustUp(Heap* hp,int num)//(从最后一个节点)向上调整函数
{
	int tmp = num;//要往上调整的坐标
	assert(hp != NULL);
	int i;
	int parent = (num - 1) / 2;
	while (parent > 0)
	{
		if (hp->data[parent] > hp->data[(parent - 1) / 2])
		{
			int tmp = hp->data[parent];
			hp->data[parent] = hp->data[(parent - 1) / 2];
			hp->data[(parent - 1) / 2] = tmp;
			parent = (parent - 1) / 2;//交换成功，定位到父节点，继续循环只直至到根节点。
		}
		else
		{
			break;
		}
	}
}


void HeapSort(Heap* hp)// 堆排序 
{
	assert(hp != NULL);
	int i;
	int tmp = hp->size;//记录堆的大小
	for (i = 0; i < hp->size; i++)
	{
		HeapPop(hp);//堆第一个元素最大，不停出堆直至所有元素结束
	}
	hp->size = tmp;//数组元素实际上并没有删除，只是把size减到0了,排好序后，
	//重新给size赋原值，数组大小又恢复，但排好序后，这个数组就不再是堆了，只是一个有序的数组
}

void TestHeap()
{
	int data[] = { 1, 5, 3, 8, 7, 6 };
	Heap hp;
	HeapInit(&hp, data, 6);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPush(&hp, 8);
	HeapPrint(&hp);
	AdjustUp(&hp,5);
	HeapPrint(&hp);
	system("pause");
	return 0;
}


