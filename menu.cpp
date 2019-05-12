#include "menu.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "login.h"
#include "utility.h"

#include "function.h"

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

	showTitle(MAIN);
	printf("1. Dang nhap\n");
	printf("2. Thoat chuong trinh\n");

	int item = getChoice();
	menuLogin_handler(u, item);
}

void menuLogin_handler(User &u, int item) {
	
	switch (item) {
		case 1: {
			system("cls");
			showTitle(MAIN);
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
		default: {
			break;
		}
	}
}

void menuSub(User &u) {
	showTitle(MAIN);

	printf("1. Tai khoan\n");
	printf("2. Quan li doc gia\n");
	printf("3. Quan li sach\n");
	printf("4. Lap phieu muon sach\n");
	printf("5. Lap phieu tra sach\n");
	printf("6. Thong ke\n");
	printf("7. Dang xuat");

	int item = getChoice();
	menuSub_handler(u, item);
}

void menuSub_handler(User &u, int item) {

	system("cls");
	switch (item) {
		case 1: {
			menuUser(u);
			break;
		}
		case 2: {
			menuReader(u);
			break;
		}
		case 3: {
			menuBook(u);
			break;
		}
		case 7: {
			DangXuat(u);
			showInfo("Dang xuat thanh cong");
			menuMain(u);
			break;
		}
		default: {
			showInfo("Chuc nang dang duoc xay dung");
			menuSub(u);
			break;
		}

	}
}



/*========================Tài khoản=============================*/
void menuUser(User &u) {
	showTitle(USER);
	printf("1. Doi mat khau\n");
	printf("2. Thay doi thong tin\n");
	printf("3. Tao nguoi dung\n");
	printf("4. Quay lai\n");


	int item = getChoice();
	menuUser_handler(u, item);
	
}

void menuUser_handler(User &u, int item)
{
	if (item <= 0 || item >= 4) {
		system("cls");
		menuMain(u);
		return;
	}
	
	system("cls");
	
	switch (item) {
		case 1: {
			changePass(u);
			break;
		}
		case 2: {
			changeInfo(u);
			break;
		}
		case 3: {
			createUser(u);
			break;
		}
	}


	menuChoice(u);
}

void menuChoice(User &u)
{
	printf("\n\n\n");
	printf("Nhan bat ki nut nao de quay lai");

	_getch();
	system("cls");
	menuUser(u);
}

/*========================Độc giả=============================*/
void menuReader(User &u)
{
	ListReader lReader;
	initListReader(lReader);
	loadListReader(lReader);

	showTitle(READER);

	printf("1. Xem danh sach doc gia trong thu vien\n");
	printf("2. Them doc gia\n");
	printf("3. Chinh sua doc gia\n");
	printf("4. Xoa doc gia\n");
	printf("5. Tim kiem doc gia theo ho ten\n");
	printf("6. Tim kiem doc gia theo CMND\n");
	printf("7. Luu thong tin doc gia vao file\n");
	printf("8. Quay lai");

	int item = getChoice();
	menuReader_handler(u, lReader, item);
}
void menuReader(User &u, ListReader &lReader)
{
	showTitle(READER);

	printf("1. Xem danh sach doc gia trong thu vien\n");
	printf("2. Them doc gia\n");
	printf("3. Chinh sua doc gia\n");
	printf("4. Xoa doc gia\n");
	printf("5. Tim kiem doc gia theo ho ten\n");
	printf("6. Tim kiem doc gia theo CMND\n");
	printf("7. Luu thong tin doc gia vao file\n");
	printf("8. Quay ve menu chinh");

	int item = getChoice();
	menuReader_handler(u, lReader, item);
}
void menuReader_handler(User &u, ListReader &lReader, int item)
{
	if (item <= 0 || item >= 8) {
		system("cls");
		menuMain(u);
		return;
	}
	if (item == 7) {

		writeListReaderToFile(lReader);
		system("cls");
		showInfo("Luu thanh cong");
		menuReader(u);
		return;
	}

	system("cls");
	
	switch (item) {
		case 1: {
			viewReader(u, lReader);
			break;
		}
		case 2: {
			addReader(u, lReader);
			break;
		}
		case 3: {
			editReader(u, lReader);
			break;
		}
		case 4: {
			deleteReader(u, lReader);
			break;
		}
		case 5: {
			findReaderAsName(u, lReader);
			break;
		}
		case 6: {
			findReaderAsCMND(u, lReader);
			break;
		}
	}


	menuChoice(u, lReader);
}
void menuChoice(User &u, ListReader &lReader)
{
	printf("\n\n\n");
	printf("Nhan bat ki nut nao de quay lai");

	_getch();
	system("cls");
	menuReader(u, lReader);
}


/*========================Độc giả=============================*/
void menuBook(User &u)
{
	ListBook lBook;
	initListBook(lBook);
	loadListBook(lBook);

	showTitle(BOOK);

	printf("1. Xem danh sach cac sach hien co trong thu vien\n");
	printf("2. Them sach\n");
	printf("3. Chinh sua sach\n");
	printf("4. Xoa sach\n");
	printf("5. Tim kiem sach theo ten sach\n");
	printf("6. Tim kiem sach theo ISBN\n");
	printf("7. Luu thong tin sach vao file\n");
	printf("8. Quay ve menu chinh");


	int item = getChoice();
	menuBook_handler(u, lBook, item);
}
void menuBook(User &u, ListBook &lBook)
{
	showTitle(BOOK);

	printf("1. Xem danh sach cac sach hien co trong thu vien\n");
	printf("2. Them sach\n");
	printf("3. Chinh sua sach\n");
	printf("4. Xoa sach\n");
	printf("5. Tim kiem sach theo ten sach\n");
	printf("6. Tim kiem sach theo ISBN\n");
	printf("7. Luu thong tin sach vao file\n");
	printf("8. Quay lai");

	int item = getChoice();
	menuBook_handler(u, lBook, item);
}
void menuBook_handler(User &u, ListBook &lBook, int item)
{
	if (item <= 0 || item >= 8) {
		system("cls");
		menuMain(u);
		return;
	}
	if (item == 7) {

		writeListBookToFile(lBook);
		system("cls");
		showInfo("Luu thanh cong");
		menuBook(u);
		return;
	}

	system("cls");
	
	switch (item) {
		case 1: {
			viewBook(u, lBook);
			break;
		}
		case 2: {
			addBook(u, lBook);
			break;
		}
		case 3: {
			editBook(u, lBook);
			break;
		}
		case 4: {
			deleteBook(u, lBook);
			break;
		}
		case 5: {
			findBookAsName(u, lBook);
			break;
		}
		case 6: {
			findBookAsISBN(u, lBook);
			break;
		}
	}

	
	menuChoice(u, lBook);

}
void menuChoice(User &u, ListBook &lBook)
{
	printf("\n\n\n");
	printf("Nhan bat ki nut nao de quay lai");

	_getch();
	system("cls");
	menuBook(u, lBook);
}