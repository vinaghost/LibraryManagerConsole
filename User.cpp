#include "User.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

void initUser(User &t) {
	t.name[0] = '\0';
	t.password[0] = '\0';

	t.permission = 0;

	t.HoTen[0] = '\0';
	t.CMND[0] = '\0';
	initDate(t.ngaySinh);
	t.DiaChi[0] = '\0';
	t.Nam = 0;
	t.active = 0;

	t.location = -1;
}

void showUser(User u)
{

	printf("Username: %s\n", u.name);
	//printf("password: %s\n", u.password);


	printf("Phan quyen (Quan li: 1, Chuyen vien: 2): %d\n", u.permission);

	printf("Ho Ten: %s\n", u.HoTen);

	printf("CMND: %s\n", u.CMND);

	printf("Birth: ");
	showDate(u.ngaySinh);
	printf("\n");

	printf("Tinh/Thanh pho: %s\n", u.DiaChi);

	printf("Gioi Tinh (Nam: 1; Nu: 0): %d\n", u.Nam);
	
	printf("Location : %d\n", u.location);

}

User isExistUser(User &u)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "r+");

	if (userFile == NULL) {
		printf("[ERROR] Khong tim thay file user.dat");
	}


	User fuser;
	int count = 1;
	char str[200];
	while (fgets(str, sizeof(str), userFile) != NULL) {

		char birth[DAY_LENGTH];
		sscanf(str, "%[^,\n], %[^,\n], %d, %[^,\n], %[^,\n], %[^,\n], %[^,\n], %d %d", fuser.name, fuser.password, &fuser.permission, fuser.HoTen, fuser.CMND, birth, fuser.DiaChi, &fuser.Nam, &fuser.active);

		if (strcmp(u.name, fuser.name) == 0) {
			fuser.location = count;
			fuser.ngaySinh = StringToDate(birth);
			return fuser;
		}

		count++;
	}

	initUser(fuser);

	return fuser;
}
int isVaildUser(User t)
{
	if (t.name[0] == '\0') {
		return 0;
	}
	return 1;
}

void addPerm(User &u, PermUser perm) {

	switch (perm) {
		case ADMIN: {
			for (int i = LOGIN; i < VIEWNUMREADERLATE + 1; i++) {
				setBit(u.permission, i);
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
			setBit(u.permission, VIEWNUMBOOKASTYPE);
			setBit(u.permission, VIEWNUMREADER);
			setBit(u.permission, VIEWNUMREADERASGENDER);
			setBit(u.permission, VIEWNUMBOOKASBORROW);
			setBit(u.permission, VIEWNUMREADERLATE);
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
			setBit(u.permission, VIEWNUMREADERLATE);
			break;
		}
	}

}

void nhapUser(User &u)
{
	printf("Username: ");

	if (fgets(u.name, sizeof(u.name), stdin) != NULL) {
		size_t len = strlen(u.name);
		if (len > 0 && u.name[len - 1] == '\n') {
			u.name[--len] = '\0';
		}
	}
	printf("Password: ");
	getPassword(u.password);

	printf("Phan quyen (Quan li: 1, Chuyen vien: 2): ");
	PermUser perm;
	scanf("%d", &perm);
	clearEnter();
	addPerm(u, perm);
}

void nhapInf(User &u)
{
	printf("Ho Ten: ");
	if (fgets(u.HoTen, sizeof(u.HoTen), stdin) != NULL) {
		size_t len = strlen(u.HoTen);
		if (len > 0 && u.HoTen[len - 1] == '\n') {
			u.HoTen[--len] = '\0';
		}
	}
	printf("Ngay sinh (dd/mm/yyyy): ");
	u.ngaySinh = nhapDate();
	printf("CMND: ");
	if (fgets(u.CMND, sizeof(u.CMND), stdin) != NULL) {
		size_t len = strlen(u.CMND);
		if (len > 0 && u.CMND[len - 1] == '\n') {
			u.CMND[--len] = '\0';
		}
	}
	printf("Tinh/Thanh pho: ");
	if (fgets(u.DiaChi, sizeof(u.DiaChi), stdin) != NULL) {
		size_t len = strlen(u.DiaChi);
		if (len > 0 && u.DiaChi[len - 1] == '\n') {
			u.DiaChi[--len] = '\0';
		}
	}
	printf("Gioi Tinh (Nam: 1; Nu: 0): ");
	scanf("%d", &u.Nam);
	clearEnter();
}


void newPass(char *pass)
{
	printf("Nhap pass moi: ");
	getPassword(pass);
}


int isPassWordSame(User u, User f)
{
	if (strcmp(u.password, f.password) == 0) {
		return 1;
	}
	return 0;
}
