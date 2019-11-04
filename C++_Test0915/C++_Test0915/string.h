#pragma once
#include<iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS 1
#define CAPACITY 16
using namespace std;
typedef char * iterator;
class String
{
private:
	char *m_data;
	size_t m_size;
	size_t m_capacity;
public:
	String(const char ch);
	String(const char* str = "");
	String(const String &s);
	String(size_t n, char ch);
	~String();
	size_t size();
	size_t capacity();
	void ReCapacity(size_t size);
	const char *c_str();
	void reserve(size_t n);
	void resize(size_t n,char ch = '\n');
	bool empty();
	bool clear();
	typedef char * iterator;
	iterator Begin();
	iterator End();
	void push_back(char ch);
	char operator [](int pos);
	const char operator [](int pos)const;
	String operator =(char ch);
	String operator =(const char* str);
	String operator =(const String& s);
	String operator +=(char ch);
	String operator +=(const char* str);
	String operator +=(const String& s);
	String append(size_t n,char ch);
	String append(const char* str);
	String append(const String& s);
	size_t find(char ch, size_t pos);
	size_t find(const char* str, size_t pos);
	size_t find(const String& s, size_t pos);
	size_t rfind(char ch, size_t pos);
	size_t rfind(const char* str, size_t pos);
	size_t rfind(const String& s, size_t pos);
	String substr(size_t start, size_t num);
	friend ostream& operator <<(ostream &os, String& s);
	friend istream& operator >>(istream &is, String& s);
};
