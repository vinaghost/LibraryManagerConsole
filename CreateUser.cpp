#include "const.h"
#include "CreateUser.h"
#include <stdio.h>
#include <string.h>


void writeInf(User &a)
{
	scanf("Name: %s", a.name);
	scanf("MS: %s", a.MS);
	scanf("Birth: %s", a.Birth);
	scanf("DiaChi: %s", a.DiaChi);
	scanf("Sex(Nam:1, Nu:0): %s", a.Nam);
	scanf("active(active:1, block:0): %s", a.active);
}

void CreateUser(User u)
{
	printf("Nhap thong tin nguoi dung:/n");
	FILE *f;
	f = fopen(CREATEUSER_FILE, "a");
	fprintf(f, u.name);
	fprintf(f, " | ");
	fprintf(f, u.MS);
	fprintf(f, " | ");
	fprintf(f, u.Birth);
	fprintf(f, " | "); 
	fprintf(f, u.DiaChi);
	fprintf(f, " | "); 
	fprintf(f, u.Nam);
	fprintf(f, " | "); 
	fprintf(f, u.active);
	fprintf(f, "\n");
	fclose(f);
}