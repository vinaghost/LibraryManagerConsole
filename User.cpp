#define _CRT_SECURE_NO_WARNINGS

#include "User.h"
#include "const.h"
#include <stdio.h>
#include <string.h>
#include "utility.h"

void initUser(User &t) {
	t.name[0] = '\0';
	t.password[0] = '\0';

	t.permission = 0;

	t.HoTen[0] = '\0';
	t.MS[0] = '\0';
	t.Birth[0] = '\0';
	t.DiaChi[0] = '\0';
	t.Nam = 0;
	t.active = 0;

	t.location = -1;
}

void showUser(User u)
{

	printf("Username: %s", u.name);
	printf("password: %s", u.password);


	printf("Phan quyen (Quan li: 1, Chuyen vien: 2): %d ", u.permission);

	printf("Ho Ten(cac tu cach nhau bang dau _): %s", u.HoTen);

	printf("Ma So SV: %s", u.MS);

	printf("Birth: %s", u.Birth);

	printf("Tinh/Thanh pho(cac tu cach nhau bang dau _): %s", u.DiaChi);

	printf("Gioi Tinh (Nam: 1; Nu: 0): %d", u.Nam);
	
	printf("Location : %d", u.location);

}

int isVaildUser(User t)
{
	if (t.name[0] == '\0') {
		return 0;
	}
	return 1;
}

int findUserLocation(User u)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "r");

	if (userFile == NULL)
	{
		printf("[ERROR] Khong tim thay file %s", USER_FILE);
	}
	int dem = 0;

	User f;

	while (!feof(userFile))
	{
		dem++;
		char str[200];
		fgets(str, sizeof(str), userFile);

		sscanf(str, "%s %s %d %s %s %s %s %d %d", f.name, f.password, &f.permission, f.HoTen, f.MS, f.Birth, f.DiaChi, &f.Nam, &f.active);


		if (strcmp(u.name, f.name) == 0)
		{
			return dem;
		}
	}

	return -1;
}

void createUser(User u)
{
	printf("Nhap thong tin nguoi dung:\n");
	FILE *f;
	f = fopen(USER_FILE, "a+");
	
	nhapUser(u);
	nhapInf(u);

	fprintf(f, "%s %s %d %s %s %s %s %d 1\n", u.name, u.password, u.permission, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam);
	fclose(f);

	printf("Ghi file thanh cong");
}

void addPerm(User &u, PermUser perm) {

	switch (perm) {
		case ADMIN: {
			for (int i = LOGIN; i < VIEWNUMREADERASLATE + 1; i++) {
				u.permission |= (1 << i);
			}
			break;
		}
		case QUANLI: {
			//1.1 1.2 1.3 1.4
			setBit(u.permission, LOGIN);
			setBit(u.permission, LOGIN);
			setBit(u.permission, CHANGEPASS);
			setBit(u.permission, CHANGEINFO);

			//2.x
			setBit(u.permission, VIEWREADER);
			setBit(u.permission, ADDREADER);
			setBit(u.permission, EDITREADER);
			setBit(u.permission, DELETEREADER);
			setBit(u.permission, FINDREADERASCMND);
			setBit(u.permission, FINDREADERASNAME);

			//3.x
			setBit(u.permission, VIEWBOOK);
			setBit(u.permission, ADDBOOK);
			setBit(u.permission, EDITBOOK);
			setBit(u.permission, DELETEBOOK);
			setBit(u.permission, FINDBOOKASISBN);
			setBit(u.permission, FINDBOOKASNAME);

			//4
			setBit(u.permission, CREATMUONSACH);

			//5
			setBit(u.permission, CREATTRASACH);

			//6.x
			setBit(u.permission, VIEWNUMBOOK);
			setBit(u.permission, VIEWNUMBOOKASCATA);
			setBit(u.permission, VIEWNUMREADER);
			setBit(u.permission, VIEWNUMREADERASGENDER);
			setBit(u.permission, VIEWNUMBOOKASBORROW);
			setBit(u.permission, VIEWNUMREADERASLATE);
			break;
		}
		
		case CHUYENVIEN: {


			//1.1 1.2 1.3 1.4
			setBit(u.permission, LOGIN);
			setBit(u.permission, LOGIN);
			setBit(u.permission, CHANGEPASS);
			setBit(u.permission, CHANGEINFO);

			//2.1 2.2 2.3 2.4 2.5 2.6
			setBit(u.permission, VIEWREADER);
			setBit(u.permission, ADDREADER);
			setBit(u.permission, EDITREADER);
			//setBit(u.permission, DELETEREADER);
			setBit(u.permission, FINDREADERASCMND);
			setBit(u.permission, FINDREADERASNAME);

			//3.5 3.6
			//setBit(u.permission, VIEWBOOK);
			//setBit(u.permission, ADDBOOK);
			//setBit(u.permission, EDITBOOK);
			//setBit(u.permission, DELETEBOOK);
			setBit(u.permission, FINDBOOKASISBN);
			setBit(u.permission, FINDBOOKASNAME);

			//4
			setBit(u.permission, CREATMUONSACH);

			//5
			setBit(u.permission, CREATTRASACH);

			//6.5 6.6
			//setBit(u.permission, VIEWNUMBOOK);
			//setBit(u.permission, VIEWNUMBOOKASCATA);
			//setBit(u.permission, VIEWNUMREADER);
			//setBit(u.permission, VIEWNUMREADERASGENDER);
			setBit(u.permission, VIEWNUMBOOKASBORROW);
			setBit(u.permission, VIEWNUMREADERASLATE);
			break;
		}
	}

}

void nhapUser(User &u)
{
	printf("Username: ");
	scanf("%s", u.name);
	
	
	printf("Password: ");
	getPassword(u.password);


	printf("Phan quyen (Quan li: 1, Chuyen vien: 2): ");
	PermUser perm;
	scanf("%d", &perm);
	addPerm(u, perm);
}

void nhapInf(User &u)
{
	printf("Ho Ten(cac tu cach nhau bang dau _): ");
	scanf("%s", u.HoTen);

	printf("Ma So SV: ");
	scanf("%s", u.MS);

	printf("Birth: ");
	scanf("%s", u.Birth);

	printf("Tinh/Thanh pho(cac tu cach nhau bang dau _): ");
	scanf("%s", u.DiaChi);

	printf("Gioi Tinh (Nam: 1; Nu: 0): ");
	scanf("%d", &u.Nam);
}

int changePass(User &u)
{
	int delete_line = u.location;

	FILE *root, *tmp;
	char ch;
	int count = 1;

	char pass[50];


	newPass(pass);

	if (strcmp(pass, u.password) != 0) {
		return 0;
	}

	root = fopen(USER_FILE, "r");
	tmp = fopen(TMP_FILE, "w");

	ch = getc(root);
	while (ch != EOF)
	{
		ch = getc(root);
		if (ch == '\n')
			count++;
		if (count != delete_line)
		{
			putc(ch, tmp);
		}
	}

	fprintf(tmp, "%s %s %d %s %s %s %s %d 1\n", u.name, pass, u.permission, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam);

	fclose(root);
	fclose(tmp);
	remove(USER_FILE);
	rename(TMP_FILE, USER_FILE);

	return 1;
}

void newPass(char *pass)
{
	printf("Nhap pass moi: ");
	scanf("%s", pass);
}

int changeInf(User &u)
{
	int delete_line = u.location;

	FILE *root, *tmp;
	char ch;
	int count = 1;

	char pass[50];


	nhapInf(u);

	if (strcmp(pass, u.password) != 0) {
		return 0;
	}

	root = fopen(USER_FILE, "r");
	tmp = fopen(TMP_FILE, "w");

	ch = getc(root);
	while (ch != EOF)
	{
		ch = getc(root);
		if (ch == '\n')
			count++;
		if (count != delete_line)
		{
			putc(ch, tmp);
		}
	}

	fprintf(tmp, "%s %s %d %s %s %s %s %d 1", u.name, pass, u.permission, u.HoTen, u.MS, u.Birth, u.DiaChi, u.Nam);

	fclose(root);
	fclose(tmp);
	remove(USER_FILE);
	rename(TMP_FILE, USER_FILE);

	return 1;
}
