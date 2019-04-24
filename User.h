#pragma once

#include "const.h"

struct User {
	char name[50];
	char password[50];
	unsigned int permission;

	char HoTen[50];
	char MS[10];
	char Birth[9];
	char DiaChi[20];
	int Nam;
	int active;

	int location;
};

void initUser(User &t);

void showUser(User u);


int isVaildUser(User t);

int findUserLocation(User u);

void createUser(User u);

void addPerm(User &u, PermUser perm);

void nhapUser(User &u);

void nhapInf(User &u);

int changePass(User &u);

void newPass(char *pass);

int changeInf(User &u);




