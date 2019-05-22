#include "const.h"
#include "login.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int DangXuat(User &u) {
	initUser(u);
	return 1;
}
LOGIN_CASE Login(User &u)
{
	printf("Username: ");
	if (fgets(u.name, sizeof(u.name), stdin) != NULL) {
		size_t len = strlen(u.name);
		if (len > 0 && u.name[len - 1] == '\n') {
			u.name[--len] = '\0';
		}
	}

	printf("Password: ");
	getPassword(u.password);

	if (strcmp(u.name, AD_USERNAME) == 0) {
		
		FILE* root = fopen(ADMIN_FILE, "r");
		char pass[PASS_LENGTH] = {} , hoTen[NAME_LENGTH] = {}, cmnd[CMND_LENGTH] = {}, birth[DAY_LENGTH] = {}, diaChi[ADDRESS_LENGTH] = {};
		int Nam = 0 ;
		fscanf_s(root, "%[^,\n], %[^,\n], %[^,\n], %[^,\n], %[^,\n], %d", pass, PASS_LENGTH,  hoTen, NAME_LENGTH,  cmnd,CMND_LENGTH, birth, DAY_LENGTH,  diaChi, ADDRESS_LENGTH, &Nam);

		if (strlen(pass) < 1) {
			if (strcmp(u.password, AD_PASSWORD) != 0) {
				return WRONG_PASSWORD;
			}
		}
		else {
			if (strcmp(u.password, pass) != 0) {
				return WRONG_PASSWORD;
			}
		}

		strcpy(u.HoTen, hoTen);
		strcpy(u.CMND, cmnd);
		u.ngaySinh = StringToDate(birth);
		strcpy(u.DiaChi, diaChi);
		u.Nam = Nam;
		u.permission = AD_PERMSSION;
		return ACCEPT;
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





