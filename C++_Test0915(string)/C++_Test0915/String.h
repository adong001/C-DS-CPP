#pragma once
#include<iostream>
#include<cstring>
#include <algorithm>
#define _CRT_SECURE_NO_WARNINGS 1
#define CAPACITY 16
using namespace std;
typedef char * Iterator;
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
	size_t length();
	size_t size();
	size_t capacity();
	void ReCapacity(size_t size);
	const char *c_str();
	void reserve(size_t n);
	void resize(size_t n,char ch = ' ');
	bool empty();
	void clear();
	Iterator Begin();
	Iterator End();
	void push_back(char ch);
	void pop_back();
	char operator [](int pos);
	const char operator [](int pos)const;
	String& operator =(char ch);
	String& operator =(const char* str);
	String& operator =(const String& s);
	String& operator +=(char ch);
	String& operator +=(const char* str);
	String& operator +=(const String& s);
	String operator + (const char * str) const;
	String operator + (const String &s) const;
	friend String operator +(const char * str, const String &s);
	bool operator >  (const char * str) const;
	bool operator <  (const char * str) const;
	bool operator >= (const char * str) const;
	bool operator <= (const char * str) const;
	bool operator == (const char * str) const;
	bool operator != (const char * str) const;
	bool operator >  (const String &s) const;
	bool operator <  (const String &s) const;
	bool operator >= (const String &s) const;
	bool operator <= (const String &s) const;
	bool operator == (const String &s) const;
	bool operator != (const String &s) const;
	friend bool operator >  (const char * str, const String &s);
	friend bool operator <  (const char * str, const String &s);
	friend bool operator >= (const char * str, const String &s);
	friend bool operator <= (const char * str, const String &s);
	friend bool operator == (const char * str, const String &s);
	friend bool operator != (const char * str, const String &s);
	String& append(size_t n, char ch);
	String& append(const char* str);
	String& append(const String& s);
	size_t find(char ch, size_t pos = 0);
	size_t find(const char* str, size_t pos = 0);
	size_t find(const String& s, size_t pos = 0);
	size_t rfind(char ch, size_t pos);
	size_t rfind(const char* str, size_t pos);
	size_t rfind(const String& s, size_t pos);
	String substr(size_t start, size_t num);
	friend ostream& operator <<(ostream &os, String& s);
	friend istream& operator >>(istream &is, String& s);
};
