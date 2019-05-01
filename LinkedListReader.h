#pragma once

#include "reader.h"
#include "const.h"

typedef Reader TData;

struct NodeReader {
	TData data;
	NodeReader* next;
};

struct ListReader {
	NodeReader *head, *tail;
	int total;


};

void initListReader(ListReader &l);

NodeReader* CreatNodeReader(TData data);

NodeReader* addFirst(ListReader &l, NodeReader *p);
NodeReader* addLast(ListReader &l, NodeReader *p);
NodeReader* addPos(ListReader &l, NodeReader *p, int pos);

NodeReader* addFirst(ListReader &l, TData data);
NodeReader* addLast(ListReader &l, TData data);
NodeReader* addPos(ListReader &l, TData data, int pos);

void deletePos(ListReader &l, int pos);
int showListReader(ListReader l);
void deleteListReader(ListReader &l);

TData getDataFirst(ListReader l);
TData getDataLast(ListReader l);
TData getDataPos(ListReader l, int pos);

int getTotal(ListReader l);

//NodeReader* getNodeReaderFromData(ListReader l, TData data);
ListReader getNodeReaderFromData(ListReader l, char* data, READER_CASE type);

ListReader joinListReader(ListReader a, ListReader b);

void loadListReader(ListReader &l);

void writeListReaderToFile(ListReader l);