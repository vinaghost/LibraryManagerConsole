#include "Phieu.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book.h"
#include "utility.h"

void initPhieu(Phieu & phieu)
{
	phieu.MS[0] = '\0';
	phieu.ISBN[0] ='\0';
	initDate(phieu.ngayTaoPhieu);
}

void nhapPhieuMuon_info(Phieu &phieuMuon)
{
	printf("Ma doc gia: ");
	scanf("%s", phieuMuon.MS);

	printf("Ngay muon (dd/mm/yyyy): ");
	phieuMuon.ngayTaoPhieu = nhapDate();
	
}

void nhapPhieuMuon_info(Phieu phieuMuon_root, Phieu &phieuMuon)
{
	strcpy(phieuMuon.MS, phieuMuon_root.MS);

	phieuMuon.ngayTaoPhieu = phieuMuon_root.ngayTaoPhieu;
}
char* nhapPhieuMuon_book() {
	printf("Nhap ma ISBN cua sach: ");
	char *isbn = (char*)malloc(sizeof(char) * 15);
	clearEnter();
	if (fgets(isbn, 15, stdin) != NULL) {
		size_t len = strlen(isbn);
		if (len > 0 && isbn[len - 1] == '\n') {
			isbn[--len] = '\0';
		}
	}
	return isbn;
}
int writePhieuMuonToFile(Phieu &phieuMuon)
{
	FILE *f;
	f = fopen(PHIEUMUON_FILE, "a");
	if (f == NULL) {
		return -1;
	}

	char *ngayTaoPhieu = DateToString(phieuMuon.ngayTaoPhieu);
	fprintf(f, "%s, %s, %s\n", phieuMuon.MS, phieuMuon.ISBN, ngayTaoPhieu);
	free(ngayTaoPhieu);
	fclose(f);
	return 1;
}

void xuatPhieuMuon(Phieu &phieuMuon)
{
	printf("] Ma doc gia: %s\n", phieuMuon.MS);
	printf("ISBN sach muon: %s\n", phieuMuon.ISBN);
	printf("Ngay muon: ");
	showDate(phieuMuon.ngayTaoPhieu);
	printf("\n");
}

void nhapPhieuTra_info(Phieu &phieuTra)
{
	printf("Ma doc gia: ");
	scanf("%s", phieuTra.MS);

	printf("Ngay muon (dd/mm/yyyy): ");
	phieuTra.ngayTaoPhieu = nhapDate();

}

void nhapPhieuTra_info(Phieu phieuTra_root, Phieu &phieuTra)
{
	strcpy(phieuTra.MS, phieuTra_root.MS);

	phieuTra.ngayTaoPhieu = phieuTra_root.ngayTaoPhieu;
}
char* nhapPhieuTra_book() {
	printf("Nhap ma ISBN cua sach: ");
	char *isbn = (char*)malloc(sizeof(char) * 15);
	clearEnter();
	if (fgets(isbn, 15, stdin) != NULL) {
		size_t len = strlen(isbn);
		if (len > 0 && isbn[len - 1] == '\n') {
			isbn[--len] = '\0';
		}
	}
	return isbn;
}
int writePhieuTraToFile(Phieu &phieuTra)
{
	FILE *f;
	f = fopen(PHIEUTRA_FILE, "a");
	if (f == NULL) {
		return -1;
	}

	char *ngayTaoPhieu = DateToString(phieuTra.ngayTaoPhieu);
	fprintf(f, "%s, %s, %s\n", phieuTra.MS, phieuTra.ISBN, ngayTaoPhieu);
	free(ngayTaoPhieu);
	fclose(f);


	f = fopen(PHIEUMUON_FILE, "w+");
	if (f == NULL) {
		return -1;
	}


	return 1;
}

void xuatPhieuTra(Phieu &phieuTra)
{
	printf("] Ma doc gia: %s\n", phieuTra.MS);
	printf("ISBN sach muon: %s\n", phieuTra.ISBN);
	printf("Ngay muon: ");
	showDate(phieuTra.ngayTaoPhieu);
	printf("\n");
}

int FindGia(char ch[20])
{
	int gia = 0;
	FILE *BookFile;

	BookFile = fopen(BOOK_FILE, "r");

	if (BookFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", BOOK_FILE);
		return;
	}
	Book fBook;
	char str[200];
	while (fgets(str, sizeof(str), BookFile) != NULL)
	{
		sscanf(str, "%[^,\n], %[^,\n], %[^,\n], %[^,\n], %[^,\n], %d, %d, %d\n", fBook.ISBN, fBook.TenSach, fBook.TenTacGia, fBook.NXB, fBook.TheLoai, &fBook.NamXB, &fBook.Gia, &fBook.SoLuong);
		if (strcmp(ch, fBook.ISBN) == 0)
		{
			gia = fBook.Gia;
		}
	}
	fclose(BookFile);
	return gia;
}

