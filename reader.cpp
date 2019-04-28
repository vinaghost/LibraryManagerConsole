#include "const.h"
#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	fprintf(f, "%s, %s, %s, %s, %d, %s\n", reader.MS, reader.HoTen, reader.CMND, birth, reader.nam, lapThe );

	free(birth);
	free(lapThe);

	fclose(f);
	return 1;
}

int nhapReader(Reader &reader)
{
	sprintf(reader.MS, "01");

	printf("Nhap thong tin doc gia: \n");
	printf("] Ho ten: ");
	if (fgets(reader.HoTen, sizeof(reader.HoTen), stdin) != NULL) {
		size_t len = strlen(reader.HoTen);
		if (len > 0 && reader.HoTen[len - 1] == '\n') {
			reader.HoTen[--len] = '\0';
		}
	}
	printf("] CMND: ");
	if (fgets(reader.CMND, sizeof(reader.CMND), stdin) != NULL) {
		size_t len = strlen(reader.CMND);
		if (len > 0 && reader.CMND[len - 1] == '\n') {
			reader.CMND[--len] = '\0';
		}
	}
	printf("] Ngay/thang/nam sinh (dd/mm/yyyy): ");
	reader.birth = nhapDate();
	printf("] Gioi tinh ( 1 - Nam, 0 - Nu): ");
	scanf("%d", &reader.nam);
	printf("] Ngay/thang/nam tao the (dd/mm/yyyy): ");
	reader.lapThe = nhapDate();

	return 1;
}

void NhapReaderFind_CMND(Reader &reader_find)
{
		printf("Nhap CMND cua doc gia: ");
		if (fgets(reader.CMND, sizeof(reader.CMND), stdin) != NULL) {
			size_t len = strlen(reader.CMND);
			if (len > 0 && reader.CMND[len - 1] == '\n') {
				reader.CMND[--len] = '\0';
			}

void FindReader_CMND(Reader reader)
{
	Reader reader_find;
	NhapReaderFind_CMND(reader_find);
	FILE *readerfile;
	readerfind = fopen(READER_FILE, "r");
	while (!feof(f))
	{
		char st[200];
		fgets(st, sizeof(st), readerfile);
		sscanf(st, "%s, %s, %s, %s, %d, %s", reader.MS, reader.HoTen, reader.CMND, birth, reader.nam, lapThe);
		if (strcmp(reader_find.CMND, reader.CMND) == 0)
		{
			printf("Thong tin doc gia can tim:/n");
			printf("%s, %s, %s, %s, %d, %s", reader.MS, reader.HoTen, reader.CMND, birth, reader.nam, lapThe);
		}
		else
		{
			printf("Khong tim thay doc gia\n");
		}
	}
}

void NhapReaderFind_HoTen(Reader &reader_find)
{
	printf("Nhap Ho va Ten cua doc gia: ");
	if (fgets(reader.HoTen, sizeof(reader.HoTen), stdin) != NULL) {
		size_t len = strlen(reader.HoTen);
		if (len > 0 && reader.HoTen[len - 1] == '\n') {
			reader.HoTen[--len] = '\0';
		}
}

void FindReader_HoTen(Reader reader)
{
	Reader reader_find;
	NhapReaderFind_HoTen(reader_find);
	FILE *readerfile;
	readerfind = fopen(READER_FILE, "r");
	while (!feof(f))
	{
		char st[200];
		fgets(st, sizeof(st), readerfile);
		sscanf(st, "%s, %s, %s, %s, %d, %s", reader.MS, reader.HoTen, reader.CMND, birth, reader.nam, lapThe);
		if (strcmp(reader_find.HoTen, reader.HoTen) == 0)
		{
			printf("Thong tin doc gia can tim:/n");
			printf("%s, %s, %s, %s, %d, %s", reader.MS, reader.HoTen, reader.CMND, birth, reader.nam, lapThe);
		}
		else
		{
			printf("Khong tim thay doc gia\n");
		}
	}
}