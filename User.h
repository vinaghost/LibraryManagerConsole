#pragma once

#include "const.h"
#include <stdio.h>
#include "utility.h"
struct User {
	char name[PASS_LENGTH];
	char password[PASS_LENGTH];
	unsigned int permission;

	char HoTen[NAME_LENGTH];
	char CMND[CMND_LENGTH];
	char DiaChi[ADDRESS_LENGTH];
	int Nam;
	Date ngaySinh;
	int active;

	int location;
};

void initUser(User &t);

void showUser(User u);

User isExistUser(User &u);


int isVaildUser(User t);

void addPerm(User &u, PermUser perm);

void nhapUser(User &u);

void nhapInf(User &u);

void newPass(char *pass);

int isPassWordSame(User u, User f);



