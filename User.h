#pragma once
#include <stdio.h>
struct User {
	char name[50];
	char password[50];
	int permission;
};

void initUser(User &t) {
	sprintf_s(t.name, sizeof(t.name) , "");
	sprintf_s(t.password, sizeof(t.password), "");

	t.permission = 0;
}