#include "utility.h"
#include <stdio.h>
#include <conio.h>

void getPassword(char *pass)
{
	char buff[50] = { 0 }, ch;
	int len = 0;
	while ((ch= getchar()) != '\n' && ch != EOF);


	while ((ch = _getch()) != '\n' )
	{
		if (ch == '\r') {
			break;
		}
		// nguon: https://www.includehelp.com/c-programs/c-program-puzzle-design-login-screen-check-username-and-password.aspx
		if (ch == '\b')    // dau khoang trang
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
