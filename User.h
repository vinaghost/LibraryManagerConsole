#pragma once
#include <stdio.h>
struct User {
	char *name;
	char *password;
	int permission;
};

void initUser(User &t) {
	t.name = NULL;
	t.password = NULL;

	t.permission = 0;
}