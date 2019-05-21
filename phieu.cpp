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
	initDate(phieu.ngayMuon);
	initDate(phieu.ngayTra);
	phieu.type = NONE;
}

void nhapPhieuMuon_info(Phieu &phieuMuon)
{
	printf("Ma doc gia: "); 
	if (fgets(phieuMuon.MS, MS_LENGTH, stdin) != NULL) {
		size_t len = strlen(phieuMuon.MS);
		if (len > 0 && phieuMuon.MS[len - 1] == '\n') {
			phieuMuon.MS[--len] = '\0';
		}
	}

	phieuMuon.ngayMuon = getToday();
	phieuMuon.ngayTra = increaseDate(phieuMuon.ngayMuon, MUON_SACH_LENGTH);

	phieuMuon.type = MUON;
	
}

void nhapPhieuMuon_info(Phieu phieuMuon_root, Phieu &phieuMuon)
{
	strcpy(phieuMuon.MS, phieuMuon_root.MS);

	phieuMuon.ngayMuon = phieuMuon_root.ngayMuon;
	phieuMuon.ngayTra = phieuMuon_root.ngayTra;

	phieuMuon.type = MUON;
}

char* nhapPhieuMuon_book() {
	printf("Nhap ma ISBN cua sach: ");
	char *isbn = (char*)malloc(sizeof(char) * 15);
	if (fgets(isbn, 15, stdin) != NULL) {
		size_t len = strlen(isbn);
		if (len > 0 && isbn[len - 1] == '\n') {
			isbn[--len] = '\0';
		}
	}
	return isbn;
}

void showPhieuMuon(Phieu &phieuMuon)
{
	printf("Ma doc gia: %s\n", phieuMuon.MS);
	printf("ISBN sach muon: %s\n", phieuMuon.ISBN);
	printf("Ngay muon: ");
	showDate(phieuMuon.ngayMuon);
	printf("Ngay tra du kien: ");
	showDate(phieuMuon.ngayTra);
	printf("\n");
}

void nhapPhieuTra_info(Phieu &phieuTra)
{
	printf("Ma doc gia: ");
	if (fgets(phieuTra.MS, MS_LENGTH, stdin) != NULL) {
		size_t len = strlen(phieuTra.MS);
		if (len > 0 && phieuTra.MS[len - 1] == '\n') {
			phieuTra.MS[--len] = '\0';
		}
	}

	phieuTra.type = TRA;

}

void nhapPhieuTra_info(Phieu phieuTra_root, Phieu &phieuTra)
{
	strcpy(phieuTra.MS, phieuTra_root.MS);

	phieuTra.type = TRA;
}

char* nhapPhieuTra_book() {
	printf("Nhap ma ISBN cua sach: ");
	char *isbn = (char*)malloc(sizeof(char) * ISBN_LENGTH);
	clearEnter();
	if (fgets(isbn, ISBN_LENGTH, stdin) != NULL) {
		size_t len = strlen(isbn);
		if (len > 0 && isbn[len - 1] == '\n') {
			isbn[--len] = '\0';
		}
	}
	return isbn;
}

void showPhieuTra(Phieu &phieuTra)
{
	printf("Ma doc gia: %s\n", phieuTra.MS);
	printf("ISBN sach muon: %s\n", phieuTra.ISBN);
	printf("Ngay muon: ");
	showDate(phieuTra.ngayMuon);
	printf("Ngay tra: ");
	showDate(phieuTra.ngayTra);
	printf("\n");
}

