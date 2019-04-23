#ifndef _USER_H_

#define _USER_H_


struct User {
	char name[50];
	char password[50];
	int permission;
};

void initUser(User &t);


#endif
