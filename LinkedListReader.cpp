#include "LinkedListReader.h"
#include "const.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initListReader(ListReader &l)
{
	l.head = NULL;
	l.tail = NULL;
	l.total = 0;
}

NodeReader* CreatNodeReader(Reader data)
{
	NodeReader *result = (NodeReader*)malloc(sizeof(NodeReader));

	int count = 3;

	while (!isCapPhatThanhCong((void*)result, "tao NodeReader")) {

		result = (NodeReader*)malloc(sizeof(NodeReader));
		count--;
		if (count == 0) return NULL;
	}

	result->data = data;
	result->next = NULL;

	return result;
}

NodeReader* addFirst(ListReader &l, NodeReader *p)
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

NodeReader* addLast(ListReader &l, NodeReader *p)
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

NodeReader* addPos(ListReader &l, NodeReader *p, int pos)
{
	if (p == NULL) return NULL;
	if (pos > l.total) return NULL;
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	NodeReader *tmp = l.head;
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

NodeReader* addFirst(ListReader &l, Reader data)
{
	NodeReader *p = CreatNodeReader(data);

	if (p == NULL) {
		return NULL;
	}
	return addFirst(l, p);
}

NodeReader* addLast(ListReader & l, Reader data)
{
	NodeReader *p = CreatNodeReader(data);

	if (p == NULL) {
		return NULL;
	}
	return addLast(l, p);
}

NodeReader* addPos(ListReader & l, Reader data, int pos)
{
	NodeReader *p = CreatNodeReader(data);

	if (p == NULL) {
		return NULL;
	}
	return addPos(l, p, pos);
}

void deletePos(ListReader &l, int pos)
{
	if (pos > l.total) {
		return;
	}

	NodeReader* tmp = l.head;
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

int showListReader(ListReader l)
{
	if (l.head == NULL) {
		return -1;
	}
	printf("Co tong cong %d doc gia trong du lieu\n", l.total);
	int num = 1;
	while (l.head != NULL) {

		/*//Nen dung std::cout de co the dung Reader tot nhat

		printf("%d", l.head->data);

		if (l.head->next != NULL) {
			printf(" -> ");
		}*/
		printf("Doc gia #%d/\n", num);
		num++;
		showReader(l.head->data);
		Line();

		l.head = l.head->next;
	}
	printf("\n");
	return 0;
}

void deleteListReader(ListReader &l)
{
	if (l.head == NULL) {
		return;
	}

	NodeReader *current, *next;
	current = l.head;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	l = ListReader();
}

Reader geReaderFirst(ListReader l)
{
	assert(l.head != NULL);

	return l.head->data;
}

Reader geReaderLast(ListReader l)
{
	assert(l.head != NULL);

	return l.tail->data;
}

Reader geReaderPos(ListReader l, int pos)
{
	assert(l.head != NULL);

	NodeReader* current = l.head;

	int count = 1;
	while (count != pos) {
		current = current->next;
		count++;
	}
	return current->data;
}


int getTotal(ListReader l)
{
	return l.total;
}

/*NodeReader* getNodeReaderFromData(ListReader l, Reader data)
{
	if (l.head == NULL) {
		return NULL;
	}

	NodeReader* current = l.head;
	while (current->data != data) {
		current = current->next;

		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}*/

ListReader getNodeReaderFromData(ListReader l, char *data, READER_CASE type)
{
	ListReader result;
	initListReader(result);

	if (l.head == NULL) {
		return result;
	}

	NodeReader* current = l.head;
	switch(type) 
	{
		case HO_TEN: {
			while (current != NULL) {
				if (strcmp(current->data.HoTen, data) == 0) {
					addLast(result, current);
				}
				current = current->next;
			}
			break;
		}
		case CMND: {
			while (current != NULL) {
				if (strcmp(current->data.CMND, data) == 0) {
					addLast(result, current);

				}

				current = current->next;

			}
			break;
		}
	}
	

	return result;
}

ListReader joinListReader(ListReader a, ListReader b)
{
	assert(a.head != NULL && b.head != NULL);

	a.tail->next = b.head;
	a.total += b.total;
	return a;
}

void loadListReader(ListReader &l)
{
	FILE *readerFile;

	readerFile = fopen(READER_FILE, "r");

	if (readerFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", READER_FILE);
		return;
	}

	Reader freader;
	
	char birth[11];
	char lapThe[11];
	char str[200];
	while (fgets(str, sizeof(str), readerFile)!= NULL) {

		/*char str[200];
		fgets(str, sizeof(str), readerFile);
		*/

		sscanf(str, "%[^,\n], %[^,\n], %[^,\n], %[^,\n], %d, %[^,\n]\n", freader.MS, freader.HoTen, freader.CMND, birth, &freader.nam, lapThe);
		freader.birth = StringToDate(birth);
		freader.lapThe = StringToDate(lapThe);

		addFirst(l, freader);
	}

	fclose(readerFile);

}

void writeListReaderToFile(ListReader l)
{
	FILE *readerFile;

	readerFile = fopen(READER_FILE, "w");

	if (readerFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", READER_FILE);
		return;
	}

	NodeReader* nReader;
	while (l.head != NULL) {

		nReader = l.head;


		char *birth = DateToString(nReader->data.birth);
		char *lapThe = DateToString(nReader->data.lapThe);

		fprintf(readerFile, "%s, %s, %s, %s, %d, %s\n", nReader->data.MS, nReader->data.HoTen, nReader->data.CMND, birth, nReader->data.nam, lapThe);

		free(birth);
		free(lapThe);

		l.head = l.head->next;
	}

	fclose(readerFile);
}
