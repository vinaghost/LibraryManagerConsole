#include "const.h"
#include "login.h"
#include <stdio.h>
#include <string.h>

User isExistUser(User u)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "r");

	if (userFile == NULL) {
		printf("[ERROR] Khong tim thay file user.dat");
	}


	User fuser;
	while (!feof(userFile)) {
		
		char str[200];
		fgets(str, sizeof(str), userFile);

		sscanf(str, "%s %s %d", fuser.name, fuser.password, &fuser.permission);

		if (strcmp(u.name, fuser.name) == 0) {
			return fuser;
		}
	}

	initUser(fuser);

	return fuser;
}

int isPassWordSame(User u, User f)
{
	if (strcmp(u.password, f.password) == 0) {
		return 1;
	}
	return 0;
}
