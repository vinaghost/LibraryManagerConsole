#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*========================1. Tài khoản==================================*/
void changePass(User &u)
{
	if (!isHavePerm(u.permission, CHANGEPASS)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

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
		int delete_line = u.location;

		FILE *root, *tmp;
		char ch;
		int count = 1;

		char pass[PASS_LENGTH];

		newPass(pass);


		root = fopen(USER_FILE, "r");
		tmp = fopen(TMP_FILE, "w");

		if (root == NULL || tmp == NULL) {
			showInfo("Da co loi xa ra xin vui long khoi dong lai chuong trinh, neu loi xay ra lien tuc xin vui long bao KTV");
			return;
		}

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

		fclose(root);
		char* birth = DateToString(u.ngaySinh);
		fprintf(tmp, "%s, %s, %d, %s, %s, %s, %s, %d, 1\n", u.name, pass, u.permission, u.HoTen, u.CMND, birth, u.DiaChi, u.Nam);
		free(birth);
		fclose(tmp);

		remove(USER_FILE);
		rename(TMP_FILE, USER_FILE);
	}

	showInfo("Da doi mat khau thanh cong");
	return;
}

void changeInfo(User &u)
{
	if (!isHavePerm(u.permission, CHANGEINFO)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	if (strcmp(u.name, AD_USERNAME) == 0) {

		printf("Nhap thong tin: \n");
		nhapInf(u);

		FILE* root = fopen(ADMIN_FILE, "w");
		char *birth = DateToString(u.ngaySinh);
		fprintf(root, "%s, %s, %s, %s, %s, %d\n", u.password, u.HoTen, u.CMND, birth, u.DiaChi, u.Nam);
		free(birth);

		fclose(root);

	}
	else {
		int delete_line = u.location;

		FILE *root, *tmp;
		char ch;
		int count = 1;
		
		printf("Nhap thong tin: \n");
		nhapInf(u);

		root = fopen(USER_FILE, "r");
		tmp = fopen(TMP_FILE, "w");

		if (root == NULL || tmp == NULL) {
			showInfo("Da co loi xa ra xin vui long khoi dong lai chuong trinh, neu loi xay ra lien tuc xin vui long bao KTV");
			return;
		}

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

		fclose(root);
		char* birth = DateToString(u.ngaySinh);
		fprintf(tmp, "%s, %s, %d, %s, %s, %s, %s, %d, 1\n", u.name, u.password, u.permission, u.HoTen, u.CMND, birth, u.DiaChi, u.Nam);
		free(birth);
		fclose(tmp);

		remove(USER_FILE);
		rename(TMP_FILE, USER_FILE);
	}


	showInfo("Da doi thong tin thanh cong");
	return;
}

void createUser(User &u)
{
	if (!isHavePerm(u.permission, CREATUSER )) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	User c;
	initUser(c);
	int result = addUser(c);

	if (result == -1) {
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

	if (lReader.head == NULL) {
		showInfo("Khong tim thay.");
		return;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeReader* r = getNodeReaderPos(lReader, stt);

	if (r == NULL) {
		showInfo("Khong tim thay.");
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

	if (lReader.head == NULL) {
		showInfo("Khong tim thay.");
		return;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeReader* r = getNodeReaderPos(lReader, stt);

	if (r == NULL) {
		showInfo("Khong tim thay.");
		return;
	}

	printf("Doc gia da chon: ");
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

	printf("Nhap ho ten cua doc gia: ");
	char* name = nhapReader_HoTen();

	printf("Dang tim . . .\n");
	int result = showListReader(lReader , name, HO_TEN);
	free(name);
	if (result < 1) {
		showInfo("Khong tim thay.");
		return;
	}

	return;
}

void findReaderAsCMND(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASCMND)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	printf("Nhap CMND cua doc gia: ");
	char* cmnd = nhapReader_HoTen();

	printf("Dang tim . . .\n");

	int result = showListReader(lReader, cmnd, CMND);

	free(cmnd);

	if (result < 1) {
		showInfo("Khong tim thay.");
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

	Book r;
	nhapBook(r);

	addFirst(lBook, r);

	return;
}

void editBook(User u, ListBook &lBook)
{
	if (!isHavePerm(u.permission, EDITREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	if (lBook.head == NULL) {
		showInfo("Khong tim thay.");
		return;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeBook* r = getNodeBookPos(lBook, stt);

	if (r == NULL) {
		showInfo("Khong tim thay.");
		return;
	}

	printf("Sach da chon: \n");
	showBook(r->data);

	printf("Nhap thong tin moi cho doc gia: \n");
	nhapBook(r->data);

	printf("\n\nDa cap nhat thanh cong doc gia.\n");
	return;
}

void deleteBook(User u, ListBook & lBook)
{
	if (!isHavePerm(u.permission, DELETEREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	if (lBook.head == NULL) {
		showInfo("Khong tim thay.");
		return;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeBook* r = getNodeBookPos(lBook, stt);

	if (r == NULL) {
		showInfo("Khong tim thay.");
		return;
	}

	printf("Doc gia da chon: ");
	showBook(r->data);

	deletePos(lBook, stt);

	printf("\n\nDa xoa thanh cong sach.\n");
	return;
}

void findBookAsName(User u, ListBook &lBook) {
	if (!isHavePerm(u.permission, FINDBOOKASNAME)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
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
void creatTheMuon(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader)
{
	if (!isHavePerm(u.permission, CREATMUONSACH)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	Phieu phieuMuon;

	nhapPhieuMuon_info(phieuMuon);

	int pos = getPosReader(lReader, phieuMuon.MS);

	if (pos == -1) {
		showInfo("Ma so doc gia nay khong ton tai trong he thong.");
		return;
	}
	int num;
	printf("So luong sach muon: ");
	scanf("%d", &num);

	Phieu pMuon;
	nhapPhieuMuon_info(phieuMuon, pMuon);
	for (int i = 0; i < num; i++) {
		
		printf("] Sach #%d: \n", i + 1);
		printf("Nhap ISBN cua sach: ");
		gets_s(pMuon.ISBN, ISBN_LENGTH);

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

void creatTheTra(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader)
{
	if (!isHavePerm(u.permission, CREATTRASACH)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	Phieu phieuTra;

	nhapPhieuTra_info(phieuTra);

	int pos = getPosReader(lReader, phieuTra.MS);

	if (pos == -1) {
		showInfo("Ma so doc gia nay khong ton tai trong he thong.");
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
		nBook->data.SoLuong++;

		int posPhieuMuon = getPosFromData(lPhieuMuon, pTra.MS, pTra.ISBN);

		deletePos(lPhieuMuon, posPhieuMuon);
		addFirst(lPhieuTra, pTra);

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

	int dem = getTotal(lBook);
	printf("So luong sach co trong thu vien: %d", dem);
}

void viewNumReader(User u, ListReader lReader)
{
	if (!isHavePerm(u.permission, VIEWNUMREADER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}

	int dem = getTotal(lReader);
	printf("So luong sach co trong thu vien: %d", dem);
}

void viewNumBookAsType(User u, ListBook lBook)
{
	if (!isHavePerm(u.permission, VIEWNUMBOOKASTYPE)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	int dem = lBook.totalType;
	for (int i = 0; i < dem; i++)
	{
		printf("The loai sach: %s  -  So luong: %d", (lBook.typeArray+i)->type, (lBook.typeArray + i)->type);
	}
}

void viewNumReaderAsGender(User u, ListReader lReader)
{
	if (!isHavePerm(u.permission, VIEWNUMREADERASGENDER)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	//aReader[1] chua so luong raeder nam, aReader[2] chua so luong reader nu
	NodeReader *current, *next;
	current = lReader.head;
	while (current != NULL) {
		if (current->data.nam == 1)
		{
			aReader[1].nam = aReader[1].nam + 1;
		}
		else if (current->data.nam == 0)
		{
			aReader[2].nam = aReader[2].nam + 1;
		}
		next = current->next;
		current = next;
	}
	printf("So luong doc gia nam: %d", aReader[1].nam);
	printf("So luong doc gia nu: %d", aReader[2].nam);
}

void viewBookAsBorrow(User u, ListPhieu lPhieu)
{
	if (!isHavePerm(u.permission, VIEWNUMBOOKASBORROW)) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	printf("So luong sach dang duoc muon la: %d\n", getTotal(lPhieu));
}


void viewNumReaderLate(User u, ListPhieu lPhieu)
{
	if (!isHavePerm(u.permission, VIEWNUMREADERLATE )) {
		showInfo("Ban khong co quyen truy cap vao muc nay.");
		return;
	}
	int dem = 0;
	Date today = getToday();
	NodePhieu *current, *next;
	current = lPhieu.head;
	while (current != NULL) {
		if (current->data.type == MUON)
		{
			bool kt = ktngay(current->data.ngayTra, today);
			if (kt == true)
			{
				dem++;
			}
		}
		next = current->next;
		current = next;
	}
	printf("So luong sach dang tre han la: %d\n", dem);
}