#include "utility.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void getPassword(char *pass)
{
	char ch;
	int len = 0;
		
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
		if( len < PASS_LENGTH - 1  ) {
			pass[len] = ch;
			len++;
		}
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
		case CARD: {
			Title_card();
			break;
		}
		case STATISTICS: {
			Title_statistics();
			break;
		}
	}
	Line();
}

void showTitle(const char* info)
{
	Line();
	printf("\t%s\n", info);
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
	clearEnter();
	return result;
}

Date increaseDate(Date current, int day)
{
	Date result;

	result = current;

	result.day += day;

	int day_odd = result.day - getDay(result.month, result.year);
	while (day_odd > 0 ) {
		result.month++;
		result.day = day_odd;
		

		if (result.month > 12) {
			result.month = 1;
			result.year++;
		}

		day_odd = result.day - getDay(result.month, result.year);
	}
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

	if (*sdate == '\0') {
		return Date();
	}
	//dd/mm/yyyy
	date.day = CharToNum(sdate[0]) * 10 + CharToNum(sdate[1]);
	date.month = CharToNum(sdate[3]) * 10 + CharToNum(sdate[4]);
	date.year = CharToNum(sdate[6]) * 1000 + CharToNum(sdate[7]) * 100 + CharToNum(sdate[8]) * 10 + CharToNum(sdate[9]);

	return date;
}

int getDay(int month, int year)
{
	if (month == 2)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			return 29;
		}
		return 28;
	}
	switch (month) {
		case 1: {
			return 31;
		}
		case 3:{
			return 31;
		}
		case 5:{
			return 31;
		}
		case 7: {
			return 31;
		}
		case 8:{
			return 31;
		}
		case 10:{
			return 31;
		}
		case 12: {
			return 31;
		}
	}
	return 30;
}

Date getToday() {
	Date today;

	time_t current;
	tm *timeinfo;

	current = time(NULL);

	timeinfo = localtime(&current);

	today.day = timeinfo->tm_mday;
	today.month = timeinfo->tm_mon + 1; // tm_mon lưu từ 0 đến 1
	today.year = timeinfo->tm_year + 1900; // tm_year lưu từ 1900, tức năm 1901 sẽ là tm_year = 1

	return today;
}

int getCachNgay(Date ngayTruoc, Date ngaySau) {
	if (!kiemTraTre(ngayTruoc, ngaySau)) {
		return -1;
	}

	int SoNgay = 0;
	if (ngayTruoc.year == ngaySau.year)	{
		if (ngayTruoc.month == ngaySau.month) {
			SoNgay = SoNgay + ngaySau.day - ngayTruoc.day;
		}
		else if (ngayTruoc.month < ngaySau.month) {
			SoNgay = SoNgay + ngaySau.day;
			SoNgay = SoNgay + getDay(ngayTruoc.month, ngayTruoc.year) - ngayTruoc.day;
			for (int i = ngayTruoc.month + 1; i < ngaySau.month; i++) {
				int dem = getDay(i, ngaySau.year);
				SoNgay = SoNgay + dem;
			}
		}
	}
	else if (ngayTruoc.year < ngaySau.year)	{
		SoNgay = SoNgay + ngaySau.day;
		SoNgay = SoNgay + getDay(ngayTruoc.month, ngayTruoc.year) - ngayTruoc.day;
		for (int i = ngayTruoc.month + 1; i <= 12; i++)	{
			int dem = getDay(i, ngayTruoc.year);
			SoNgay = SoNgay + dem;
		}
		for (int i = ngayTruoc.year + 1; i < ngaySau.year; i++) {
			int dem = getDay(2, i);
			if (dem == 28)
			{
				SoNgay = SoNgay + 365;
			}
			else if (dem == 29)
			{
				SoNgay = SoNgay + 366;
			}
		}
		for (int i = 1; i < ngaySau.month; i++)	{
			int dem = getDay(i, ngaySau.year);
			SoNgay = SoNgay + dem;
		}
	}
	return SoNgay;
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
	return getBit(uPerm, perm);
}

void clearEnter()
{
	while ((getchar()) != '\n');
}

char* maHoa(char* password)
{
	int len = strlen(password) + 1;
	char* encrypt = (char*)malloc(sizeof(char)*len);
	
	int num_pepper = 0;
	for (int i = 0; i < len - 1; i++) {
		*(encrypt + i) = *(password + i);
		*(encrypt + i) ^= num_pepper;
		num_pepper++;
		if (num_pepper > PEPPER) {
			num_pepper = 0;
		}
	}
	encrypt[len-1] = '\0';
	return encrypt;
}

int kiemTraTre(Date ngayKiemTra, Date ngayLamMoc)
{
	if (ngayKiemTra.year < ngayLamMoc.year) {
		return 0;
	}
	if (ngayKiemTra.month < ngayLamMoc.month) {
		return 0;
	}
	if (ngayKiemTra.day < ngayLamMoc.day) {
		return 0;
	}

	return 1;
}
