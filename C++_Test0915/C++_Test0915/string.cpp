#include"string.h" 
String::String(const char ch)
{
	m_size = 1;
	m_capacity = CAPACITY;
	m_data = new char[m_capacity];
	m_data[m_size-1] = ch;
}
String::String(const char* str )
{
	if (str == NULL)
	{
		str = "";
	}
	m_size = strlen(str);
	ReCapacity(m_size);
	strcpy(m_data, str);
}
String::String(const String &s)
{
	m_size = s.m_size;
	ReCapacity(m_size);
	strncpy(m_data, s.m_data,m_size);
}
String::String(size_t n, char ch)
{
	m_size = n;
	ReCapacity(m_size);
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
		os << s.m_data[i]<<" ";
	}
	os << endl;
	return os;
}

istream& operator >>(istream &is, String& s)
{
	char *tmp = new char[1024];
	fgets(tmp, 1024, stdin);
	s.m_size = strlen(tmp);
	s.ReCapacity(s.m_size);
	delete[]s.m_data;
	s.m_data = tmp;
	tmp = NULL;
}

const char * String::c_str()
{
	return m_data;
}