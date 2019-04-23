#include "menu.h"
#include "const.h"
#include <stdio.h>
#include "login.h"

void menuMain(User &u)
{
	if (isVaildUser(u)) {
		menuLogin(u);
	}
	else {
		menuSub(u);
	}
}

void menuLogin(User &u) {
	printf("1. Dang nhap\n");
	printf("2. Thoat chuong trinh\n");

	int item;
	scanf("%d", &item);

	menuLogin_handler(u, item);
}

void menuLogin_handler(User &u, int item) {
	
	switch (item) {
		case 0: {
			//Login(u);
			break;
		}
		case 1: {
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

	int item;
	scanf("%d", &item);
	menuSub_handler(u, item);
}

void menuSub_handler(User &u, int item) {
	switch (item) {
	case 0: break;
	default: break;

	}
}