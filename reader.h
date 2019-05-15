#pragma once
#include "utility.h"

struct Reader {
	char MS[MS_LENGTH];
	char HoTen[NAME_LENGTH];
	char CMND[CMND_LENGTH];
	Date birth;
	int nam;
	Date lapThe;
};

void initReader(Reader &reader);

int isVaildReader(Reader reader);

Date getHetHan(Date lapThe);

int nhapReader(Reader &reader);

void showReader(Reader reader);

char* nhapReader_CMND();
char* nhapReader_HoTen();