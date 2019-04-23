#include "User.h"
#include "const.h"
#include <stdio.h>

void initUser(User &t) {
	sprintf_s(t.name, sizeof(t.name), "");
	sprintf_s(t.password, sizeof(t.password), "");

	t.permission = 0;
}

void AddInf(User &u)
{
	printf("Name: ");
	scanf("%s", u.name);
	printf("Ho Ten(cac tu cach nhau bang dau _): ");
	scanf("%s", u.HoTen);
	printf("Ma So SV: ");
	scanf("%s", u.MS);
	printf("Birth: ");
	scanf("%s", u.Birth);
	printf("Tinh/Thanh pho(cac tu cach nhau bang dau _): ");
	scanf("%s", u.DiaChi);
	printf("Gioi Tinh (Nam: 1; Nu: 0): ");
	scanf("%s", u.Nam);
	printf("Active(Active: 1; Block: 0): ");
	scanf("%s", u.active);
}

void CreateUser(User u)
{
	printf("Nhap thong tin nguoi dung:/n");
	FILE *f;
	f = fopen(USER_FILE, "a");
	AddInf(u);
	fprintf(f, "%s | %s | %s | %s | %s | %s | %s", u.name, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam, u.active);
	fclose(f);
}