#include "const.h"
#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"


void initReader(Reader &reader)
{
	reader.MS[0] = '\0';
	reader.HoTen[0] = '\0';
	reader.CMND[0] = '\0';

	initDate(reader.birth);
	initDate(reader.lapThe);

	reader.nam = -1;

}

int isVaildReader(Reader reader)
{

	if (reader.MS[0] == '\0') {
		return 0;
	}

	if (reader.HoTen[0] == '\0') {
		return 0;
	}

	if (reader.CMND[0] == '\0') {
		return 0;
	}
	if (reader.nam == -1) {
		return 0;
	}

	return 1;
}

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

int addReaderToFile(Reader reader)
{
	if (!isVaildReader(reader)) {
		return 0;
	}

	FILE *f = fopen(READER_FILE, "a");

	char *birth = DateToString(reader.birth);
	char *lapThe = DateToString(reader.lapThe);
	fprintf(f, "%s, %s, %s, %s, %d, %s", reader.MS, reader.HoTen, reader.CMND, birth, reader.nam, lapThe );

	free(birth);
	free(lapThe);

	fclose(f);
	return 1;
}
