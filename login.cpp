#include "const.h"
#include "login.h"
#include <stdio.h>
#include <string.h>



int DangXuat(User &u) {
	initUser(u);
	return 1;
}
LOGIN_CASE Login(User &u)
{
	printf("Username: ");
	gets_s(u.name, sizeof(u.name));

	printf("Password: ");
	getPassword(u.password);

	if (strcmp(u.name, AD_USERNAME) == 0) {

		if (strcmp(u.password, AD_PASSWORD) == 0) {


			sprintf(u.HoTen, AD_NAME);


			return ACCEPT;
		}
		return WRONG_PASSWORD;
	}
	User tmp = isExistUser(u);

	if (tmp.name[0] == '\0') {
		return WRONG_USERNAME;
	}

	if (!isPassWordSame(u, tmp)) {
		return WRONG_PASSWORD;
	}

	u = tmp;

	return ACCEPT;
}
int isPassWordSame(User u, User f)
{
	if (strcmp(u.password, f.password) == 0) {
		return 1;
	}
	return 0;
}



