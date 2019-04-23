#pragma once


struct User {
	char name[50];
	char password[50];
	unsigned int permission;

	char HoTen[50];
	char MS[10];
	char Birth[9];
	char DiaChi[20];
	char Nam[2];
	char active[2];
};


void initUser(User &t);

int isVaildUser(User t);

