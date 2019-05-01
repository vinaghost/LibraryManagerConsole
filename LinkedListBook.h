#pragma once
#include "Book.h"
#include "const.h"

typedef Book TData;

struct NodeBook {
	TData data;
	NodeBook* next;
};

struct ListBook {
	NodeBook *head, *tail;
	int total;


};

void initListBook(ListBook &l);

NodeBook* CreatNodeBook(TData data);

NodeBook* addFirst(ListBook &l, NodeBook *p);
NodeBook* addLast(ListBook &l, NodeBook *p);
NodeBook* addPos(ListBook &l, NodeBook *p, int pos);

NodeBook* addFirst(ListBook &l, TData data);
NodeBook* addLast(ListBook &l, TData data);
NodeBook* addPos(ListBook &l, TData data, int pos);


void deletePos(ListBook &l, int pos);
int showListBook(ListBook l);
void deleteListBook(ListBook &l);

TData getDataFirst(ListBook l);
TData getDataLast(ListBook l);
TData getDataPos(ListBook l, int pos);

int getTotal(ListBook l);

ListBook getNodeBookFromData(ListBook l, char* data, BOOK_CASE type);

ListBook joinListBook(ListBook a, ListBook b);

void loadListBook(ListBook &l);

void writeListBookToFile(ListBook l);