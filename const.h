 #pragma once
#define _CRT_SECURE_NO_WARNINGS

// admin account
#define AD_USERNAME "admin"
#define AD_PERMSSION 67108863

#define PEPPER 5

#define USER_FILE "user.dat"
#define ADMIN_FILE "admin.dat"
#define READER_FILE "reader.dat"
#define BOOK_FILE "book.dat"
#define PHIEU_FILE "phieu.dat"

#define TMP_FILE "tmp.dat"

#define HET_HAN_THE 48

#define PASS_LENGTH 50
#define DAY_LENGTH 12
#define ADDRESS_LENGTH 50

#define NAME_LENGTH 50
#define CMND_LENGTH 13

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
	ERROR,
	NOT_FOUND
};

enum TITLE_CASE {
	MAIN,
	USER,
	READER,
	BOOK
};
#define setBit(a, b) a |= (1 << b)
#define getBit(a, b) !(!(a & (1 << b)))



#define Line() printf("======================================\n")
#define Title() printf("\tPhan mem quan li thu vien\n")
#define Title_reader() printf("\tQuan li doc gia\n")
#define Title_user() printf("\tQuan li tai khoan\n")
#define Title_book() printf("\tQuan li sach\n")