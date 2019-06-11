#ifndef _MAILLIST_H
#define _MAILLIST_H

typedef struct MailList
{
	char 姓名[50];
	char 性别;
	char 电话[20];
	char 住址[100];
	int 年龄;
	MailList *next;
}MailList[1000], *List;

enum {
	ADD_MSG = 1,
	DELETE_MSG,
	SEARCH_MSG,
	CHANGE_MSG,
	DISPLAY_MSG,
	EMTTY_MSG
};
#endif /*_MAILLIST_H*/