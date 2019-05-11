#pragma once

#include "const.h"
#include "utility.h"

struct Phieu
{
	char MS[10];
	char ISBN[15];
	Date ngayMuon;
	Date ngayTra;
	CARD_TYPE type;
};

void initPhieu(Phieu &phieu);

void nhapPhieuMuon_info(Phieu &phieuMuon);
void nhapPhieuMuon_info(Phieu phieuMuon_root, Phieu &phieuMuon );
char* nhapPhieuMuon_book();
void showPhieuMuon(Phieu &phieuMuon);
int writePhieuMuonToFile(Phieu &phieuMuon);

void nhapPhieuTra_info(Phieu &phieuTra);
void nhapPhieuTra_info(Phieu phieuTra_root, Phieu &phieuTra );
char* nhapPhieuTra_book();
void showPhieuTra(Phieu &phieuTra);
int writePhieuTraToFile(Phieu &phieuTra);
