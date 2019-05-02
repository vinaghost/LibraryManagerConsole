#include "const.h"
#include "Book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

void initBook(Book &book)
{
	book.ISBN[0] = '\0';
	book.TenSach[0] = '\0';
	book.TenTacGia[0] = '\0';
	book.NXB[0] = '\0';
	book.TheLoai[0] = '\0';
	book.NamXB = 0;
	book.Gia = 0;
	book.SoLuong = 0;
}

int isVaildBook(Book book)
{
	if (book.ISBN[0] == '/0') {
		return 0;
	}
	if (book.TenSach[0] == '/0') {
		return 0;
	}
	if (book.TenTacGia[0] == '/0') {
		return 0;
	}
	if (book.NXB[0] == '/0') {
		return 0;
	}
	if (book.TheLoai[0] == '/0') {
		return 0;
	}
}

int addBookToFile(Book book)
{
	if (!isVaildBook(book)) {
		return 0;
	}

	FILE *f = fopen(BOOK_FILE, "a");

	fprintf(f, "%s, %s, %s, %s, %s, %d, %d, %d\n", book.ISBN, book.TenSach, book.TenTacGia, book.NXB, book.TheLoai, book.NamXB, book.Gia, book.SoLuong);

	fclose(f);
	return 1;
}

int nhapBook(Book &book)
{
	sprintf(book.ISBN, "processing");
	printf("Nhap thong tin sach: \n");
	printf("] Ten sach: ");
	if (fgets(book.TenSach, sizeof(book.TenSach), stdin) != NULL) {
		size_t len = strlen(book.TenSach);
		if (len > 0 && book.TenSach[len - 1] == '\n') {
			book.TenSach[--len] = '\0';
		}
	}
	printf("] Ten tac gia: ");
	if (fgets(book.TenTacGia, sizeof(book.TenTacGia), stdin) != NULL) {
		size_t len = strlen(book.TenTacGia);
		if (len > 0 && book.TenTacGia[len - 1] == '\n') {
			book.TenTacGia[--len] = '\0';
		}
	}
	printf("] Ten nha xuat ban: ");
	if (fgets(book.NXB, sizeof(book.NXB), stdin) != NULL) {
		size_t len = strlen(book.NXB);
		if (len > 0 && book.NXB[len - 1] == '\n') {
			book.NXB[--len] = '\0';
		}
	}
	printf("] The loai: ");
	if (fgets(book.TheLoai, sizeof(book.TheLoai), stdin) != NULL) {
		size_t len = strlen(book.TheLoai);
		if (len > 0 && book.TheLoai[len - 1] == '\n') {
			book.TheLoai[--len] = '\0';
		}
	}
	printf("Nam xuat ban: ");
	scanf("%d", &book.NamXB);
	printf("Gia sach: ");
	scanf("%d", &book.Gia);
	printf("So luong sach: ");
	scanf("%d", &book.SoLuong);

	return 1;
}

void showBook(Book book)
{
	printf("Ma sach(ISBN): %s\n", book.ISBN);
	printf("] Ten sach: %s\n", book.TenSach);
	printf("] Ten tac gia: %s\n", book.TenTacGia);
	printf("] Ten nha xuat ban:  %s\n", book.NXB);
	printf("] The loai: %s\n", book.TheLoai);
	printf("Nam xuat ban: %d\n", book.NamXB);
	printf("Gia sach: %d\n", book.Gia);
	printf("So luong sach: %d\n", book.SoLuong);
}

char* nhapBook_ISBN()
{
	char* ISBN = (char*)malloc(sizeof(char) * 13);
	if (ISBN == NULL) {
		return NULL;
	}
	if (fgets(ISBN, sizeof(ISBN), stdin) != NULL) {
		size_t len = strlen(ISBN);
		if (len > 0 && ISBN[len - 1] == '\n') {
			ISBN[--len] = '\0';
		}
	}

	return ISBN;
}

char* nhapBook_TenSach()
{
	char* TenSach = (char*)malloc(sizeof(char) * 13);
	if (TenSach == NULL) {
		return NULL;
	}
	if (fgets(TenSach, sizeof(TenSach), stdin) != NULL) {
		size_t len = strlen(TenSach);
		if (len > 0 && TenSach[len - 1] == '\n') {
			TenSach[--len] = '\0';
		}
	}

	return TenSach;
}