#pragma once

struct Date {
	int day, month, year;
};

void getPassword(char *pass);

int getChoice();

void showTitle();

void showInfo(const char* info);

void initDate(Date &date);
Date nhapDate();


int CharToNum(char num);

char* DateToString(Date date);
void showInfo(const char* info); 
