#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define USER_FILE "user.dat"
#define TMP_FILE "tmp.dat"

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

#define setBit(a, b) a |= (1 << b)
#define getBit(a, b) a & (1 << b)