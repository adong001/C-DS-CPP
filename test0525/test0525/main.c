#define _CRT_SECURE_NO_WARNINGS 1
#define SIZEOF(a)  sizeof(a)/sizeof(a[0])
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
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
//4.实现strchr
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
//7.实现memmove



size_t my_strlen(const char* str)
{
	int size=0;
    assert(str != NULL);
	while (*str++ != '\0'){ size++; }
	return size;
}

char *my_strncpy(char* str, const char* soure, size_t n)//把src所指字符串的前n个字符添加
{
	char *dest = str;
	assert(str != NULL && soure != NULL);//注意如果assert中的值为0时直接会终止掉程序
	while ((n-- > 0) && (*dest++ = *soure++));
	return str;
}
char *my_strncat(char* str, const char* soure, size_t n)//把src所指字符串的前n个字符添加
{
	char *dest = str;
	while (*dest){ dest++; };
    assert(str != NULL && soure != NULL);//注意如果assert中的值为0时直接会终止掉程序
	while (*dest){ dest++; };
    while ((n-- > 0) && (*dest++ = *soure++));
    return str;
}

size_t my_strncmp(const char* str1, const char* str2,size_t n)//比较两个字符串前n个字符
{
	const unsigned char* src1 = (const unsigned char*)str1;
	//强转成const unsigned char* 是为了下面两个指针的值的ascii相减
	const unsigned char* src2 = (const unsigned char*)str2;
	int ret = 0;
	assert(src1 != NULL && src2 != NULL);
	while (!(*src1 - *src2) && *src2 && n > 0 )//如果两个值不相等或*src2的ascii为0,
	{//(*src1-*src2,所以如果*src2的ascii的值为0,那*src1就比*src2大或相等,显然结果就已知了,退出循环）,
	 //就继续判断, 否则，求出相减的值并退出循环
		src1++, src2++,n--;
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

//int main()
//{
//	char str1[20]= "abcd";
//	char str2[20] = "abcdef";
//	printf("%d\n",my_strcmp(str1, str2));
//	return 0;
//}
//| 返回值 | str1   str2 |
//| -- | -- |
//| 1 | > ||
//| 0 |= |
//| -1 | < |
/*char str[20];
char str1[20]="i am ";
char str2[20] = "a student ";
my_strcpy(str,my_strcat(str1, str2));
puts(str);

}*/
//int my_strcmp(const char* str1, const char* str2)
//{
//
//}
//typedef struct student
//{
//	
//	char name[20];   //20
//	char sex;        //4
//	int num;         //4
//}student;
//#include <stdio.h> #pragma pack(8)
//struct S1 {    
//	char c1;   
//	int i;
//    char c2; };
//#pragma pack()
//int main()
//{
//	printf("%d\n", sizeof(struct S1));
//
//	char str[10];
//	char str2[10];
//	printf("%d\n", strcmp(str, str2));
	/*char str[20];
	char str1[20]="i am ";
	char str2[20] = "a student ";
	my_strcpy(str,my_strcat(str1, str2));
	puts(str);

}*/



//#include <string.h>
//
//int main() 
//{
//	char str[] = "- hhhhhhh, a sample string,"; 
//char * pch; d
//printf("Splitting string \"%s\" into tokens:\n", str);
//pch = strtok(str, " ,,-"); 
//
//while (pch != NULL) 
//{ printf("%s\n", pch);
//pch = strtok(NULL, " ,,-"); } 
//return 0; }
////int mainl()
////{
////	char str[] = "hahah\012";
////	printf("%d\n", my_strlen(str));
////    system("pause");
////    return 0;


//
//char *my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 != NULL);
//	char *s1 = (char*)str1;
//	char *s2 = (char*)str2;
//	char *p = (char*)str1;
//	if (str2 == NULL)
//	{
//		return NULL;
//	}
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1&&*s2&&*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return p;
//		}
//		p++;
//	}
//	return 0;
//}
//
//int main()
//{
//
//	char str1[] = "abcdcdefggg";
//	char str2[] = "cdef";
//	puts(my_strstr(str1, str2));
//}
	/*while (*s1)
	{
		p = s1;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		s2 = str2;
	}

}*/

//typedef struct student
//{
//	int num;
//	char name[20];
//	char sex;
//}stu;
//int main()
//{
//	stu a = { 1, "杨超", 'f' };  //结构体类型只能初始化
//	printf("%d %s %c\n", a.num, a.name, a.sex);
//	//stu b;
//	//b = { 2, "张三", '男' };    //不能直接赋值，比如数组 
//	//char ar[10] = "ajdjajd";
//	//char arr[10];
//	//arr = "adwokoefowkef";      //不能直接赋值，只能初始化
//	stu b;                       //想要赋值，只能分别对成员赋值；
//	b.num = 2;
//	strcpy(b.name, "张三");
//	b.sex = '男';
//	stu c;
//	c = a;
//	printf("%d %s %c\n", c.num, c.name, c.sex);
//	system("pause");
//	return 0;
//}

//#pragma pack(2)
//struct data
//{
//	int a;  // 4  2
//	char b; // 1  2
//}; 
//#pragma pack() 
//int main()
//{
//	printf("%d\n", sizeof(struct data));
//}

//#define my_offsetof(s,m)  (size_t)&(((s *)0)->m)
//typedef struct student
//{
//	int num;       //4
//	char name[20]; //20
//	char sex;      //4
//}stu;
//int main()
//{
//	printf("%d\n", my_offsetof(stu,name));
//}

//struct A    
//{   //位段
//	int a : 2; 
//	int b : 5; //2 ，5, 10 占一个int字节，
//	int c : 10;
//	int d : 30;//30自己占一个int字节
//};
//int main()
//{
//	struct A a;
//	a.a = 2;
//	a.b = 5;
//	printf("%d\n", sizeof(struct A));
//}

//typedef enum week
//{
//	Mon=1,Tues,Wed,Thu=3,Fri,Sat,Sun
//}week;
//int main1()
//{
//	week W;
//	W = Wed;
//	printf("%d\n", W);
//}
//typedef union Un
//{
//	int a;
//	char b;
//	double c;//共用体大小以最大的成员为准
//}Un;

//int main()-
//{
//	Un U;
//	//U.a = 10;
//	//U.b = '3';
//	//printf("%d\n", sizeof(Un));
//	//printf("%p\n", U.a);
//	//printf("%p\n", U.b);=
//	U.a = 0x11223344;
//	U.c = 0x55;
//	printf("%x\n", U.a);
//	printf("%x\n", U.c);
//}
//int sys_check()
//{
//	int a = 1;
//	return *(((char*)a) & 1);
//}
//union data
//{
//	short int a;
//	char b[2];sss
//
//};


//register int i;
//(期望)定义在寄存器里，不在主存，所以没有地址；
//volatile 
//volatile的作用是作为指令关键字，确保本条指令不会因编译器的优化而省略，且要求每次直接读值。
//static 
//限制函数和变量的作用域;
//限制