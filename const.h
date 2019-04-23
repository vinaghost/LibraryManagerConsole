#ifndef _CONST_H_

#define _CONST_H_
#define _CRT_SECURE_NO_WARNINGS

#define USER_FILE "user.dat"


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
	DELETEREAEDER,
	FINDREADERASCMND,
	FINDREADERASNAME,

	VIEWBOOK,
	ADDBOOK,
	EDITBOOK,
	DELETEBOOK,
	FINDBOOKASISBN,
	FINDBOOKRASNAME,

	CREATMUONSACH,
	CREATTRASACH,

	VIEWNUMBOOK,
	VIEWBOOKASCATA,
	VIEWNUMREADER,
	VIEWREADERASGENDER,
	VIEWBOOKASBORROW,
	VIEWREADERASLATE
};


#endif