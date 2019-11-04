#include"String.h" 
String::String(const char ch)
{
	m_size = 1;
	m_capacity = CAPACITY;
	m_data = new char[m_capacity];
	m_data[m_size - 1] = ch;
}
String::String(const char* str)
{
	if (str == NULL)
	{
		str = "";
	}
	m_size = strlen(str);
	m_capacity = CAPACITY * ((m_size / CAPACITY) + 1);
	m_data = new char[m_capacity];
	strncpy(m_data, str,m_size);
}
String::String(const String &s)
{
	m_size = s.m_size;
	m_capacity = CAPACITY * ((m_size / CAPACITY) + 1);
	m_data = new char[m_capacity];
	strncpy(m_data, s.m_data, m_size);
}
String::String(size_t n, char ch)
{
	m_size = n;
	m_capacity = CAPACITY * ((m_size / CAPACITY) + 1);
	m_data = new char[m_capacity];
	memset(m_data, ch, m_size);
}
String::~String()
{
	if (m_data)
	{
	    delete[]m_data;
		m_data = NULL;
	}
	m_size = 0;
	m_capacity = 0;
}

void String::ReCapacity(size_t size)
{
	m_capacity = CAPACITY * ((size / CAPACITY) + 1);
	m_data = (char*)realloc(m_data, m_capacity);
}

ostream& operator <<(ostream &os, String &s)
{
	for (int i = 0; i < s.m_size; i++)
	{
		os << s.m_data[i];
	}
	os << endl;
	return os;
}

istream& operator >>(istream &is, String& s)
{
	char *tmp = new char[1024];
	is.getline(tmp, 1024);
	s.m_size = strlen(tmp);
	s.ReCapacity(s.m_size);
	strcpy(s.m_data, tmp);
	tmp = NULL;
	return is;
}

const char * String::c_str()
{
	return m_data;
}

size_t String::length()
{
	return m_size;
}

size_t String::size()
{
	return m_size;
}

size_t String::capacity()
{
	return m_capacity ? m_capacity - 1 : m_capacity;
}

void String::reserve(size_t n)
{
	ReCapacity(n);
}

void String::resize(size_t n, char ch)
{
	ReCapacity(n);
	if (m_size < n)
	{
		memset((m_data + m_size), ch, n - m_size);
	}
	m_size = n;
}

bool String::empty()
{
	return m_size > 0;
}

void String::clear()
{
	m_size = 0;
	m_capacity = 0;
}

Iterator String::Begin()
{
	return m_data;
}

Iterator String::End()
{
	return (m_data + m_size);
}

void String::push_back(char ch)
{
	ReCapacity(m_size + 1);
	m_size += 1;
	m_data[m_size - 1] = ch;
}

void String::pop_back()
{
	m_size--;
}

char String::operator [](int pos)
{
	return m_data[pos];
}

const char String::operator [](int pos)const
{
	return m_data[pos];
}

String& String::operator =(char ch)
{
	ReCapacity(1);
	m_size = 1;
	m_data[m_size - 1] = ch;
	return *this;
}

String& String::operator =(const char* str)
{
	m_size = strlen(str);
	ReCapacity(m_size);
	strcpy(m_data, str);
	return *this;
}

String& String::operator =(const String& s)
{
	m_size = s.m_size;
	ReCapacity(m_size);
	strncpy(m_data, s.m_data,m_size);
	return *this;
}

String& String::operator +=(char ch)
{
	m_size += 1;
	ReCapacity(m_size);
	m_data[m_size - 1] = ch;
	return *this;
}

String& String::operator +=(const char* str)
{
	m_size += strlen(str);
	ReCapacity(m_size);
	strcpy(m_data + (m_size - strlen(str)), str);
	return *this;
}

String& String::operator +=(const String& s)
{
	m_size += s.m_size;
	ReCapacity(m_size);
	strncpy((m_data + (m_size - s.m_size)), s.m_data, s.m_size);
	return *this;
}

String String::operator + (const char * str) const
{
	String tmp(*this);
	if (str == NULL)
	{
		return tmp;
	}
	tmp.m_size += strlen(str);
	tmp.ReCapacity(tmp.m_size);
	strcpy(tmp.m_data + m_size, str);
	return tmp;
}

String String::operator + (const String &s) const
{
	String tmp(*this);
	tmp.m_size += s.m_size;
	tmp.ReCapacity(tmp.m_size);
	strncpy(tmp.m_data + m_size, s.m_data,s.m_size);
	return tmp;
}

String operator +(const char * str, const String &s)
{
	String tmp;
	if (str == NULL)
	{
		return tmp;
	}
	tmp.m_size = (strlen(str)+s.m_size);
	tmp.ReCapacity(tmp.m_size);
	strcpy(tmp.m_data , str);
	strncpy(tmp.m_data + strlen(str), s.m_data, s.m_size);
	return tmp;
}

bool String::operator >  (const char * str) const
{
	/*m_data[m_size] = '\0';         
	return(strcmp(m_data, str) > 0);*///越界改值较方便，但不太好
	return (strncmp(m_data, str, m_size) > 0);
	
}

bool String::operator <  (const char * str) const
{
	//m_data[m_size] = '\0';
	//return (strcmp(m_data, str) < 0);
	int res = strncmp(m_data, str, m_size);
	if(!res && strlen(str)>m_size)
	{
		return true;
	}
	return res > 0;
}

bool String::operator >= (const char * str) const
{
	return !(*this < str);
}

bool String::operator <= (const char * str) const
{
	return !(*this > str);
}

bool String::operator == (const char * str) const
{
	/*m_data[m_size] = '\0';
	return (strcmp(m_data, str) == 0);*/
	int res = strncmp(m_data, str, m_size);
	if (!res && strlen(str) == m_size)
	{
		return true;
	}
	return false;
}

bool String::operator != (const char * str) const
{
	return !(*this == str);
}

bool String::operator >  (const String &s) const
{
	/*m_data[m_size] = '\0';
	return (strcmp(m_data, s.m_data) > 0);*/
	return (strncmp(m_data, s.m_data, m_size) > 0);
}

bool String::operator <  (const String &s) const
{
	/*m_data[m_size] = '\0';
	return (strcmp(m_data, s.m_data) < 0);*/
	int res = strncmp(m_data, s.m_data, m_size);
	if (!res && s.m_size > m_size)
	{ 
		return true;
	}
	return res > 0;
}

bool String::operator >= (const String &s) const
{ 
	return !(*this < s);
}

bool String::operator <= (const String &s) const
{
	return !(*this > s);
}

bool String::operator == (const String &s) const
{
	/*m_data[m_size] = '\0';
	return (strcmp(m_data, s.m_data)== 0);*/
	int res = strncmp(m_data, s.m_data, m_size);
	if (!res && s.m_size == m_size)
	{
		return true;
	}
	return false;
}
bool String::operator != (const String &s) const
{
	return !(*this == s);
}

bool operator >  (const char * str, const String &s)
{
	int ret = strncmp(str, s.m_data, s.m_size) > 0;
	if (!ret && strlen(str) > s.m_size)
	{
		return true;
	}
	else
	{
		return ret > 0;
	}
}

bool operator <  (const char * str, const String &s)
{
	return (strncmp(str, s.m_data, s.m_size) < 0);
}

bool operator >= (const char * str, const String &s)
{
	return !(str < s);
}

bool operator <= (const char * str, const String &s)
{
	return !(str > s);
}

bool operator == (const char * str, const String &s)
{
	int ret = strncmp(str, s.m_data, s.m_size);
	if (!ret && strlen(str) == s.m_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator != (const char * str, const String &s)
{
	return !(str == s);
}

String& String::append(size_t n, char ch)
{
	m_size += n;
	ReCapacity(m_size);
	memset((m_data + (m_size - n)), ch, n);
	return *this;
}

String& String::append(const char* str)
{
	m_size += strlen(str);
	ReCapacity(m_size);
	strcpy((m_data + (m_size - strlen(str))), str);
	return *this;
}

String& String::append(const String& s)
{
	m_size += s.m_size;
	ReCapacity(m_size);
	strncpy((m_data + (m_size - s.m_size)), s.m_data,s.m_size);
	return *this;
}


size_t String::find(char ch, size_t pos)
{
	if (pos < 0 || pos >= m_size)
	{
		return -1;
	}
	char *tmp = strchr(m_data + pos, ch);
	return tmp ? tmp - m_data : -1;
}

size_t String::find(const char* str, size_t pos)
{
	if (pos < 0 || pos >= m_size)
	{
		return -1;
	}
	char *tmp = strstr(m_data + pos, str);
	return tmp ? tmp - m_data : -1;
}

size_t String::find(const String& s, size_t pos)
{
	if (pos < 0 || pos >= m_size)
	{
		return -1;
	}
	char *tmp = strstr(m_data + pos, s.m_data);
	return tmp ? tmp - m_data : -1;
}

size_t String::rfind(char ch, size_t pos)
{
	if (pos < 0 || pos >= m_size)
	{
		return -1;
	}
	char *tmp = strrchr(m_data + pos, ch);
	return tmp ? tmp - m_data : -1;
}

size_t String::rfind(const char* str, size_t pos)
{
	if (pos < 0 || pos >= m_size)
	{
		return -1;

	}
	char res = m_data[pos + 1] ;
	m_data[pos + 1] = '\0'; 
	char *tmp = strstr(m_data, str);
	m_data[pos + 1] = res;
	return tmp ? tmp - m_data : -1;
}

size_t String::rfind(const String& s, size_t pos )
{
	if (pos < 0 || pos > m_size)
	{
		return -1;
	}
	char res1 = m_data[pos + 1];
	char res2 = s.m_data[s.m_size];
	m_data[pos + 1] = '\0';
	s.m_data[s.m_size] = '\0';
	char *tmp = strstr(m_data, s.m_data);
	m_data[pos + 1] = res1;
	s.m_data[s.m_size] = res2;
	return tmp ? tmp - m_data : -1;
}

String String::substr(size_t start, size_t num)
{
	String tmp;
	if (start < 0 || start >= m_size || num < 0 || num>m_size)
	{	
		return tmp;
	}
	tmp.m_size = num;
	if (tmp.m_size >= tmp.m_capacity)
	{
		tmp.ReCapacity(tmp.m_size);
	}
	strncpy(tmp.m_data, m_data + start, num);
	return tmp;
}
