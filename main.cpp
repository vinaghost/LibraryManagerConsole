#include "menu.h"
#include <windows.h>

int main() {
	SetConsoleTitle(TEXT("Phan mem quan li thu vien"));


	User u;
	initUser(u);

	menuMain(u);

	return 0;
}