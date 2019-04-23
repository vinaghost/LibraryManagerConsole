#ifndef _USER_H_

#define _USER_H_


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



#endif
