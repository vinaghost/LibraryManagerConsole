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
	int count = 1;
	while (!feof(userFile)) {
		
		char str[200];
		fgets(str, sizeof(str), userFile);

		sscanf(str, "%s %s %d %s %s %s %s %d %d", fuser.name, fuser.password, &fuser.permission, fuser.HoTen, fuser.MS, fuser.Birth, fuser.DiaChi, &fuser.Nam, &fuser.active);
		
		if (strcmp(u.name, fuser.name) == 0) {
			fuser.location = count;
			return fuser;
		}

		count++;
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

int Login(User &u)
{
	printf("Username: ");
	gets_s(u.name, sizeof(u.name));

	printf("Password: ");
	getPassword(u.password);

	User tmp = isExistUser(u);

	if (tmp.name[0] == '\0') {
		printf("Username khong ton tai");
		return 0;
	}

	if (!isPassWordSame(u, tmp)) {
		printf("Password khong dung");
		return 0;
	}

	u = tmp;
	return 1;
}

