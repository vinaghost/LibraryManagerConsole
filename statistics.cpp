#include "LinkedListReader.h"
#include "const.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListBook.h"

int soluongBook(ListBook lBook)
{
	int dem = 0;
	NodeBook *current, *next;
	current = lBook.head;
	while (current != NULL) {
		dem++;
		next = current->next;
		free(current);
		current = next;
	}
	return dem;
}

int soluongReader(ListReader lReader)
{
	int dem = 0;
	NodeReader *current, *next;
	current = lReader.head;
	while (current != NULL) {
		dem++;
		next = current->next;
		free(current);
		current = next;
	}
	return dem;
}

void Book_theotheloai(ListBook lBook, Book aBook[])
{
	int dem = -1;
	NodeBook *current, *next;
	current = lBook.head;
	while (current != NULL) {
			bool kt = false;
			for (int i = 0; i < dem; i++)
			{
				if (strcmp(current->data.TheLoai, aBook[i].TheLoai) == 0)
				{
					aBook[i].SoLuong = aBook[i].SoLuong + 1;
					kt = true;
				}
			}
			if (kt == false)
			{
				dem++;
				strcpy(current->data.TheLoai, aBook[dem].TheLoai);
				aBook[dem].SoLuong = aBook[dem].SoLuong + 1;
			}
		next = current->next;
		free(current);
		current = next;
	}
	for (int i = 0; i < dem; i++)
	{
		printf("The loai sach: %s  -  So luong: %d", aBook[i].TheLoai, aBook[i].SoLuong);
	}
}

void Reader_theogioitinh(ListReader lReader, Reader aReader[2])
{
	//aReader[1] chua so luong raeder nam, aReader[2] chua so luong reader nu
	NodeReader *current, *next;
	current = lReader.head;
	while (current != NULL) {
		if (current->data.nam == 1)
		{
			aReader[1].nam = aReader[1].nam + 1;
		}
		else if (current->data.nam == 0)
		{
			aReader[2].nam = aReader[2].nam + 1;
		}
		next = current->next;
		free(current);
		current = next;
	}
	printf("So luong doc gia nam: %d", aReader[1].nam);
	printf("So luong doc gia nu: %d", aReader[2].nam);
}

