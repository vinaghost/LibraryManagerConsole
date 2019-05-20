#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOOK_FILE "book.dat"
const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";
int intN(int n) { return rand() % n; }

char theLoai[][20] = {
    "Truyen ngan",
    "Truyen dai",
    "Tieu thuyet",
    "Sach giao khoa",
    "Tu dien",
    "Tai lieu tham khao"
};
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
    FILE* f = fopen(BOOK_FILE, "w");
    if( f == NULL ) {
        return -1;
    }
    srand(time(NULL));

    int n = 50;
    char isbn[15], tensach[40], tenTacGia[40], nXB[40], str_theLoai[20];
    int namXB, gia, soLuong;

    char *tmp;
    while(n--) {
        tmp = randomString(14, 0);
        sprintf(isbn, tmp);
        isbn[14] = '\0';
        printf(tmp);
        printf("\n");
        free(tmp);

        tmp =  randomString( 12, 1);
        sprintf(tenTacGia, tmp);
        printf(tmp);
        printf("\n");
        free(tmp);

         tmp = randomString( 12, 1);
        sprintf(tensach, tmp);
        printf(tmp);
        printf("\n");
        free(tmp);

         tmp = randomString( 12, 1);
        sprintf(nXB, tmp);
        printf(tmp);
        printf("\n");
        printf("\n");
        printf("\n");
        free(tmp);

        sprintf(str_theLoai, theLoai[ rand() % 6]);

        namXB = rand() % 2015;
        soLuong = rand() % 200;
        gia = rand() % 50000 + 50000;
        fprintf(f, "%s, %s, %s, %s, %s, %d, %d, %d\n", isbn, tensach, tenTacGia, nXB, str_theLoai, namXB, gia, soLuong);
    }
    fclose(f);
    return 0;
}
