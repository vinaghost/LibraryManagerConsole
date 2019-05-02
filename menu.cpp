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
	loadListReader(lReader);

	showTitle();

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
void menuReader(User &u, ListReader &lReader)
{
	showTitle();

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
	if (item == 8) {
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
	FUNCTION_CASE result;
	switch (item) {
		case 1: {
			result = viewReader(u, lReader);
			break;
		}
		case 2: {
			result = addReader(u, lReader);
			break;
		}
		case 3: {
			result = editReader(u, lReader);
			break;
		}
		case 4: {
			result = deleteReader(u, lReader);
			break;
		}
		case 5: {
			result = findReaderAsName(u, lReader);
			break;
		}
		case 6: {
			result = findReaderAsCMND(u, lReader);
			break;
		}
	}

	switch (result) {
		case INVAILD: {
			showInfo("Tai khoan cua ban khong co quyen truy cap lenh nay\n");
			break;
		}
		case ERROR: {
			showInfo("Co loi xay ra vui long khoi dong lai chuong trinh\n");
			break;
		}
		case NOT_FOUND: {
			showInfo("Khong tim thay sach\n");
			break;
		}
	}

	menuChoice(u, lReader);
}

void menuReader_sub(User &u, ListReader &lReader, ListReader &findReader)
{
	printf("\n\n\n");
	printf("1. Thay doi thong tin doc gia\n");
	printf("2. Xoa doc gia\n");
	printf("3. Quay lai");

	int item = getChoice();
	menuReader_sub_handler(u, lReader, findReader, item);
}
void menuReader_sub_handler(User &u, ListReader &lReader, ListReader &findReader, int item)
{
	if (item == 3) {
		menuReader(u, lReader);
		return;
	}

	printf("Chon doc gia de thuc hien: \n\n");
	showListReader(findReader);

	int item_ = getChoice();

	printf("Ban da chon doc gia #%d", item);
	printf("Tinh nang van dang duoc xay dung\n");
	printf("Nhan bat ki phim nao de quay lai");
	_getch();
	menuReader(u, lReader);
}

void menuChoice(User &u, ListReader &lReader)
{
	printf("\n");
	printf("Nhan bat ki nut nao de quay lai");

	_getch();
	system("cls");
	menuReader(u, lReader);
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

	system("cls");
	switch (item) {
		case 2: {
			menuReader(u);
			break;
		}
		case 3: {
			menuBook(u);
			break;
		}
		case 7: {
			break;
		}
		default: {
			showInfo("Chuc nang dang duoc xay dung");
			menuSub(u);
			break;
		}

	}
}




//////////////////Menu Book/////////////////
void menuBook(User &u)
{
	ListBook lBook;
	initListBook(lBook);
	loadListBook(lBook);

	showTitle();

	printf("1. Xem danh sach cac sach hien co trong thu vien\n");
	printf("2. Them sach\n");
	printf("3. Tim kiem sach theo ten sach\n");
	printf("4. Tim kiem sach theo ISBN\n");
	printf("5. Luu thong tin sach vao file\n");
	printf("6. Quay ve menu chinh");

	int item = getChoice();
	menuBook_handler(u, lBook, item);
}
void menuBook(User &u, ListBook &lBook)
{
	showTitle();

	printf("1. Xem danh sach cac sach hien co trong thu vien\n");
	printf("2. Them sach\n");
	printf("3. Tim kiem sach theo ten sach\n");
	printf("4. Tim kiem sach theo ISBN\n");
	printf("5. Tim kiem sach theo ten sach\n");
	printf("6. Tim kiem sach theo ISBN\n");
	printf("7. Luu thong tin sach vao file\n");
	printf("8. Quay ve menu chinh");

	int item = getChoice();
	menuBook_handler(u, lBook, item);
}
void menuBook_handler(User &u, ListBook &lBook, int item)
{
	if (item == 8) {
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
	FUNCTION_CASE result;
	switch (item) {
		case 1: {
			result = viewBook(u, lBook);
			break;
		}
		case 2: {
			result = addBook(u, lBook);
			break;
		}
		case 3: {
			result = editBook(u, lBook);
			break;
		}
		case 4: {
			result = deleteBook(u, lBook);
			break;
		}
		case 5: {
			result = findBookAsName(u, lBook);
			break;
		}
		case 6: {
			result = findBookAsISBN(u, lBook);
			break;
		}
	}

	switch (result) {
		case INVAILD: {
			system("cls");
			showInfo("Tai khoan cua ban khong co quyen truy cap lenh nay\n");
			break;
		}
		case ERROR: {
			system("cls");
			showInfo("Co loi xay ra vui long khoi dong lai chuong trinh\n");
			break;
		}
		case NOT_FOUND: {
			system("cls");
			showInfo("Khong tim thay sach\n");
			break;
		}
	}
	
	menuChoice(u, lBook);

}

void menuBook_sub(User &u, ListBook &lBook, ListBook &findBook)
{
	printf("\n\n\n");
	printf("1. Thay doi thong tin sach\n");
	printf("2. Xoa sach\n");
	printf("3. Quay lai");

	int item = getChoice();
	menuBook_sub_handler(u, lBook, findBook, item);
}
void menuBook_sub_handler(User &u, ListBook &lBook, ListBook &findBook, int item)
{
	if (item == 3) {
		menuBook(u, lBook);
		return;
	}

	printf("Chon sach de thuc hien: \n\n");
	showListBook(findBook);

	int item_ = getChoice();

	printf("Ban da chon sach #%d", item);
	printf("Tinh nang van dang duoc xay dung\n");
	printf("Nhan bat ki phim nao de quay lai");
	_getch();
	menuBook(u, lBook);
}

void menuChoice(User &u, ListBook &lBook)
{
	printf("\n\n\n");
	printf("Nhan bat ki nut nao de quay lai");

	_getch();
	system("cls");
	menuBook(u, lBook);
}