#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//1.实现strcpy
char* my_strcpy(char* str, const char* soure)
{
	char* dest = str;
	assert(dest != NULL && soure != NULL);
	while (*dest++ = *soure++);
	return str;
}
//2.实现strcat
char* my_strcat(char* str, const char* soure)
{
	char* dest = str;
	assert(dest != NULL && soure != NULL);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *soure++);
	return str;
}
//3.实现strstr

char * my_strstr(const char *str1, const char *str2)
{
	char* p = str1;
	char* t = str2;
	char *q ;
	assert(p != NULL && t != NULL);
	if (*t == '\0')
	{
		return NULL;
	}
	while (*p)
	{
		q = p;//q指针标记p的初始位置，找到就返回他
		while (*p && *t && *t == *p)//str1和str2都没找完且找到相等字符，指针移动
		{
			p++;
			t++;
		}
		if (*t == '\0')//正好找到
		{
			return q;
		}
		p++;//此次循环没找到,继续进入下一轮寻找
	}
}

//4.实现strchr
char *my_strchr(const char *src, char value)
{
	assert(src != NULL);
	if (value == '\0')
	{
		return NULL;
	}
	while (*src && (*src != value))
	{
		src++;
	}
	if (src != '\0')
	{
		return src;
	}
	return NULL;

}
//strtok
//char * strtok(char * str, const char * sep);
//sep参数是个字符串，定义了用作分隔符的字符集合
//第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。 
//strtok函数找到str中的下一个标记，并将其用 \0 结尾，返回一个指向这个标记的指针。
//（注：strtok函数会 改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
//strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
//strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
//如果字符串中不存在更多的标记，则返回 NULL 指针。
//strerror
//char * strerror(int errnum)
//#include <errno.h>//必须包含的头文件
//5.实现strcmp
size_t my_strcmp(const char* str1, const char* str2)
{
	const unsigned char* src1 = (const unsigned char*)str1;
	//强转成const unsigned char* 是为了下面两个指针的值的ascii相减
	const unsigned char* src2 = (const unsigned char*)str2;
	int ret = 0;
	assert(src1 != NULL && src2 != NULL);
	while (!(*src1 - *src2) && *src2)//如果两个值不相等或*src2的ascii为0,
	{//(*src1-*src2,所以如果*src2的ascii的值为0,那*src1就比*src2大或相等,显然结果就已知了,退出循环）,
		//就继续判断, 否则，求出相减的值并退出循环
		src1++, src2++;
	}
	ret = (*src1 - *src2);
	if (ret < 0)
	{
		return -1;
	}
	else if (ret>0)
	{
		return 1;
	}
	return (ret);
}
//6.实现memcpy
void *my_memcpy(void *dest, const void *src, size_t num)
{
	char *str1 = (char *)dest;//应为此函数要将dest的n个字节copy给dest
	char *str2 = (char *)src;//所以先强转为char*
	assert(dest != NULL && dest != NULL);//使用assert断言，防止传空指针
	while (num--)
	{
		*str1++ = *str2++;//切记不能把此条语句放入while()中,其他类型强转成char*
	}//时之间可能会存有'\0'的字节，会导致while的结束
	return dest;
}
//从源dest所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中
//7.实现memmove
void *my_memmove(void * dest, const void * src, size_t num)
{
	char *str1 = (char*)dest;//定一两个char*指向要处理的两个字符串的首地址
	char *str2 = (char*)src;//memmove是字节移动函数，必须强转为char*；
	assert(str1 != NULL&&str2 != NULL);//遇见指针先断言
	if (str1 <= str2 || str1 >= str2 + num)//以下就是对于内存重叠时和memcpy的不同之处，
	{//分为三种情况，第一种：dest在低地址（一串字符串从左到右地址由高到低），dest在高地址
	 //从左到右一次移动就好，不会发生内存重叠。第二种：dest在高地址，dest在低地址，
	 //但要移动的长度不足以使其反生内存重叠。
		*str1++ = *str2++;
	}
	else//第三种：dest在高地址，dest在低地址，移动的长度正好会发生内存重叠
	{//解决方法就是由原来的从左到右移动改为从右向左移动，先把内存重叠区域的
     //字符移动走，就不会被高地址的覆盖掉。
		str1 += num - 1;//str1和str2先移动到内存重叠区域的最后一个字符上
		str2 += num - 1;
		while (num--)
		{//依次从左向右赋值
			*str1-- = *str2--;
		}
	}
}
int main() 
{ 
	char str[] = "- This, a sample string.";
	char * pch;
	printf("Splitting string \"%s\" into tokens:\n", str); 
	pch = strtok(str, " ,.-"); 
	while (pch != NULL) 
	{ printf("%s\n", pch); 
	pch = strtok(NULL, " ,.-"); 
	}  
   return 0;
}
char *my_strncpy(char* str, const char* soure, size_t n)//把dest所指字符串的前n个字符添加
{
	char *dest = str;
	assert(str != NULL && soure != NULL);//注意如果assert中的值为0时直接会终止掉程序
	while ((n-- > 0) && (*dest++ = *soure++));//相比strcpy函数多了一个只copy前n个字符。
	return str;
}
int my_strncmp(const char* str1, const char* str2, size_t n)//比较两个字符串前n个字符
{
	const unsigned char* src1 = (const unsigned char*)str1;
	//强转成const unsigned char* 是为了下面两个指针的值的ascii相减
	const unsigned char* src2 = (const unsigned char*)str2;
	int ret = 0;
	assert(src1 != NULL && src2 != NULL);
	while (!(*src1 - *src2) && *src2 && n > 0)//如果两个值不相等或*src2的ascii为0,
	{//(*src1-*src2,所以如果*src2的ascii的值为0,那*src1就比*src2大或相等,显然结果就已知了,退出循环）,
		//就继续判断, 否则，求出相减的值并退出循环
		src1++, src2++, n--;
	}
	ret = (*(--src1) - *(--src2));//比较n个字符指针移动到了n+1个位置，-1返回n的范围内
	if (ret < 0)
	{
		return -1;
	}
	else if (ret>0)
	{
		return 1;
	}
	return (ret);
}

void *my_memset(void *dest, int value, size_t count)
{
	char *tmp = (char*)dest;
	assert(tmp != NULL);
	while (count--)
	{
		*tmp++ = value;
	}
	return dest;
}
int my_memcmp(const void * ptr1, const void * ptr2, size_t num)
{
	unsigned char* str1 = (unsigned char*)ptr1;
	unsigned char* str2 = (unsigned char*)ptr2;
	int  ret;
	if (!num)
	{
		return 0;
	}
	assert(str1 != NULL && str2 != NULL);
	while ((num--) && !(ret = (*str1 - *str2)))//与strcmp最大的差别,不用找'\0'
	{
		str1++;
		str2++;
	}
	if (ret > 0)
	{
	    return 1;
	} 
	else if (ret < 0)
	{
		return -1;
	}
	return 1;
}

int main1()
{
	char ar1[10] = "abcdef";
	printf(my_strchr(ar1, 'a'));
	printf("\n");
	printf(my_strchr(ar1, 'f'));
	printf("\n");
	printf(my_strchr(ar1, 'g')); 
	printf("\n");
    system("pause");
    return 0;
}
