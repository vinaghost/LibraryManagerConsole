#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include "const.h"
#include <stdio.h>
#include <string.h>

void initUser(User &t) {
	t.name[0] = '\0';
	t.password[0] = '\0';

	t.permission = 0;
}

void AddInf(User &u)
{
	printf("Name: ");
	scanf("%s", u.name);
	printf("Password: ");
	scanf("%s", u.password);
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
	fprintf(f, "%s %s %s %s %s %s %s %s", u.name, u.password, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam, u.active);
	fclose(f);
}
int isVaildUser(User t)
{
	if (t.name[0] == '\0') {
		return 0;
	}
	return 1;
}

void NewPass(User &u)
{
	printf("Name: ");
	scanf("%s", u.name);
	printf("New Pass: ");
	scanf("%s", u.password);

}

int FindPlaceOldPass(User u, User &f, User &h)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "r");

	if (userFile == NULL)
	{
		printf("[ERROR] Khong tim thay file user.dat");
	}

	NewPass(h);
	int dem = 0;
	while (!feof(userFile)) 
	{

		dem = dem + 1;
		char str[200];
		fgets(str, sizeof(str), userFile);
		sscanf(str, "%s %s %s %s %s %s %s %s", u.name, u.password, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam, u.active);
		sscanf(str, "%s %s %s %s %s %s %s %s", f.name, f.password, f.HoTen, f.MS, f.Birth, f.DiaChi, f.Nam, f.active);

		if (strcmp(u.name, h.name) == 0) 
		{
			return dem;
		}
	}
}

void ChangePass(User u)
{
	User f, h;
	int delete_line = 0;
	delete_line = FindPlaceOldPass(u, f, h);
	FILE *file1, *file2;
	char ch;
	int temp = 1;

	file1 = fopen(USER_FILE, "r");
	file2 = fopen("test.dat", "w"); 
	ch = getc(file1);
	while (ch != EOF)
	{
		ch = getc(file1);
		if (ch == '\n')
			temp++;
		if (temp != delete_line)
		{
			putc(ch, file2);
		}
	}
<<<<<<< HEAD
	fprintf(file2, "%s %s %s %s %s %s %s %s", h.name, h.password, f.HoTen, f.MS, f.Birth, f.DiaChi, f.Nam, f.active);
	fclose(file1);
	fclose(file2);
	remove(USER_FILE);
	rename("test.dat", USER_FILE);
}


void NewInf(User &u)
{
	printf("Name: ");
	scanf("%s", u.Name);
	printf("Ho Ten(viet cach nhau bang dau _): ");
	scanf("%s", u.Hoten);
	printf("MSSV: ");
	scanf("%s", u.MS);
	printf("Birth: ");
	scanf("%s", u.Birth);
	printf("Sex(Nam: 1; Nu: 0): ");
	scanf("%s", u.Nam);
	printf("Tinh trang(Active: 1; Block: 0): ");
	scanf("%s", u.active);
}

void FindPlaceOldInf(User u, User &f, User &h)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "r");

	if (userFile == NULL)
	{
		printf("[ERROR] Khong tim thay file user.dat");
	}

	NewInf(h);
	int dem = 0;
	while (!feof(userFile))
	{

		dem = dem + 1;
		char str[200];
		fgets(str, sizeof(str), userFile);
		sscanf(str, "%s %s %s %s %s %s %s %s", u.name, u.password, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam, u.active);
		sscanf(str, "%s %s %s %s %s %s %s %s", f.name, f.password, f.HoTen, f.MS, f.Birth, f.DiaChi, f.Nam, f.active);

		if (strcmp(u.name, h.name) == 0)
		{
			return dem;
		}
	}
}

void ChangeInf(User u)
{
	User f, h;
	int delete_line = 0;
	delete_line = FindPlaceOldPass(u, f, h);
	FILE *file1, *file2;
	char ch;
	int temp = 1;

	file1 = fopen(USER_FILE, "r");
	file2 = fopen("test.dat", "w");
	ch = getc(file1);
	while (ch != EOF)
	{
		ch = getc(file1);
		if (ch == '\n')
			temp++;
		if (temp != delete_line)
		{
			putc(ch, file2);
		}
	}
	fprintf(file2, "%s %s %s %s %s %s %s %s", f.name, f.password, h.HoTen, h.MS, h.Birth, h.DiaChi, h.Nam, h.active);
=======
	fprintf(file2, "%s | %s | %s | %s | %s | %s | %s | %s", h.name, h.password, f.HoTen, f.MS, f.Birth, f.DiaChi, f.Nam, f.active);
>>>>>>> 8698c68db8d94e5e1758be1412ce6cd18c550299
	fclose(file1);
	fclose(file2);
	remove(USER_FILE);
	rename("test.dat", USER_FILE);
}