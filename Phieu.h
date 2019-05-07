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
