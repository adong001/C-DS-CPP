#pragma once
template<class T>
class ListNode //½ÚµãÀà
{
private:
	ListNode<T>* m_pPre;
	ListNode<T>* m_pNext;
	T m_val;
public:
	ListNode(const T& val = T()) :
		m_pPre(nullptr),
		m_pNext(nullptr),
		m_val(val)
	{}
	friend list;
};