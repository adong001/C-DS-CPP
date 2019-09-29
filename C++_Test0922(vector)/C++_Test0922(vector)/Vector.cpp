//#include"Vector.h"
//using namespace Bit;
//
//template<class T>
//vector<T>::iterator begin()
//{
//	return m_start;
//}
//
//template<class T>
//vector<T>::iterator end()
//{
//	return m_finsh;
//}
//
//template<class T>
//vector<T>::c_iterator c_begin()const
//{
//	return m_start;
//}
//
//template<class T>
//vector<T>::c_iterator c_end()const
//{
//	return m_finsh;
//}
//
//template<class T>
//size_t vector<T>::size()
//{
//	return m_end - m_start;
//}
//
//template<class T>
//size_t vector<T>::capacity()
//{
//	return m_endOfStorage - m_start;
//}
//
//
//template<class T>
//void vector<T>::reserve(size_t _size)//Ö»À©²»Ëõ
//{
//	int capacity = m_endOfStorage - start;
//	T* tmp;
//	if (capacity < _size)
//	{
//		if (capacity == 0)
//		{
//			capacity = 1;
//		}
//		while (capacity < _size)
//		{
//			capacity *= 2;
//		}
//
//		tmp = new T[capacity];
//		memncpy(tmp, m_start, size());
//		m_end = tmp + size();
//		delete[]m_start;
//		m_start = tmp;
//		m_endOfStorage = tmp + _size;
//	}
//}

/*c_iterator c_begin(){ }
c_iterator c_begin(){ }
size_t size(){ }
size_t capacity(){ }
void reserve(size_t _size){ }
void resize(size_t _size, const T &val = T()){ }
T & operator [] (int i){ }
const T & operator [] (int i) const{ }
void push_back(const T &val){ }
void pop_back(){ }
iterator insert(iterator pos, const T &val){ }
iterator insert(iterator pos, int n, const T &val){ }
iterator insert(iterator pos, const T * start, const T * end){ }
iterator erase(iterator pos){ }
iterator erase(iterator start, iterator end){ }*/
