#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*========================1. Tài khoản==================================*/


/*========================2. Quản lí độc giả==================================*/
FUNCTION_CASE viewReader(User u, ListReader lReader)
{
	if ( !isHavePerm(u.permission, VIEWREADER)) {
		return INVAILD;
	}

	int result = showListReader(lReader);

	if (result == -1) {
		return ERROR;
	}
	return SUCCESS;
}



FUNCTION_CASE addReader(User u, ListReader &lReader)
{
	if (!isHavePerm(u.permission, ADDREADER)) {
		return INVAILD;
	}

	Reader r;
	nhapReader(r);

	sprintf(r.MS, "READ%05d", MSToNum(lReader.tail->data.MS) + 1);

	addFirst(lReader, r);

	return SUCCESS;
}
FUNCTION_CASE editReader(User u, ListReader &lReader)
{
	if (!isHavePerm(u.permission, EDITREADER)) {
		return INVAILD;
	}

	if (lReader.head == NULL) {
		return NOT_FOUND;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeReader* r = getNodeReaderPos(lReader, stt);

	if (r == NULL) {
		return NOT_FOUND;
	}

	printf("Doc gia da chon: \n");
	showReader(r->data);

	printf("Nhap thong tin moi cho doc gia: \n");
	nhapReader(r->data);

	printf("\n\nDa cap nhat thanh cong doc gia.\n");
	return SUCCESS;
}
FUNCTION_CASE deleteReader(User u, ListReader &lReader)
{
	if (!isHavePerm(u.permission, DELETEREADER)) {
		return INVAILD;
	}

	if (lReader.head == NULL) {
		return NOT_FOUND;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeReader* r = getNodeReaderPos(lReader, stt);

	if (r == NULL) {
		return NOT_FOUND;
	}

	printf("Doc gia da chon: ");
	showReader(r->data);

	deletePos(lReader, stt);

	printf("\n\nDa xoa thanh cong doc gia.\n");
	return SUCCESS;
}
FUNCTION_CASE findReaderAsName(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASNAME)) {
		return INVAILD;
	}

	printf("Nhap ho ten cua doc gia: ");
	char* name = nhapReader_HoTen();

	printf("Dang tim . . .\n");
	int result = showListReader(lReader , name, HO_TEN);
	free(name);
	if (result < 1) {
		return NOT_FOUND;
	}

	return SUCCESS;
}

FUNCTION_CASE findReaderAsCMND(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASCMND)) {
		return INVAILD;
	}

	printf("Nhap CMND cua doc gia: ");
	char* cmnd = nhapReader_HoTen();

	printf("Dang tim . . .\n");

	int result = showListReader(lReader, cmnd, CMND);

	free(cmnd);

	if (result < 1) {
		return NOT_FOUND;
	}
	return SUCCESS;
}


/*========================3. Quản lí sách==================================*/
FUNCTION_CASE viewBook(User u, ListBook lBook)
{
	if (!isHavePerm(u.permission, VIEWBOOK)) {
		return INVAILD;
	}

	int result = showListBook(lBook);

	if (result == -1) {
		return ERROR;
	}
	return SUCCESS;
}

FUNCTION_CASE addBook(User u, ListBook &lBook)
{
	if (!isHavePerm(u.permission, ADDBOOK)) {
		return INVAILD;
	}

	Book r;
	nhapBook(r);

	sprintf(r.ISBN, "BOOK%05d", MSToNum(lBook.tail->data.ISBN) + 1);

	addFirst(lBook, r);

	return SUCCESS;
}
FUNCTION_CASE editBook(User u, ListBook &lBook)
{
	if (!isHavePerm(u.permission, EDITREADER)) {
		return INVAILD;
	}

	if (lBook.head == NULL) {
		return NOT_FOUND;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeBook* r = getNodeBookPos(lBook, stt);

	if (r == NULL) {
		return NOT_FOUND;
	}

	printf("Sach da chon: \n");
	showBook(r->data);

	printf("Nhap thong tin moi cho doc gia: \n");
	nhapBook(r->data);

	printf("\n\nDa cap nhat thanh cong doc gia.\n");
	return SUCCESS;
}
FUNCTION_CASE deleteBook(User u, ListBook & lBook)
{
	if (!isHavePerm(u.permission, DELETEREADER)) {
		return INVAILD;
	}

	if (lBook.head == NULL) {
		return NOT_FOUND;
	}
	int stt;
	printf("Nhap so thu tu cua doc gia: ");
	scanf("%d", &stt);

	NodeBook* r = getNodeBookPos(lBook, stt);

	if (r == NULL) {
		return NOT_FOUND;
	}

	printf("Doc gia da chon: ");
	showBook(r->data);

	deletePos(lBook, stt);

	printf("\n\nDa xoa thanh cong sach.\n");
	return SUCCESS;
}
FUNCTION_CASE findBookAsName(User u, ListBook &lBook) {
	if (!isHavePerm(u.permission, FINDBOOKASNAME)) {
		return INVAILD;
	}

	printf("Nhap ten sach ");
	char* name = nhapBook_TenSach();

	printf("Dang tim . . .\n");
	int result = showListBook(lBook, name, TEN_SACH);
	free(name);

	if (result < 0) {
		return NOT_FOUND;
	}
	return SUCCESS;
}

FUNCTION_CASE findBookAsISBN(User u, ListBook &lBook) {
	if (!isHavePerm(u.permission, FINDBOOKASISBN)) {
		return INVAILD;
	}

	printf("Nhap ISBN cua sach: ");
	char* isbn = nhapBook_ISBN();

	printf("Dang tim . . .\n");
	int result = showListBook(lBook, isbn, ISBN);

	free(isbn);

	if (result < 0) {
		return NOT_FOUND;
	}
	return SUCCESS;
}