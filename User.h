#pragma once

struct User {
	char *name;
	char *password;
	int permission;
};

void initUser(User &t) {
	t.name = nullptr;
	t.password = nullptr;

	t.permission = 0;
}