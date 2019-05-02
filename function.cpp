#include "function.h"

#include <stdio.h>
#include <stdlib.h>



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

	sprintf(r.MS, "READ%05d", lReader.total + 1);

	addFirst(lReader, r);

	return SUCCESS;
}
FUNCTION_CASE findReaderAsName(User u, ListReader &lReader, ListReader &findReader) {
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

FUNCTION_CASE findReaderAsCMND(User u, ListReader &lReader, ListReader &findReader) {
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

	sprintf(r.ISBN, "READ%05d", lBook.total + 1);

	addFirst(lBook, r);

	return SUCCESS;
}
FUNCTION_CASE findBookAsName(User u, ListBook &lBook, ListBook &findBook) {
	if (!isHavePerm(u.permission, FINDBOOKASNAME)) {
		return INVAILD;
	}

	printf("Nhap ten sach ");
	char* name = nhapBook_TenSach();

	printf("Dang tim . . .\n");
	findBook = getNodeBookFromData(lBook, name, TEN_SACH);

	if (getTotal(findBook) == 0) {
		return ERROR;
	}
	printf("Tim thay %d sach co ten %s\n", getTotal(findBook), name);
	showListBook(findBook);
	free(name);
	return SUCCESS;
}

FUNCTION_CASE findBookAsCMND(User u, ListBook &lBook, ListBook &findBook) {
	if (!isHavePerm(u.permission, FINDBOOKASISBN)) {
		return INVAILD;
	}

	printf("Nhap ISBN cua sach: ");
	char* isbn = nhapBook_ISBN();

	printf("Dang tim . . .\n");
	findBook = getNodeBookFromData(lBook, isbn, ISBN);

	if (getTotal(findBook) == 0) {
		return ERROR;
	}
	printf("Tim thay %d sach co ISBN %s\n", getTotal(findBook), isbn);
	showListBook(findBook);

	return SUCCESS;
}