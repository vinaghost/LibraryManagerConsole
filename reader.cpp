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

int nhapReader(Reader &reader)
{
	sprintf(reader.MS, "processing");

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

void showReader(Reader reader)
{
	printf("] Ma so: %s\n", reader.MS);

	printf("] Ho ten: %s \n", reader.HoTen);

	printf("] CMND: %s \n", reader.CMND);

	printf("] Ngay sinh: ");
	showDate(reader.birth);
	printf("\n");

	printf("] Gioi tinh: %s", reader.nam ? "nam" : "nu");

	printf("] Ngay tao the: ");
	showDate(reader.lapThe);
	printf("\n");
}

char* nhapReader_CMND()
{
	char* cmnd = (char*)malloc(sizeof(char) * CMND_LENGTH);
	if (cmnd == NULL) {
		return NULL;
	}
	printf("Nhap CMND cua doc gia: ");
	if (fgets(cmnd, CMND_LENGTH, stdin) != NULL) {
		size_t len = strlen(cmnd);
		if (len > 0 && cmnd[len - 1] == '\n') {
			cmnd[--len] = '\0';
		}
	}

	return cmnd;
}

char* nhapReader_HoTen()
{
	char* hoTen = (char*)malloc(sizeof(char) * NAME_LENGTH);
	if (hoTen == NULL) {
		return NULL;
	}
	if (fgets(hoTen, NAME_LENGTH, stdin) != NULL) {
		size_t len = strlen(hoTen);
		if (len > 0 && hoTen[len - 1] == '\n') {
			hoTen[--len] = '\0';
		}
	}

	return hoTen;
}
