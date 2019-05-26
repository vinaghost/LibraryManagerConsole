#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
int intN(int n) { return rand() % n; }

char *randomString(int len, int space) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
        if(space && rand() % 10 == 0) {
            rstr[i] = ' ';
        }
        else {
            rstr[i] = alphabet[intN(strlen(alphabet))];
        }
  }
  rstr[len] = '\0';
  return rstr;
}
int main() {
    FILE* f = fopen("reader.dat", "w");
    if( f == NULL ) {
        return -1;
    }
    srand(time(NULL));

    int n;
    printf("Nhap so luong sach duoc tao ra (vi du 500): ");
    scanf("%d", &n);

    char ms[10], hoTen[50], cmnd[13], birth[12], lapThe[12];
    int nam;

    char *tmp;
    while(n--) {

        sprintf(ms, "READ%05d", 50 - n);

        tmp = randomString(49, 1);
        strcpy(hoTen, tmp);
        free(tmp);

        tmp = randomString(12, 0);
        strcpy(cmnd, tmp);
        free(tmp);

        sprintf(birth, "%02d/%02d/%04d", rand() % 28 + 1, rand() % 11 + 1, rand() % 14 + 1990);

        nam = rand() % 2;

        sprintf(lapThe, "%02d/%02d/%04d", rand() % 28 + 1, rand() % 11 + 1, rand() % 2 + 2018);

        fprintf(f, "%s, %s, %s, %s, %d, %s\n", ms, hoTen, cmnd, birth, nam, lapThe);
    }
    fclose(f);

    printf("Da tao thanh cong file\n");

    return 0;
}

