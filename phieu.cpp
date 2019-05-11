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
	scanf("%s", phieuMuon.MS);

	printf("Ngay muon (dd/mm/yyyy): ");
	phieuMuon.ngayMuon = nhapDate();

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
	clearEnter();
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
	scanf("%s", phieuTra.MS);

	printf("Ngay muon (dd/mm/yyyy): ");
	phieuTra.ngayMuon = nhapDate();

	printf("Ngay tra (dd/mm/yyyy): ");
	phieuTra.ngayTra = nhapDate();

	phieuTra.type = MUON;

}

void nhapPhieuTra_info(Phieu phieuTra_root, Phieu &phieuTra)
{
	strcpy(phieuTra.MS, phieuTra_root.MS);

	phieuTra.ngayMuon = phieuTra_root.ngayMuon;
	phieuTra.ngayTra = phieuTra_root.ngayTra;

	phieuTra.type = MUON;
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

