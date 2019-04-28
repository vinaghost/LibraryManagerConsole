#pragma once

#include "reader.h"

typedef Reader TData;

struct Node {
	TData data;
	Node* next;
};

struct List {
	Node *head, *tail;
	int total;


};

void initList(List &l);

Node* CreatNode(TData data);

Node* addFirst(List &l, Node *p);
Node* addLast(List &l, Node *p);
Node* addPos(List &l, Node *p, int pos);

Node* addFirst(List &l, TData data);
Node* addLast(List &l, TData data);
Node* addPos(List &l, TData data, int pos);

void deletePos(List &l, int pos);
void showList(List l);
void deleteList(List &l);

TData getDataFirst(List l);
TData getDataLast(List l);
TData getDataPos(List l, int pos);

int getTotal(List l);

Node* getNodeFromData(List l, TData data);

List joinList(List a, List b);