#pragma once
#include "Book.h"
#include "const.h"

struct NodeBook {
	Book data;
	NodeBook* next;
};

struct ListBook {
	NodeBook *head, *tail;
	int total;

	TypeBook* typeArray;
	int totalType;

};

void initListBook(ListBook &l);

NodeBook* CreatNodeBook(Book data);

NodeBook* addFirst(ListBook &l, NodeBook *p);
NodeBook* addLast(ListBook &l, NodeBook *p);
NodeBook* addPos(ListBook &l, NodeBook *p, int pos);

NodeBook* addFirst(ListBook &l, Book data);
NodeBook* addLast(ListBook &l, Book data);
NodeBook* addPos(ListBook &l, Book data, int pos);


void deletePos(ListBook &l, int pos);
int showListBook(ListBook l);
int showListBook(ListBook l, char* data, BOOK_CASE type);
void deleteListBook(ListBook &l);

NodeBook* getBookFromISBN(ListBook l, char* isbn);

int getTotal(ListBook l);

NodeBook* getNodeBookPos(ListBook l, int pos);

void loadListBook(ListBook &l);

void writeListBookToFile(ListBook l);