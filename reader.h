#pragma once
#include "utility.h"

struct Reader {
	char MS[20];
	char HoTen[40];
	char CMND[20];
	Date birth;
	int nam;
	Date lapThe;
};

void initReader(Reader &reader);

int isVaildReader(Reader reader);

Date getHetHan(Date lapThe);

int addReaderToFile(Reader reader);