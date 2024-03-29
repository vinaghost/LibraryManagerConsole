#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*========================1. Tài khoản==================================*/
void changePass(User &u, ListUser &lUser)
{
	if (!isHavePerm(u.permission, CHANGEPASS)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	showTitle("Doi mat khau ");


	if (strcmp(u.name, AD_USERNAME) == 0) {
		char pass[PASS_LENGTH];

		newPass(pass);

		FILE* root = fopen(ADMIN_FILE, "w");
		char *birth = DateToString(u.ngaySinh);
		fprintf(root, "%s, %s, %s, %s, %s, %d\n",  pass, u.HoTen, u.CMND, birth, u.DiaChi, u.Nam);
		free(birth);

		fclose(root);

	}
	else {
		int pos = u.location;


		char pass[PASS_LENGTH];

		newPass(pass);

		NodeUser* nUser = getNodeUserPos(lUser, pos);

		strcpy(nUser->data.password, pass);
	}

	showInfo("Da doi mat khau thanh cong");
	return;
}

void changeInfo(User &u, ListUser &lUser)
{
	if (!isHavePerm(u.permission, CHANGEINFO)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Doi thong tin tai khoan");

	if (strcmp(u.name, AD_USERNAME) == 0) {

		printf("Nhap thong tin: \n");
		nhapInf(u);

		FILE* root = fopen(ADMIN_FILE, "w");
		if (root == NULL) {
			showInfo("Da xay ra loi, vui long lien he KTV");
			return;
		}
		char *birth = DateToString(u.ngaySinh);
		fprintf(root, "%s, %s, %s, %s, %s, %d\n", u.password, u.HoTen, u.CMND, birth, u.DiaChi, u.Nam);
		free(birth);

		fclose(root);

	}
	else {
		int pos = u.location;

		printf("Nhap thong tin: \n");
		nhapInf(u);

		NodeUser* nUser = getNodeUserPos(lUser, pos);

		strcpy(nUser->data.HoTen, u.HoTen);
		strcpy(nUser->data.CMND, u.CMND);
		strcpy(nUser->data.DiaChi, u.DiaChi);

		nUser->data.ngaySinh = u.ngaySinh;
		nUser->data.Nam = u.Nam;
	}


	showInfo("Da doi thong tin thanh cong");
	return;
}

void createUser(User &u, ListUser &lUser)
{
	if (!isHavePerm(u.permission, CREATUSER )) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Tao tai khoan");

	User c;
	initUser(c);
	printf("Nhap thong tin tai khoan:\n");

	nhapUser(u);
	nhapInf(u);

	NodeUser* result = addFirst(lUser, u);

	if (result == NULL) {
		showInfo("Da co loi xa ra xin vui long khoi dong lai chuong trinh, neu loi xay ra lien tuc xin vui long bao KTV");
		return;
	}

	showInfo("Ghi thong tin tai khoan thanh cong");
	return;
}

/*========================2. Quản lí độc giả==================================*/
void viewReader(User u, ListReader lReader)
{
	if ( !isHavePerm(u.permission, VIEWREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Danh sach doc gia");

	if (lReader.head == NULL) {
		showInfo("Khong co doc gia trong he thong");
		return;
	}
	int result = showListReader(lReader);

	if (result == -1) {
		showInfo("Da co loi xa ra xin vui long khoi dong lai chuong trinh, neu loi xay ra lien tuc xin vui long bao KTV");
		return;
	}

	return;
}

void addReader(User u, ListReader &lReader)
{
	if (!isHavePerm(u.permission, ADDREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	showTitle("Them doc gia");

	Reader r;
	nhapReader(r);

	sprintf(r.MS, "READ%05d", MSToNum(lReader.tail->data.MS) + 1);

	addFirst(lReader, r);

	showInfo("Them doc gia thanh cong");
	return;
}

void editReader(User u, ListReader &lReader)
{
	if (!isHavePerm(u.permission, EDITREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	showTitle("Sua doi thong tin doc gia");
	if (lReader.head == NULL) {
		showInfo("Trong he thong khong co doc gia nao.");
		return;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);
	clearEnter();

	NodeReader* r = getNodeReaderPos(lReader, stt);

	if (r == NULL) {
		showInfo("Khong tim thay doc gia.");
		return;
	}

	printf("Doc gia da chon: \n");
	showReader(r->data);

	printf("Nhap thong tin moi cho doc gia: \n");
	nhapReader(r->data);

	showInfo("Da cap nhat thong tin thanh cong.");
	return;
}

void deleteReader(User u, ListReader &lReader)
{
	if (!isHavePerm(u.permission, DELETEREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Xoa doc gia");

	if (lReader.head == NULL) {
		showInfo("Trong he thong khong co doc gia nao.");
		return;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);
	clearEnter();

	NodeReader* r = getNodeReaderPos(lReader, stt);

	if (r == NULL) {
		showInfo("Khong tim thay doc gia.");
		return;
	}

	printf("Doc gia da chon: \n");
	showReader(r->data);

	deletePos(lReader, stt);

	showInfo("Da xoa thanh cong doc gia.");
	return;
}

void findReaderAsName(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASNAME)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Tim thong tin doc gia theo ten");

	if (lReader.head == NULL) {
		showInfo("Trong he thong khong co doc gia nao.");
		return;
	}

	printf("Nhap ho ten cua doc gia: ");
	char* name = nhapReader_HoTen();

	printf("Dang tim . . .\n");
	int result = showListReader(lReader , name, HO_TEN);
	free(name);
	if (result < 1) {
		showInfo("Khong tim thay doc gia.");
		return;
	}

	return;
}

void findReaderAsCMND(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASCMND)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	showTitle("Tim doc gia theo CMND");

	if (lReader.head == NULL) {
		showInfo("Trong he thong khong co doc gia nao.");
		return;
	}

	printf("Nhap CMND cua doc gia: ");
	char* cmnd = nhapReader_CMND();

	printf("Dang tim . . .\n");

	int result = showListReader(lReader, cmnd, CMND);

	free(cmnd);

	if (result < 1) {
		showInfo("Khong tim thay doc gia.");
		return;
	}
	return;
}

/*========================3. Quản lí sách==================================*/
void viewBook(User u, ListBook lBook)
{
	if (!isHavePerm(u.permission, VIEWBOOK)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Xem danh sach sach trong he thong");

	if (lBook.head == NULL) {
		showInfo("Khong co sach trong he thong.");
		return;
	}

	int result = showListBook(lBook);

	if (result == -1) {
		showInfo("Da co loi xa ra xin vui long khoi dong lai chuong trinh, neu loi xay ra lien tuc xin vui long bao KTV");
		return;
	}
	return;
}

void addBook(User u, ListBook &lBook)
{
	if (!isHavePerm(u.permission, ADDBOOK)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Them sach");

	Book r;
	nhapBook(r);

	addFirst(lBook, r);

	int exist = 0;
	int count = lBook.totalType;
	for (int i = 0; i < count; i++) {
		if (strcmp(r.TheLoai, (lBook.typeArray + i)->type) == 0) {
			(lBook.typeArray + i)->SoLuong++;
			exist = 1;
			break;
		}
	}
	if (!exist) {
		lBook.typeArray = (TypeBook*)realloc(lBook.typeArray, count + 1);
		strcpy((lBook.typeArray + count)->type, r.TheLoai);
		(lBook.typeArray + count)->SoLuong = 1;

		lBook.totalType++;
	}

	return;
}

void editBook(User u, ListBook &lBook)
{
	if (!isHavePerm(u.permission, EDITREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Sua thong tin sach");

	if (lBook.head == NULL) {
		showInfo("Khong co sach trong he thong.");
		return;
	}

	int stt;
	printf("Nhap so thu tu cua sach: ");
	scanf("%d", &stt);
	clearEnter();
	NodeBook* r = getNodeBookPos(lBook, stt);

	if (r == NULL) {
		showInfo("Khong tim thay.");
		return;
	}

	printf("Sach da chon: \n");
	showBook(r->data);

	printf("Nhap thong tin moi cho sach: \n");
	nhapBook(r->data);

	showInfo("Da cap nhat thanh cong sach.");
	return;
}

void deleteBook(User u, ListBook & lBook)
{
	if (!isHavePerm(u.permission, DELETEREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	showTitle("Xoa sach");

	if (lBook.head == NULL) {
		showInfo("Khong co sach trong he thong.");
		return;
	}

	int stt;
	printf("Nhap so thu tu cua sach: ");
	scanf("%d", &stt);
	clearEnter();

	NodeBook* r = getNodeBookPos(lBook, stt);

	if (r == NULL) {
		showInfo("Khong tim thay.");
		return;
	}

	printf("Sach da chon: ");
	showBook(r->data);

	deletePos(lBook, stt);

	showInfo("Da xoa thanh cong sach.");
	return;
}

void findBookAsName(User u, ListBook &lBook) {
	if (!isHavePerm(u.permission, FINDBOOKASNAME)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Tim sach theo ten");

	if (lBook.head == NULL) {
		showInfo("Khong co sach trong he thong.");
		return;
	}

	printf("Nhap ten sach ");
	char* name = nhapBook_TenSach();

	printf("Dang tim . . .\n");
	int result = showListBook(lBook, name, TEN_SACH);
	free(name);

	if (result < 0) {
		showInfo("Khong tim thay.");
		return;
	}
	return;
}

void findBookAsISBN(User u, ListBook &lBook) {
	if (!isHavePerm(u.permission, FINDBOOKASISBN)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Tim sach theo ma ISBN");
	if (lBook.head == NULL) {
		showInfo("Khong co sach trong he thong.");
		return;
	}

	printf("Nhap ISBN cua sach: ");
	char* isbn = nhapBook_ISBN();

	printf("Dang tim . . .\n");
	int result = showListBook(lBook, isbn, ISBN);

	free(isbn);

	if (result < 0) {
		showInfo("Khong tim thay.");
		return;
	}
	return;
}

/*========================4. Thẻ mượn ==================================*/
void creatTheMuon(User u, ListPhieu &lPhieuMuon, ListBook &lBook, ListReader &lReader)
{
	if (!isHavePerm(u.permission, CREATMUONSACH)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	
	showTitle("Tao the muon");

	if (lReader.head == NULL) {
		showInfo("Khong co doc gia trong he thong.");
		return;
	}

	if (lBook.head == NULL) {
		showInfo("Khong co sach trong he thong.");
		return;
	}

	Phieu phieuMuon;

	nhapPhieuMuon_info(phieuMuon);

	int pos = getPosReader(lReader, phieuMuon.MS);

	if (pos == -1) {
		showInfo("Ma so doc gia nay khong ton tai trong he thong.");
		clearEnter();
		return;
	}
	int num;
	printf("So luong sach muon: ");
	scanf("%d", &num);
	clearEnter();

	Phieu pMuon;
	nhapPhieuMuon_info(phieuMuon, pMuon);
	for (int i = 0; i < num; i++) {
		
		printf("] Sach #%d: \n", i + 1);
		printf("Nhap ISBN cua sach: ");
		if (fgets(pMuon.ISBN, sizeof(pMuon.ISBN), stdin) != NULL) {
			size_t len = strlen(pMuon.ISBN);
			if (len > 0 && pMuon.ISBN[len - 1] == '\n') {
				pMuon.ISBN[--len] = '\0';
			}
		}
		NodeBook* nBook = getBookFromISBN(lBook, pMuon.ISBN);
		if (nBook == NULL) {
			printf("Ma ISBN khong ton tai trong he thong.\n");
			continue;
		}

		if (nBook->data.SoLuong < 1) {
			printf("Sach trong he thong khong con.\n");
			continue;
		}
		nBook->data.SoLuong--;

		addFirst(lPhieuMuon, pMuon);
	}

	showInfo("Da nhap thanh cong vao he thong.");

	return;
}

void creatTheTra(User u, ListPhieu &lPhieuMuon, ListBook &lBook, ListReader &lReader)
{
	if (!isHavePerm(u.permission, CREATTRASACH)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Tao the tra");

	if (lPhieuMuon.head == NULL) {
		showInfo("Khong co sach nao duoc muon.");
		return;
	}

	Phieu phieuTra;

	nhapPhieuTra_info(phieuTra);

	int pos = getPosReader(lReader, phieuTra.MS);

	if (pos == -1) {
		showInfo("Ma so doc gia nay khong ton tai trong he thong.");
		clearEnter();
		return;
	}

	int num;
	printf("So luong sach tra: ");
	scanf("%d", &num);
	clearEnter();
	Phieu pTra;
	nhapPhieuTra_info(phieuTra, pTra);
	for (int i = 0; i < num; i++) {

		printf("] Sach #%d: \n", i + 1);

		printf("Nhap ISBN cua sach: ");
		if (fgets(pTra.ISBN, ISBN_LENGTH, stdin) != NULL) {
			size_t len = strlen(pTra.ISBN);
			if (len > 0 && pTra.ISBN[len - 1] == '\n') {
				pTra.ISBN[--len] = '\0';
			}
		}

		NodeBook* nBook = getBookFromISBN(lBook, pTra.ISBN);

		if (nBook == NULL) {
			printf("Ma ISBN khong ton tai trong he thong.\n");
			continue;
		}

		int mat = 0;
		printf("Sach bi mat (1 la mat, 0 la con): ");
		mat = getChoice();
		while (mat != 0 && mat != 1) {
			mat = getChoice();
		}
		
		printf("%d\n", mat);

		int posPhieuMuon = getPosFromData(lPhieuMuon, pTra.MS, pTra.ISBN);
		NodePhieu* PhieuMuon = getNodePhieuPos(lPhieuMuon, posPhieuMuon);

		if (!mat) {
			nBook->data.SoLuong++;

			int cachNgay = getCachNgay(PhieuMuon->data.ngayTra, getToday());

			if (cachNgay > 0) {

				int tienPhat = 5000 * cachNgay;
				printf("Tra sach tre han %d ngay, phat %d dong\n", cachNgay, tienPhat);
			}

		}
		else {
			
			printf("Lam mat sach phat %d dong", 2 * nBook->data.Gia);
		}
		
		deletePos(lPhieuMuon, posPhieuMuon);

	}

	showInfo("Da nhap thanh cong vao he thong.");
	return;
}

/*=================================6. Thong ke ========================*/

void viewNumBook(User u, ListBook lBook)
{
	if (!isHavePerm(u.permission, VIEWNUMBOOK)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	showTitle("So luong sach");

	int dem = getTotal(lBook);
	printf("So luong sach co trong thu vien: %d", dem);
}

void viewNumReader(User u, ListReader lReader)
{
	if (!isHavePerm(u.permission, VIEWNUMREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("So luong doc gia");

	int dem = getTotal(lReader);
	printf("So luong doc gia trong he thong la: %d", dem);
}

void viewNumBookAsType(User u, ListBook lBook)
{
	if (!isHavePerm(u.permission, VIEWNUMBOOKASTYPE)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Phan loai sach theo the loai");
	int dem = lBook.totalType;
	for (int i = 0; i < dem; i++)
	{
		printf("The loai sach: %20s -  So luong: %d\n", (lBook.typeArray+i)->type, (lBook.typeArray + i)->SoLuong);
	}
}

void viewNumReaderAsGender(User u, ListReader lReader)
{
	if (!isHavePerm(u.permission, VIEWNUMREADERASGENDER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("Phan loai doc gia theo gioi tinh");

	printf("So luong doc gia nam: %d\n", lReader.nam);
	printf("So luong doc gia nu: %d", getTotal(lReader) - lReader.nam);
}

void viewBookAsBorrow(User u, ListPhieu lPhieu)
{
	if (!isHavePerm(u.permission, VIEWNUMBOOKASBORROW)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("So sach muon");


	printf("So luong sach dang duoc muon la: %d\n", getTotal(lPhieu));
}

void viewNumBookLate(User u, ListPhieu lPhieu)
{
	if (!isHavePerm(u.permission, VIEWNUMREADERLATE )) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	showTitle("So sach tre phieu tre");
	int dem = 0;
	NodePhieu *current;
	current = lPhieu.head;
	while (current != NULL) {
		if (kiemTraTre(current->data.ngayTra, getToday()))
		{
			dem++;
		}

		current = current->next;
	}
	printf("So luong sach dang tre han la: %d\n", dem);
}