#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define USER_FILE "user.dat"
#define READER_FILE "reader.dat"

#define TMP_FILE "tmp.dat"

#define HET_HAN_THE 48

enum PermUser {
	ADMIN,
	QUANLI,
	CHUYENVIEN
};

enum Perm {
	LOGIN = 0,
	LOGOUT,
	CHANGEPASS,
	CHANGEINFO,
	CREATUSER,
	CHANGEPERM,

	VIEWREADER,
	ADDREADER,
	EDITREADER,
	DELETEREADER,
	FINDREADERASCMND,
	FINDREADERASNAME,

	VIEWBOOK,
	ADDBOOK,
	EDITBOOK,
	DELETEBOOK,
	FINDBOOKASISBN,
	FINDBOOKASNAME,

	CREATMUONSACH,
	CREATTRASACH,

	VIEWNUMBOOK,
	VIEWNUMBOOKASCATA,
	VIEWNUMREADER,
	VIEWNUMREADERASGENDER,
	VIEWNUMBOOKASBORROW,
	VIEWNUMREADERASLATE
};

enum LOGIN_CASE {
	ACCEPT,
	WRONG_PASSWORD,
	WRONG_USERNAME
};

enum READER_CASE {
	HO_TEN,
	CMND
};

enum BOOK_CASE {
	ISBN,
	TEN_SACH
};

enum FUNCTION_CASE {
	INVAILD = -1,
	SUCCESS,
	ERROR
};
#define setBit(a, b) a |= (1 << b)
#define getBit(a, b) a & (1 << b)

#define clear char t; while ((t= _getch()) != '\n' && t != EOF)


#define Line() printf("======================================\n")
#define Title() printf("\tPhan mem quan li thu vien\n")