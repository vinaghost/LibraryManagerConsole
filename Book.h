#pragma once
#include "utility.h"

struct Book {
	char ISBN[20];
	char TenSach[40];
	char TenTacGia[40];
	char NXB[40];
	int NamXB;
	char TheLoai[20];
	int Gia;
	int SoLuong;
};

void initBook(Book &book);

int isVaildBook(Book book);

int addBookToFile(Book book);

int nhapBook(Book &book);

void showBook(Book book);

char* nhapBook_ISBN();

char* nhapBook_TenSach();
