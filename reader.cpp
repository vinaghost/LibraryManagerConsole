#include "reader.h"
#include <stdlib.h>
#include "utility.h"
#include "const.h"


Date getHetHan(Date lapThe)
{
	Date hetHan;

	hetHan.day = lapThe.day;

	int month = lapThe.month;
	int year = lapThe.year;

	month += HET_HAN_THE;

	if (month > 12) {
		int tmp = month / 12;
		month %= 12;

		year += tmp;
	}

	hetHan.month = month;
	hetHan.year = year;

	return hetHan;
}
