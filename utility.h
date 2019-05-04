#pragma once
#include "const.h"
struct Date {
	int day, month, year;
};

void getPassword(char *pass);

int getChoice();

void showTitle(TITLE_CASE type);

void showInfo(const char* info);

void initDate(Date &date);
Date nhapDate();
void showDate(Date date);

int CharToNum(char num);
int MSToNum(char *str);

char* DateToString(Date date);
Date StringToDate(char *sdate);
void showInfo(const char* info); 


int isCapPhatThanhCong(void* p, const char* info);

int isHavePerm(unsigned int uPerm, Perm perm);

char *maHoa(char *password);
void getPassword(char *pass);
void clearEnter();