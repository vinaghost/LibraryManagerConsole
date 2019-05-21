#include "LinkedListCard.h"
#include "const.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initListPhieu(ListPhieu &l)
{
	l.head = NULL;
	l.tail = NULL;
	l.total = 0;
}

NodePhieu* CreatNodePhieu(Phieu data)
{
	NodePhieu *result = (NodePhieu*)malloc(sizeof(NodePhieu));

	int count = 3;

	while (!isCapPhatThanhCong((void*)result, "tao NodePhieu")) {

		result = (NodePhieu*)malloc(sizeof(NodePhieu));
		count--;
		if (count == 0) return NULL;
	}

	result->data = data;
	result->next = NULL;

	return result;
}

NodePhieu* addFirst(ListPhieu &l, NodePhieu *p)
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

NodePhieu* addLast(ListPhieu &l, NodePhieu *p)
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

NodePhieu* addPos(ListPhieu &l, NodePhieu *p, int pos)
{
	if (p == NULL) return NULL;
	if (pos > l.total) return NULL;
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	NodePhieu *tmp = l.head;
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

NodePhieu* addFirst(ListPhieu &l, Phieu data)
{
	NodePhieu *p = CreatNodePhieu(data);

	if (p == NULL) {
		return NULL;
	}
	return addFirst(l, p);
}

NodePhieu* addLast(ListPhieu & l, Phieu data)
{
	NodePhieu *p = CreatNodePhieu(data);

	if (p == NULL) {
		return NULL;
	}
	return addLast(l, p);
}

NodePhieu* addPos(ListPhieu & l, Phieu data, int pos)
{
	NodePhieu *p = CreatNodePhieu(data);

	if (p == NULL) {
		return NULL;
	}
	return addPos(l, p, pos);
}

void deletePos(ListPhieu &l, int pos)
{
	if (pos > l.total) {
		return;
	}

	NodePhieu* tmp = l.head;
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

int showListPhieu(ListPhieu l)
{
	if (l.head == NULL) {
		return -1;
	}
	printf("Co tong cong %d phieu trong du lieu\n", l.total);
	int num = 0;

	if (l.head->data.type == MUON) {
		while (l.head != NULL) {
			num++;
			printf("Phieu #%d\n", num);

			showPhieuMuon(l.head->data);
			Line();

			l.head = l.head->next;
		}
		printf("\n");
	}
	else {
		while (l.head != NULL) {
			num++;
			printf("Phieu #%d\n", num);

			showPhieuTra(l.head->data);
			Line();

			l.head = l.head->next;
		}
		printf("\n");
	}
	return num;
}

int showListPhieu(ListPhieu l, char* ms)
{
	if (l.head == NULL) {
		return -1;
	}
	int num = 0;

	if (l.head->data.type == MUON) {
		while (l.head != NULL) {
			num++;
			printf("Phieu #%d\n", num);

			if (strcmp(l.head->data.MS, ms) == 0) {
				showPhieuMuon(l.head->data);
				Line();
			}
			l.head = l.head->next;
		}
		printf("\n");
	}
	else {
		while (l.head != NULL) {
			num++;
			printf("Phieu #%d\n", num);

			if (strcmp(l.head->data.MS, ms) == 0) {
				showPhieuTra(l.head->data);
				Line();
			}

			l.head = l.head->next;
		}
		printf("\n");
	}
	return num;
}

int showListPhieuLate(ListPhieu l)
{
	if (l.head == NULL) {
		return -1;
	}
	int num = 0;

	if (l.head->data.type == MUON) {
		while (l.head != NULL) {
			num++;
			printf("Phieu #%d\n", num);
			showPhieuMuon(l.head->data);
			Line();
			if (getCachNgay(l.head->data.ngayTra, getToday()) > MUON_SACH_LENGTH) {
				break;
			}
			l.head = l.head->next;
		}
		printf("\n");
	}
	return num;
}

void deleteListPhieu(ListPhieu &l)
{
	if (l.head == NULL) {
		return;
	}

	NodePhieu *current, *next;
	current = l.head;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	initListPhieu(l);
}

NodePhieu* getNodePhieuPos(ListPhieu l, int pos)
{
	assert(l.head != NULL);

	NodePhieu* current = l.head;

	int count = 1;
	while (count != pos) {
		current = current->next;
		count++;
		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}

int getPosFromData(ListPhieu l, char *ms, char *isbn)
{
	assert(l.head != NULL);

	NodePhieu* current = l.head;

	int count = 1;
	while (current != NULL) {

		if (strcmp(current->data.MS, ms) == 0 && strcmp(current->data.ISBN, isbn) == 0) {
			return count;
		}

		current = current->next;
		count++;
	}

	return -1;
}

Phieu getPhieuFirst(ListPhieu l)
{
	assert(l.head != NULL);

	return l.head->data;
}

Phieu getPhieuLast(ListPhieu l)
{
	assert(l.head != NULL);

	return l.tail->data;
}

Phieu getPhieuPos(ListPhieu l, int pos)
{
	assert(l.head != NULL);

	NodePhieu* current = l.head;

	int count = 1;
	while (count != pos) {
		current = current->next;
		count++;
	}
	return current->data;
}


int getTotal(ListPhieu l)
{
	return l.total;
}


ListPhieu joinListPhieu(ListPhieu a, ListPhieu b)
{
	assert(a.head != NULL && b.head != NULL);

	a.tail->next = b.head;
	a.total += b.total;
	return a;
}

void loadListPhieu(ListPhieu &l, CARD_TYPE type)
{
	FILE *PhieuFile = NULL;

	switch (type) {
		case MUON: {
			PhieuFile = fopen(PHIEUMUON_FILE, "r");
			if (PhieuFile == NULL) {
				fopen(PHIEUMUON_FILE, "w");
				return;
			}
			break;
		}
		case TRA: {
			PhieuFile = fopen(PHIEUTRA_FILE, "r");
			if (PhieuFile == NULL) {
				fopen(PHIEUTRA_FILE, "w");
				return;
			}
			break;
		}
	}
	Phieu fPhieu;

	char ngayMuon[DAY_LENGTH];
	char ngayTra[DAY_LENGTH];
	// 10 + 15 + 2* DAY_LENGTH + 1
	char str[48];
	while (fgets(str, sizeof(str), PhieuFile) != NULL) {

		sscanf(str, "%[^,\n], %[^,\n], %[^,\n], %[^,\n]", fPhieu.MS, fPhieu.ISBN, ngayMuon, ngayTra);
		fPhieu.ngayMuon = StringToDate(ngayMuon);
		fPhieu.ngayTra = StringToDate(ngayTra);

		addFirst(l, fPhieu);
	}

	fclose(PhieuFile);

}

void writeListPhieuToFile(ListPhieu l, CARD_TYPE type)
{
	FILE *PhieuFile = NULL;

	switch (type) {
		case MUON: {
			PhieuFile = fopen(PHIEUMUON_FILE, "w");
			if (PhieuFile == NULL) {
				printf("[ERROR] Khong tim thay file %s", PHIEUMUON_FILE);
				return;
			}
			break;
		}
		case TRA: {
			PhieuFile = fopen(PHIEUTRA_FILE, "w");
			if (PhieuFile == NULL) {
				printf("[ERROR] Khong tim thay file %s", PHIEUTRA_FILE);
				return;
			}
			break;
		}
	}
	NodePhieu* nPhieu;
	while (l.head != NULL) {

		nPhieu = l.head;

		char *ngayMuon = DateToString(nPhieu->data.ngayMuon);
		char *ngayTra = DateToString(nPhieu->data.ngayTra);

		fprintf(PhieuFile, "%s, %s, %s, %s\n", nPhieu->data.MS, nPhieu->data.ISBN, ngayMuon, ngayTra);

		free(ngayMuon);
		free(ngayTra);

		l.head = l.head->next;
	}

	fclose(PhieuFile);
}
