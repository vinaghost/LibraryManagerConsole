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

void menuSub(User &u) {


	showInfo("Dang load du lieu . . .");

	ListReader lReader;
	initListReader(lReader);
	loadListReader(lReader);

	ListBook lBook;
	initListBook(lBook);
	loadListBook(lBook);

	ListPhieu lPhieuMuon;
	initListPhieu(lPhieuMuon);
	loadListPhieu(lPhieuMuon, MUON);

	ListPhieu lPhieuTra;
	initListPhieu(lPhieuTra);
	loadListPhieu(lPhieuTra, TRA);

	clearScreen();

	while (1) {
		showTitle(MAIN);

		printf("1. Tai khoan\n");
		printf("2. Quan li doc gia\n");
		printf("3. Quan li sach\n");
		printf("4. Muon/Tra sach\n");
		printf("5. Thong ke\n");
		printf("6. Dang xuat");

		int item = getChoice();

		clearScreen();

		switch (item) {
			case 1: {
				menuUser(u);
				break;
			}
			case 2: {
				menuReader(u, lReader);
				break;
			}
			case 3: {
				menuBook(u, lBook);
				break;
			}
			case 4: {
				menuPhieu(u, lPhieuMuon, lPhieuTra, lBook, lReader);
				break;
			}
			case 6: {
				DangXuat(u);
				showInfo("Dang xuat thanh cong");
				menuMain(u);
				return;
			}
			default: {
				showInfo("Chuc nang dang duoc xay dung");
				menuSub(u);
				break;
			}

		}
	}


	deleteListBook(lBook);
	deleteListReader(lReader);
	deleteListPhieu(lPhieuMuon);
	deleteListPhieu(lPhieuTra);
}

void menuChoice()
{
	printf("\n\n\n");
	printf("Nhan bat ki nut nao de quay lai");

	_getch();
	clearScreen();
}
/*========================Đăng nhập=============================*/
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

/*========================Tài khoản=============================*/
void menuUser(User &u) {
	while (1) {
		showTitle(USER);
		printf("1. Doi mat khau\n");
		printf("2. Thay doi thong tin\n");
		printf("3. Tao nguoi dung\n");
		printf("4. Quay lai\n");


		int item = getChoice();

		if (item <= 0 || item >= 4) {
			clearScreen();
			return;
		}

		clearScreen();

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


		menuChoice();
	}
}
/*========================Độc giả=============================*/
void menuReader(User &u, ListReader &lReader)
{

	while (1) {
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

		if (item <= 0 || item >= 8) {
			clearScreen();
			return;
		}
		if (item == 7) {
			clearScreen();
			showInfo("Dang luu du lieu");
			writeListReaderToFile(lReader);
			showInfo("Luu thanh cong");

			continue;
		}

		clearScreen();

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
		menuChoice();
	}
}

/*========================Sách=============================*/
void menuBook(User &u, ListBook &lBook)
{
	while (1) {
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

		if (item <= 0 || item >= 8) {
			clearScreen();
			return;
		}
		if (item == 7) {

			clearScreen();
			showInfo("Dang luu du lieu");
			writeListBookToFile(lBook);
			clearScreen();
			showInfo("Luu thanh cong");
			continue;
		}

		clearScreen();

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
		
		menuChoice();
	}
}

/*========================Phiếu=============================*/
void menuPhieu(User &u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader)
{
	while (1) {
		showTitle(CARD);

		printf("1. Muon sach\n");
		printf("2. Tra sach\n");
		printf("3. Luu thong tin vao file\n");
		printf("4. Quay ve menu chinh");


		int item = getChoice();
		
		if (item <= 0 || item >= 4) {
			clearScreen();
			return;
		}
		if (item == 3) {

			clearScreen();
			showInfo("Dang luu du lieu");

			writeListPhieuToFile(lPhieuMuon, MUON);
			writeListPhieuToFile(lPhieuTra, TRA);

			clearScreen();
			showInfo("Luu thanh cong");
			continue;
		}

		clearScreen();

		switch (item) {
			case 1: {
				creatTheMuon(u, lPhieuMuon, lPhieuTra, lBook, lReader);
				break;
			}
			case 2: {
				creatTheTra(u, lPhieuMuon, lPhieuTra, lBook, lReader);
				break;
			}
		}


		menuChoice();
	}
}

/*========================Thống kê=============================*/
void menuStatistics(User & u, ListPhieu & lPhieuMuon, ListPhieu & lPhieuTra, ListBook & lBook, ListReader & lReader)
{
	while (1) {
		showTitle(STATISTICS);

		printf("1. So luong sach trong thu vien\n");
		printf("2. So luong sach theo the loai\n");
		printf("3. Thong ke so luong doc gia\n");
		printf("4. Thong ke so luong doc gia theo gioi tinh\n");
		printf("5. Thong ke so luong sach dang duoc muon\n");
		printf("6. Thong ke so luong sach tre han\n");
		printf("7. Quay ve menu chinh");


		int item = getChoice();

		if (item <= 0 || item >= 7) {
			clearScreen();
			return;
		}
	
		clearScreen();

		switch (item) {
			case 1: {
				viewNumBook(u, lBook);
				break;
			}
			case 2: {
				viewNumBookAsType(u, lBook);
				break;
			}
			case 3: {
				viewNumBook(u, lBook);
				break;
			}
			case 4: {
				creatTheTra(u, lPhieuMuon, lPhieuTra, lBook, lReader);
				break;
			}
			case 5: {
				viewNumBook(u, lBook);
				break;
			}
			case 6: {
				creatTheTra(u, lPhieuMuon, lPhieuTra, lBook, lReader);
				break;
			}
		}


		menuChoice();
	}
}
