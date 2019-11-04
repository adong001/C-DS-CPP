#include"List.h"

template<class T>
List<T>::List() //构造空的list
{
	CreateHead();
}

template<class T>
List<T>::List(size_type n, const T& val = T())//构造的list中包含n个值为val的元素
{
	CreateHead();
	int i;
	for (i = 0; i < n; i++)
	{
		push_back(val);
	}

}

template<class T>
List<T>::List(const List& res) //拷贝构造函数
{
	List<T> temp(res.cbegin(), res.cend());
	this->swap(temp);
}

template<class T>
List<T>::List(Iterator ﬁrst, Iterator last) //用[ﬁrst, last]区间中的元素构造list
{
	CreateHead();
	while (first != last)
	{
		push_back(*first);
		++first;
	}
}

template<class T>
void List<T>::CreateHead()
{
	m_pHead = new m_Node;
	m_pHead->m_pPre = m_pHead;
	m_pHead->m_pNext = m_pHead;
}

template<class T>
void List<T>::push_back(const T& val)
{
	insert(begin(), val); 
}

template<class T>
List<T>::iterator List<T>::insert(iterator pos, const T& val)
{
	m_PNode pNewNode = new Node(val);         
	m_PNode pCur = pos.m_pNode;// 先将新节点插入             
	pNewNode->_pPre = pCur->_pPre;        
	pNewNode->_pNext = pCur;          
	pNewNode->_pPre->_pNext = pNewNode;    
	pCur->_pPre = pNewNode;          
	return iterator(pNewNode);       
}

template<class T>
List<T>::iterator List<T>::begin()
{ 
	return List<T>::iterator(m_pHead->m_pNext);
}

template<class T>
List<T>::iterator List<T>::end()
{
	return iterator(m_pHead->m_pPre);
}

template<class T>
List<T>::const iterator List<T>::cbegin()
{
	return const iterator(m_pHead->m_pNext);
}

template<class T>
List<T>::const iterator List<T>::cend()
{
	return const iterator(m_pHead->m_pPre);
}