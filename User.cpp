#include "User.h"
#include <stdio.h>

void initUser(User &t) {
	sprintf_s(t.name, sizeof(t.name), "");
	sprintf_s(t.password, sizeof(t.password), "");

	t.permission = 0;
}