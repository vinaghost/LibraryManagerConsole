#include "menu.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>

#include "login.h"
#include "utility.h"

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
	printf("1. Dang nhap\n");
	printf("2. Thoat chuong trinh\n");

	int item = getChoice();
	menuLogin_handler(u, item);
}

void menuLogin_handler(User &u, int item) {
	
	switch (item) {
		case 1: {
			system("cls");
			LOGIN_CASE Case = Login(u);
			system("cls");
			switch (Case) {
				
				case ACCEPT: {
					printf("Dang nhap thanh cong\n");

					menuSub(u);
					break;
				}
				case WRONG_PASSWORD: {
					printf("Sai password\n");
					menuLogin(u);
					break;
				}
				case WRONG_USERNAME: {
					printf("Username khong ton tai\n");
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

void menuSub(User &u) {
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
	switch (item/7) {
	case 0: {
		system("cls");
		printf("Chuc nang dang duoc xay dung\n");
		menuSub(u);
	}
	case 7: {
		break;
	}

	}
}