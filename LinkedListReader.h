#pragma once

#include "reader.h"
#include "const.h"


struct NodeReader {
	Reader data;
	NodeReader* next;
};

struct ListReader {
	NodeReader *head, *tail;
	int total;


};

void initListReader(ListReader &l);

NodeReader* CreatNodeReader(Reader data);

NodeReader* addFirst(ListReader &l, NodeReader *p);
NodeReader* addLast(ListReader &l, NodeReader *p);
NodeReader* addPos(ListReader &l, NodeReader *p, int pos);

NodeReader* addFirst(ListReader &l, Reader data);
NodeReader* addLast(ListReader &l, Reader data);
NodeReader* addPos(ListReader &l, Reader data, int pos);

void deletePos(ListReader &l, int pos);
int showListReader(ListReader l);
int showListReader(ListReader l, char* data, READER_CASE type);
void deleteListReader(ListReader &l);

Reader geReaderFirst(ListReader l);
Reader geReaderLast(ListReader l);
Reader geReaderPos(ListReader l, int pos);

int getTotal(ListReader l);

//NodeReader* getNodeReaderFromData(ListReader l, Reader data);
//ListReader getNodeReaderFromData(ListReader l, char* data, READER_CASE type);

ListReader joinListReader(ListReader a, ListReader b);

void loadListReader(ListReader &l);

void writeListReaderToFile(ListReader l);