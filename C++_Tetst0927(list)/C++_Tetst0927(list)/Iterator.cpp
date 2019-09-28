#include"Iterator.h"

template<class T>//前中后元素类型可不一致
T& ListIterator<T>::operator*()
{
	return m_pNode->m_val;
}

template<class T>
T* ListIterator<T>::operator->()
{
	return &(operator*());
}

template<class T>
Self& ListIterator<T>::operator++()
{
	_pNode = _pNode->_pNext;
	return *this;
}

template<class T>
Self ListIterator<T>::operator++(int)
{
	Self temp(*this);
	_pNode = _pNode->_pNext;
	return temp;
}

template<class T>
Self& ListIterator<T>::operator--();

template<class T>
Self& ListIterator<T>::operator--(int);

template<class T>
bool ListIterator<T>::operator!=(const Self& l)
{
	return _pNode != l._pNode;
}

template<class T>
bool ListIterator<T>::operator==(const Self& l)
{
	return _pNode != l._pNode;
}
