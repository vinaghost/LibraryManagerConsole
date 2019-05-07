#pragma once

#include "const.h"
#include <stdio.h>
#include "Book.h"
#include "utility.h"

struct Phieu
{
	char madocgia[10];
	Date ngaymuon;
	Date ngaytradukien;
	int soluong;
	Book *a = new Book[soluong];
	Date ngaytrathucte;
	int kt;
};

void InputPhieuMuon(Phieu &PhieuMuon);
void AddPhieuMuonintoFile(Phieu PhieuMuon);
void InputPhieuTra(Phieu &PhieuTra);
int FindGia(char ch[20]);
int KTThang(int i, int j);
int Ngay(Date D1, Date D2);
int FindPhieuMuon(Phieu &PhieuTra, Phieu PhieuMuon);
void AddPhieuTraintoFile(Phieu PhieuTra, Phieu PhieuMuon);