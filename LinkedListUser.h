#pragma once

#include "const.h"
#include "user.h"


struct NodeUser {
	User data;
	NodeUser* next;
};

struct ListUser {
	NodeUser *head, *tail;
	int total;
};

void initListUser(ListUser &l);

NodeUser* CreatNodeUser(User data);

NodeUser* addFirst(ListUser &l, NodeUser *p);
NodeUser* addLast(ListUser &l, NodeUser *p);
NodeUser* addPos(ListUser &l, NodeUser *p, int pos);

NodeUser* addFirst(ListUser &l, User data);
NodeUser* addLast(ListUser &l, User data);
NodeUser* addPos(ListUser &l, User data, int pos);

void deletePos(ListUser &l, int pos);
void deleteListUser(ListUser &l);

NodeUser* getNodeUserPos(ListUser l, int pos);

int getTotal(ListUser l);

void loadListUser(ListUser &l);

void writeListUserToFile(ListUser l);