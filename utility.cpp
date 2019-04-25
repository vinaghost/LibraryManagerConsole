#include "utility.h"
#include "const.h"
#include <stdio.h>
#include <conio.h>

void getPassword(char *pass)
{
	char buff[50] = { 0 }, ch;
	int len = 0;
	

	//clear;

	while ((ch = _getch()) != '\n' )
	{
		if (ch == '\r') {
			break;
		}
		// nguon: https://www.includehelp.com/c-programs/c-program-puzzle-design-login-screen-check-username-and-password.aspx
		if (ch == '\b')    // dau backspace
		{
			if (len == 0)  continue;
			printf("\b \b"); len--; continue;
		}
		printf("%c", '*');
		pass[len] = ch;
		len++;
	}
	pass[len] = '\0';
	putc('\n', stdout);
}

int getChoice()
{
	int item = _getch();
	item -= ('1' - 1);
	return item;
}

void showTitle()
{
	Line();
	Title();
	Line();
}

void showInfo(const char *info)
{
	Line();
	printf("] %s\n", info);
	Line();
	printf("\n\n");
}

