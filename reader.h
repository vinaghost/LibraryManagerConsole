#pragma once
#include "utility.h"

struct Reader {
	char MS[20];
	char HoTen[40];
	char CMND[20];
	char birth[9];
	int nam;
	Date lapThe;
};


Date getHetHan(Date lapThe)