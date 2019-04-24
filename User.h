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
//
//Input User's Information
void AddInf(User &u);
//
//Add User's Information to File
void CreateUser(User u);
//
//Add Name and newpass
void NewPass(User &u);
//
//Find place old pass
int FindPlaceOldPass(User u, User &f, User &h);
//
//Change Pass
void ChangePass(User u);


int isVaildUser(User t);

