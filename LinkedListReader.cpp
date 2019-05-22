#include "LinkedListReader.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initListReader(ListReader &l)
{
	l.head = NULL;
	l.tail = NULL;
	l.total = 0;
	l.nam = 0;
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

NodeReader* addFirst (ListReader &l, NodeReader *p)
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

	if (p->data.nam == 1) {
		l.nam++;
	}
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
	if (l.head == NULL) {
		return;
	}

	if (pos > l.total) {
		return;
	}
	NodeReader* current = l.head;
	if (pos == 1) {
		
		l.head = l.head->next;
		free(current);
		return;
	}

	int count = 1;

	while (current != NULL) {
		if (count == pos - 1) {
			
			NodeReader* next = (current->next)->next;

			if (current == NULL || current->next == NULL) {
				return;
			}
			free(current->next);
			
			current->next = next;
			return;
		}

		count++;
	}
	return;
}

int showListReader(ListReader l)
{
	if (l.head == NULL) {
		return -1;
	}
	printf("Co tong cong %d doc gia trong du lieu\n", l.total);
	int num = 0;
	while (l.head != NULL) {
		num++;
		printf("Doc gia #%d\n", num);
	
		showReader(l.head->data);
		Line();

		l.head = l.head->next;
	}
	printf("\n");
	return 0;
}

int showListReader(ListReader l, char* data, READER_CASE type)
{
	if (l.head == NULL) {
		return -1;
	}
	int num = 0;
	int count = 0;
	char *str = NULL;
	while (l.head != NULL) {
		num++;

		switch (type) {
			case HO_TEN: {
				str = l.head->data.HoTen;
				break;
			}
			case CMND: {
				str = l.head->data.CMND;
				break;
			}
		}

		if (strcmp(str, data) == 0) {
			printf("Doc gia #%d\n", num);
			count++;
			showReader(l.head->data);
			Line();
		}

		
		l.head = l.head->next;
	}
	printf("\n");
	return count;
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

	initListReader(l);
}

NodeReader* getNodeReaderPos(ListReader l, int pos)
{

	NodeReader* current = l.head;

	int count = 1;

	while (current != NULL) {
		if (count == pos) {
			return current;
		}
		count++;
		current = current->next;
	}
	return NULL;
}

int getPosReader(ListReader l, char* ms)
{
	NodeReader* current = l.head;

	int count = 1;
	while (current != NULL) {
		if (strcmp(ms, current->data.MS) == 0) {
			return count;
		}
		current = current->next;
		count++;
	}
	return -1;
}

int getTotal(ListReader l)
{
	return l.total;
}

void loadListReader(ListReader &l)
{
	FILE *readerFile;

	readerFile = fopen(READER_FILE, "r+");

	if (readerFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", READER_FILE);
		return;
	}

	Reader freader;
	
	char birth[DAY_LENGTH];
	char lapThe[DAY_LENGTH];
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
