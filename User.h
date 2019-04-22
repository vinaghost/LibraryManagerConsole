#pragma once
#include <stdio.h>
struct User {
	char name[50];
	char password[50];
	int permission;
};

void initUser(User &t) {
	sprintf_s(t.name, sizeof(t.name) - 1, "");
	sprintf_s(t.password, sizeof(t.password) - 1, "");

	t.permission = 0;
}