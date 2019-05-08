#include "Phieu.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Book.h"
#include "utility.h"

void InputPhieuMuon(Phieu &PhieuMuon)
{
	PhieuMuon.kt = 0;
	printf("Ma doc gia: ");
	scanf("%s", PhieuMuon.madocgia);
	printf("Ngay muon(dd/mm/yyyy): ");
	PhieuMuon.ngaymuon = nhapDate();
	printf("Ngay tra du kien(dd/mm/yyyy): ");
	PhieuMuon.ngaytradukien = nhapDate();
	printf("So luong sach muon: ");
	scanf("%d", &PhieuMuon.soluong);
	for (int i = 0; i < PhieuMuon.soluong; i++)
	{
		printf("Ma sach: ");
		scanf("%s", PhieuMuon.a[i].ISBN);
	}
}

void AddPhieuMuonintoFile(Phieu PhieuMuon)
{
	FILE *f;
	f = fopen(PHIEU_FILE, "w");
	InputPhieuMuon(PhieuMuon);
	fprintf(f, "%s %d %d ", PhieuMuon.madocgia, PhieuMuon.kt, PhieuMuon.soluong);
	fprintf(f, "%02d/%02d/%04d ", PhieuMuon.ngaymuon.day, PhieuMuon.ngaymuon.month, PhieuMuon.ngaymuon.year);
	fprintf(f, "%02d/%02d/%04d ", PhieuMuon.ngaytradukien.day, PhieuMuon.ngaytradukien.month, PhieuMuon.ngaytradukien.year);
	for (int i = 0; i < PhieuMuon.soluong; i++)
	{
		fprintf(f, "%s ", PhieuMuon.a[i].ISBN);
	}
	fprintf(f, "\n");
	fclose(f);
}

void InputPhieuTra(Phieu &PhieuTra)
{
	printf("Ma doc gia: ");
	scanf("%s", PhieuTra.madocgia);
	PhieuTra.kt = false;
	printf("Ngay tra thuc te: ");
	PhieuTra.ngaytrathucte = nhapDate();
}

int FindGia(char ch[20])
{
	int gia = 0;
	FILE *BookFile;

	BookFile = fopen(BOOK_FILE, "r");

	if (BookFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", BOOK_FILE);
	}
	else
	{
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
	}
	fclose(BookFile);
	return gia;
}


int KTThang(int i, int j)
{
	int ngay;
	if ((i == 1) || (i == 3) || (i == 5) || (i == 7) || (i == 8) || (i == 10) || (i == 12))
	{
		ngay = 31;
	}
	if ((i == 4) || (i == 6) || (i == 9) || (i == 11))
	{
		ngay = 30;
	}
	if (i == 2)
	{
		if ((j % 4 == 0) && (j % 100 == 0) || (j % 400 == 0))
		{
			ngay = 29;
		}
		else
		{
			ngay = 28;
		}
	}
	return ngay;
}

int Ngay(Date D1, Date D2)
{
	int SoNgay = 0;
	if ((D1.month == D2.month) && (D1.year == D2.year))
	{
		SoNgay = SoNgay + D2.day - D1.day;
	}
	else if ((D1.month != D2.month) && (D1.year == D2.year))
	{
		SoNgay = SoNgay + D2.day;
		int dem = KTThang(D1.month, D1.year);
		SoNgay = SoNgay + dem - D1.day;
		for (int i = D1.month + 1; i <= D2.month; i++)
		{
			dem = KTThang(i, D1.year);
			SoNgay = SoNgay + dem;
		}
	}
	else if (D1.year != D2.year)
	{
		SoNgay = SoNgay + D2.day;
		int dem = KTThang(D1.month, D1.year);
		SoNgay = SoNgay + dem - D1.day;
		for (int i = D1.month + 1; i <= 12; i++)
		{
			dem = KTThang(i, D1.year);
			SoNgay = SoNgay + dem;
		}
		for (int i = D1.year + 1; i < D2.year; i++)
		{
			dem = KTThang(2, i);
			if (dem == 28)
			{
				SoNgay = SoNgay + 365;
			}
			else if (dem == 29)
			{
				SoNgay = SoNgay + 366;
			}
		}
		for (int i = 1; i < D2.month; i++)
		{
			dem = KTThang(i, D2.year);
			SoNgay = SoNgay + dem;
		}
	}
	return SoNgay;
}

int FindPhieuMuon(Phieu &PhieuTra, Phieu PhieuMuon)
{
	int dem = 0, tmp = 0;
	FILE *f;
	f = fopen(PHIEU_FILE, "r");
	InputPhieuTra(PhieuTra);
	while (!feof(f))
	{
		dem++;
		fscanf(f, "%s", PhieuMuon.madocgia);
		fscanf(f, "%d", &PhieuMuon.kt);
		fscanf(f, "%d", &PhieuMuon.soluong);
		char st[20];
		fscanf(f, "%s", st);
		sscanf(st, "%d/%d/%d", &PhieuTra.ngaymuon.day, &PhieuTra.ngaymuon.month, &PhieuTra.ngaymuon.year);
		fscanf(f, "%s", st);
		sscanf(st, "%d/%d/%d", &PhieuTra.ngaytradukien.day, &PhieuTra.ngaytradukien.month, &PhieuTra.ngaytradukien.year);
		for (int i = 0; i < PhieuMuon.soluong; i++)
		{
			fscanf(f, "%s ", PhieuMuon.a[i].ISBN);
		}

		if ((strcmp(PhieuTra.madocgia, PhieuMuon.madocgia) == 0) && (PhieuMuon.kt == 0))
		{
			tmp = dem;
			printf("%s\n", PhieuMuon.madocgia);
			showDate(PhieuTra.ngaymuon);
			printf("\n");
			showDate(PhieuTra.ngaytradukien);
			printf("\n");
			printf("so luong sach da tra: ");
			scanf("%d", &PhieuTra.soluong);
			printf("danh sach ma sach da tra: \n");
			for (int i = 0; i < PhieuTra.soluong; i++)
			{
				scanf("%s", PhieuTra.a[i].ISBN);
			}
			int S = 0;
			if (PhieuTra.soluong < PhieuMuon.soluong)
			{
				int a = PhieuMuon.soluong - PhieuTra.soluong;
				for (int i = 0; i < a; i++)
				{
					char ch[20];
					printf("Ma sach mat: ");
					if (fgets(ch, sizeof(ch), stdin) != NULL) {
						size_t len = strlen(ch);
						if (len > 0 && ch[len - 1] == '\n') {
							ch[--len] = '\0';
						}
					}
					int gia;
					gia = FindGia(ch);
					S = S + gia * 2;
				}
			}
			int SoNgay = Ngay(PhieuMuon.ngaytradukien, PhieuTra.ngaytrathucte);
			PhieuTra.kt = 1;
		}
	}
	return tmp;
}


void AddPhieuTraintoFile(Phieu PhieuTra, Phieu PhieuMuon)
{
	FILE *f1, *f2;
	char ch;
	int delete_line, temp = 1;
	delete_line = FindPhieuMuon(PhieuTra, PhieuMuon);
	f1 = fopen(PHIEU_FILE, "r");
	f2 = fopen(TMP_FILE, "w");
	ch = getc(f1);
	while (ch != EOF)
	{
		ch = getc(f1);
		if (ch == '\n')
			temp++;
		if (temp != delete_line)
		{
			putc(ch, f2);
		}
	}
	fclose(f1);
	fclose(f2);
	remove(PHIEU_FILE);
	rename(TMP_FILE, PHIEU_FILE);
	f1 = fopen(PHIEU_FILE, "a");
	fprintf(f1, "%s %d %d", PhieuTra.madocgia, PhieuTra.kt, PhieuTra.soluong);
	fprintf(f1, "%02d/%02d/%04d ", PhieuTra.ngaymuon.day, PhieuTra.ngaymuon.month, PhieuTra.ngaymuon.year);
	fprintf(f1, "%02d/%02d/%04d ", PhieuTra.ngaytradukien.day, PhieuTra.ngaytradukien.month, PhieuTra.ngaytradukien.year);
	fprintf(f1, "%02d/%02d/%04d ", PhieuTra.ngaytrathucte.day, PhieuTra.ngaytrathucte.month, PhieuTra.ngaytrathucte.year);

	for (int i = 0; i < PhieuTra.soluong; i++)
	{
		fprintf(f1, "%s ", PhieuTra.a[i].ISBN);
	}
	fclose(f1);
}