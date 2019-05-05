#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
	User u;
	initUser(u);

	menuMain(u);

	/*char str[] = "18120218";

	char *pass = maHoa(str);
	FILE *f = fopen("abc.dat", "w");
	fprintf(f, "%s", pass);
	free(pass);
	fclose(f);
	getchar();*/

	/*int perm = 0;
	for (int i = LOGIN; i < VIEWNUMREADERASLATE + 1; i++) {
		perm |= (1 << i);
	}
	printf("%d", perm);

	printf("\n%d", isHavePerm(perm, CREATUSER));
	getchar();*/
	return 0;
}