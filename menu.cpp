#include "menu.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>

#include "login.h"
#include "utility.h"

#include "reader.h"
#include "LinkedListReader.h"

void menuMain(User &u)
{
	if (!isVaildUser(u)) {
		menuLogin(u);
	}
	else {
		menuSub(u);
	}
}

void menuLogin(User &u) {
	showTitle();
	printf("1. Dang nhap\n");
	printf("2. Thoat chuong trinh\n");

	int item = getChoice();
	menuLogin_handler(u, item);
}

void menuLogin_handler(User &u, int item) {
	
	switch (item) {
		case 1: {
			system("cls");
			showTitle();
			printf("Dang nhap: \n");
			LOGIN_CASE Case = Login(u);
			system("cls");
			switch (Case) {
				
				case ACCEPT: {
					showInfo("Dang nhap thanh cong");

					menuSub(u);
					break;
				}
				case WRONG_PASSWORD: {
					showInfo("Sai password");
					menuLogin(u);
					break;
				}
				case WRONG_USERNAME: {
					showInfo("Username khong ton tai");
					menuLogin(u);
					break;
				}
			}
		}
		case 2: {
			break;
		}
	}
}

void menuReader(User &u)
{
	ListReader lReader;
	initListReader(lReader);

	showTitle();

	printf("1. Xem danh sach doc gia trong thu vien\n");
	printf("2. Them doc gia\n");
	printf("3. Quan li sach\n");
	printf("4. Tim kiem doc gia theo ho ten\n");
	printf("5. Tim kiem doc gia theo CND\n");
	printf("6. Quay ve menu chinh");

	int item = getChoice();
	menuReader_handler(u, lReader, item);
}

void menuReader_handler(User &u, ListReader lReader, int item)
{


}

void menuSub(User &u) {
	showTitle();

	printf("1. Tai khoan\n");
	printf("2. Quan li doc gia\n");
	printf("3. Quan li sach\n");
	printf("4. Lap phieu muon sach\n");
	printf("5. Lap phieu tra sach\n");
	printf("6. Thong ke\n");
	printf("7. Thoat chuong trinh");

	int item = getChoice();
	menuSub_handler(u, item);
}

void menuSub_handler(User &u, int item) {
	switch (item) {
	case 1: {
		system("cls");
		showInfo("Chuc nang dang duoc xay dung");
		menuSub(u);
	}
	case 2: {
		system("cls");
		menuReader(u);
	}
	case 7: {
		break;
	}

	}
}