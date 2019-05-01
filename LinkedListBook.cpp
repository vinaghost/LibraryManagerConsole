#include "LinkedListBook.h"
#include "const.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initListBook(ListBook &l)
{
	l.head = NULL;
	l.tail = NULL;
	l.total = 0;
}

NodeBook* CreatNodeBook(TData data)
{
	NodeBook *result = (NodeBook*)malloc(sizeof(NodeBook));

	int count = 3;

	while (!isCapPhatThanhCong((void*)result, "tao NodeBook")) {

		result = (NodeBook*)malloc(sizeof(NodeBook));
		count--;
		if (count == 0) return NULL;
	}

	result->data = data;
	result->next = NULL;

	return result;
}

NodeBook* addFirst(ListBook &l, NodeBook *p)
{
	if (p == NULL) return NULL;

	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	p->next = l.head;
	l.head = p;
	l.total++;
	return p;
}

NodeBook* addLast(ListBook &l, NodeBook *p)
{
	if (p == NULL) return NULL;
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	l.tail->next = p;
	l.tail = p;
	l.total++;
	return p;
}

NodeBook* addPos(ListBook &l, NodeBook *p, int pos)
{
	if (p == NULL) return NULL;
	if (pos > l.total) return NULL;
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	NodeBook *tmp = l.head;
	int count = 1;
	while (count != pos - 1) {
		tmp = tmp->next;
		count++;

	}
	// before
	/* pos - 1      pos*/
	/*   tmp   -> tmp->next*/

	p->next = tmp->next;
	tmp->next = p;

	//after
	/* pos - 1   pos*/
	/*   tmp   ->  p  ->   tmp->next*/
	l.total++;
	return p;
}

NodeBook* addFirst(ListBook &l, TData data)
{
	NodeBook *p = CreatNodeBook(data);

	if (p == NULL) {
		return NULL;
	}
	return addFirst(l, p);
}

NodeBook* addLast(ListBook & l, TData data)
{
	NodeBook *p = CreatNodeBook(data);

	if (p == NULL) {
		return NULL;
	}
	return addLast(l, p);
}

NodeBook* addPos(ListBook & l, TData data, int pos)
{
	NodeBook *p = CreatNodeBook(data);

	if (p == NULL) {
		return NULL;
	}
	return addPos(l, p, pos);
}

void deletePos(ListBook &l, int pos)
{
	if (pos > l.total) {
		return;
	}

	NodeBook* tmp = l.head;
	int count = 1;
	while (count != pos - 1) {
		tmp = tmp->next;
		count++;
	}
	/* pos - 1     pos            pos + 1*/
	/*    tmp   tmp->next   (tmp->next)->next*/
	tmp->next = (tmp->next)->next;
	return;
}

int showListBook(ListBook l)
{
	if (l.head == NULL) {
		return -1;
	}
	printf("Co tong cong %d sach trong du lieu\n", l.total);
	int num = 1;
	while (l.head != NULL) {

		/*//Nen dung std::cout de co the dung TData tot nhat

		printf("%d", l.head->data);

		if (l.head->next != NULL) {
			printf(" -> ");
		}*/
		printf("Sach #%d/\n", num);
		num++;
		showBook(l.head->data);
		Line();

		l.head = l.head->next;
	}
	printf("\n");
	return 0;
}

void deleteListBook(ListBook &l)
{
	if (l.head == NULL) {
		return;
	}

	NodeBook *current, *next;
	current = l.head;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	l = ListBook();
}

TData getDataFirst(ListBook l)
{
	assert(l.head != NULL);

	return l.head->data;
}

TData getDataLast(ListBook l)
{
	assert(l.head != NULL);

	return l.tail->data;
}

TData getDataPos(ListBook l, int pos)
{
	assert(l.head != NULL);

	NodeBook* current = l.head;

	int count = 1;
	while (count != pos) {
		current = current->next;
		count++;
	}
	return current->data;
}


int getTotal(ListBook l)
{
	return l.total;
}

/*NodeBook* getNodeBookFromData(ListBook l, TData data)
{
	if (l.head == NULL) {
		return NULL;
	}

	NodeBook* current = l.head;
	while (current->data != data) {
		current = current->next;

		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}*/

ListBook getNodeBookFromData(ListBook l, char *data, BOOK_CASE type)
{
	ListBook result;
	initListBook(result);

	if (l.head == NULL) {
		return result;
	}

	NodeBook* current = l.head;
	switch (type)
	{
	case ISBN: {
		while (current != NULL) {
			if (strcmp(current->data.ISBN, data) == 0) {
				addLast(result, current);
			}
			current = current->next;
		}
		break;
	}
	case TEN_SACH: {
		while (current != NULL) {
			if (strcmp(current->data.TenSach, data) == 0) {
				addLast(result, current);

			}

			current = current->next;

		}
		break;
	}
	}


	return result;
}

ListBook joinListBook(ListBook a, ListBook b)
{
	assert(a.head != NULL && b.head != NULL);

	a.tail->next = b.head;
	a.total += b.total;
	return a;
}

void loadListBook(ListBook &l)
{
	FILE *BookFile;

	BookFile = fopen(BOOK_FILE, "r");

	if (BookFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", BOOK_FILE);
		return;
	}

	Book fBook;

	char str[200];
	while (fgets(str, sizeof(str), BookFile) != NULL) {

		/*char str[200];
		fgets(str, sizeof(str), BookFile);
		*/

		sscanf(str, "%[^,\n], %[^,\n], %[^,\n], %[^,\n], %[^,\n], %d, %d, %d\n", fBook.ISBN, fBook.TenSach, fBook.TenTacGia, fBook.NXB, fBook.TheLoai, &fBook.NamXB, &fBook.Gia, &fBook.SoLuong);


		addFirst(l, fBook);
	}

	fclose(BookFile);

}

void writeListBookToFile(ListBook l)
{
	FILE *BookFile;

	BookFile = fopen(BOOK_FILE, "w");

	if (BookFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", BOOK_FILE);
		return;
	}

	NodeBook* nBook;
	while (l.head != NULL) {

		nBook = l.head;

		fprintf(BookFile, "%s, %s, %s, %s, %s, %d, %d, %d\n", nBook->data.ISBN, nBook->data.TenSach, nBook->data.TenTacGia, nBook->data.NXB, nBook->data.TheLoai, nBook->data.NamXB, nBook->data.Gia, nBook->data.SoLuong);

		l.head = l.head->next;
	}

	fclose(BookFile);
}
