#include "utility.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void getPassword(char *pass)
{
	char buff[50] = { 0 }, ch;
	int len = 0;
	

	//clear;
	
	while ((ch = _getch()) != '\n' )
	{
		if (ch == '\r') {
			break;
		}
		// nguon: https://www.includehelp.com/c-programs/c-program-puzzle-design-login-screen-check-username-and-password.aspx
		if (ch == '\b')    // dau backspace
		{
			if (len == 0)  continue;
			printf("\b \b"); len--; continue;
		}
		putc('*', stdout);
		pass[len] = ch;
		len++;
	}
	pass[len] = '\0';

	char* encryptPass = maHoa(pass);

	strcpy_s(pass, PASS_LENGTH,  encryptPass);
	free(encryptPass);
	putc('\n', stdout);
}

int getChoice()
{
	int item = _getch();
	item -= ('1' - 1);
	return item;
}

void showTitle(TITLE_CASE type)
{
	Line();
	switch (type) {
		case MAIN: {
			Title();
			break;
		}
		case BOOK: {
			Title_book();
			break;
		}
		case READER: {
			Title_reader();
			break;
		}
		case USER: {
			Title_user();
			break;
		}
	}
	Line();
}

void showInfo(const char *info)
{
	Line();
	printf("] %s\n", info);
	Line();
	printf("\n\n");
}

void initDate(Date &date)
{
	date.day = 0;
	date.month = 0;
	date.year = 0;
}

Date nhapDate()
{
	Date result;

	scanf("%d/%d/%d", &result.day, &result.month, &result.year);
	return result;
}

void showDate(Date date)
{
	printf("%02d/%02d/%04d", date.day, date.month, date.year);
}

int CharToNum(char num)
{
	return (int)(num - '1' + 1);
}

int MSToNum(char *str)
{
	if (str == NULL) {
		return 0;
	}
	if (strlen(str) < 9) {
		return 0;
	}
	int num; 

	num = CharToNum(str[4]) * 10000 + CharToNum(str[5]) * 1000 + CharToNum(str[6]) * 100 + CharToNum(str[7]) * 10 + CharToNum(str[8]);
	return num;
}

char* DateToString(Date date)
{
	char* sDate = (char*)malloc(sizeof(char) * DAY_LENGTH); // dd/mm/yyyy

	if (sDate == NULL) {
		return sDate;
	}
	sprintf_s(sDate, DAY_LENGTH,  "%02d/%02d/%04d", date.day, date.month, date.year);

	return sDate;
}

Date StringToDate(char *sdate)
{
	Date date;

	//dd/mm/yyyy
	date.day = CharToNum(sdate[0]) * 10 + CharToNum(sdate[1]);
	date.month = CharToNum(sdate[3]) * 10 + CharToNum(sdate[4]);
	date.year = CharToNum(sdate[6]) * 1000 + CharToNum(sdate[7]) * 100 + CharToNum(sdate[8]) * 10 + CharToNum(sdate[9]);

	return date;
}

int isCapPhatThanhCong(void *p, const char *info)
{
	if (p == nullptr) {
		printf("\nCap phat bo nho that bai ( %s )\n", info);
		return 0;
	}
	return 1;
}

int isHavePerm(unsigned int uPerm, Perm perm)
{
	return !(!(getBit(uPerm, perm)));
}

void clearEnter()
{
	char t; 
	while ((t = getchar()) != '\n' && t != EOF);
}

char* maHoa(char* password)
{
	int len = strlen(password) * 2 + 1;
	char* encrypt = (char*)malloc(sizeof(char)*len);
	
	int len_s = strlen(salt), len_p = strlen(password);
	int num_s = 0, num_p = 0;
	for (int i = 0; i < len - 1; i++) {
		if (i % 2 == 0) {
			*(encrypt + i) = *(salt + num_s);
			num_s++;
			if (num_s > len_s) {
				num_s = 0;
			}
		}
		else {
			*(encrypt + i) = *(password + num_p);
			num_p++;
		}

		*(encrypt + i) ^= pepper;
	}
	encrypt[len-1] = '\0';
	return encrypt;
}
