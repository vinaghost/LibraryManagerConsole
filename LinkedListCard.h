#pragma once


#include "const.h"
#include "Phieu.h"


struct NodePhieu {
	Phieu data;
	NodePhieu* next;
};

struct ListPhieu {
	NodePhieu *head, *tail;
	int total;


};

void initListPhieu(ListPhieu &l);

NodePhieu* CreatNodePhieu(Phieu data);

NodePhieu* addFirst(ListPhieu &l, NodePhieu *p);
NodePhieu* addLast(ListPhieu &l, NodePhieu *p);
NodePhieu* addPos(ListPhieu &l, NodePhieu *p, int pos);

NodePhieu* addFirst(ListPhieu &l, Phieu data);
NodePhieu* addLast(ListPhieu &l, Phieu data);
NodePhieu* addPos(ListPhieu &l, Phieu data, int pos);

void deletePos(ListPhieu &l, int pos);
int showListPhieu(ListPhieu l);
int showListPhieu(ListPhieu l, char* MS);
int showListPhieuLate(ListPhieu l);
void deleteListPhieu(ListPhieu &l);

NodePhieu* getNodePhieuPos(ListPhieu l, int pos);

int getPosFromData(ListPhieu l, char* ms, char* isbn);

int getTotal(ListPhieu l);

void loadListPhieu(ListPhieu &l, CARD_TYPE type);

void writeListPhieuToFile(ListPhieu l, CARD_TYPE type);