#include "User.h"
#include <stdio.h>

void initUser(User &t) {
	t.name[0] = '\0';
	t.password[0] = '\0';

	t.permission = 0;
}

int isVaildUser(User t)
{
	if (t.name[0] == '\0') {
		return 0;
	}
	return 1;
}
