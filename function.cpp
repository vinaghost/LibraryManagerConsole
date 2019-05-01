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
FUNCTION_CASE findReaderAsName(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASNAME)) {
		return INVAILD;
	}

	printf("Nhap ho ten cua doc gia: ");
	char* name = nhapReader_HoTen();

	printf("Dang tim . . .\n");
	ListReader nReader = getNodeReaderFromData(lReader, name, HO_TEN);

	if(getTotal(nReader) == 0) {
		return ERROR;
	}
	printf("Tim thay %d doc gia co ten %s\n", getTotal(nReader), name);
	showListReader(nReader);
	free(name);
	return SUCCESS;
}

FUNCTION_CASE findReaderAsCMND(User u, ListReader &lReader) {
	if (!isHavePerm(u.permission, FINDREADERASCMND)) {
		return INVAILD;
	}

	printf("Nhap CMND cua doc gia: ");
	char* cmnd = nhapReader_HoTen();

	printf("Dang tim . . .\n");
	ListReader nReader = getNodeReaderFromData(lReader, cmnd, CMND);

	if (getTotal(nReader) == 0) {
		return ERROR;
	}
	printf("Tim thay %d doc gia co CMND %s\n", getTotal(nReader), cmnd);
	showListReader(nReader);

	return SUCCESS;
}