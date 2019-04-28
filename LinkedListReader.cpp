#include "LinkedListReader.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void initList(List &l)
{
	l.head = NULL;
	l.tail = NULL;
	l.total = 0;
}

Node* CreatNode(TData data)
{
	Node *result = (Node*)malloc(sizeof(Node));

	int count = 3;

	while (!isCapPhatThanhCong((void*)result, "tao node")) {

		result = (Node*)malloc(sizeof(Node));
		count--;
		if (count == 0) return NULL;
	}

	result->data = data;
	result->next = NULL;

	return result;
}

Node* addFirst(List &l, Node *p)
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

Node* addLast(List &l, Node *p)
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

Node* addPos(List &l, Node *p, int pos)
{
	if (p == NULL) return NULL;
	if (pos > l.total) return NULL;
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	Node *tmp = l.head;
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

	return p;
}

Node* addFirst(List &l, TData data)
{
	Node *p = CreatNode(data);

	if (p == NULL) {
		return NULL;
	}
	return addFirst(l, p);
}

Node* addLast(List & l, TData data)
{
	Node *p = CreatNode(data);

	if (p == NULL) {
		return NULL;
	}
	return addLast(l, p);
}

Node* addPos(List & l, TData data, int pos)
{
	Node *p = CreatNode(data);

	if (p == NULL) {
		return NULL;
	}
	return addPos(l, p, pos);
}

void deletePos(List &l, int pos)
{
	if (pos > l.total) {
		return;
	}

	Node* tmp = l.head;
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

void showList(List l)
{
	if (l.head == NULL) {
		return;
	}

	while (l.head != NULL) {

		//Nen dung std::cout de co the dung TData tot nhat

		printf("%d", l.head->data);

		if (l.head->next != NULL) {
			printf(" -> ");
		}

		l.head = l.head->next;
	}
	printf("\n");
}

void deleteList(List &l)
{
	if (l.head == NULL) {
		return;
	}

	Node *current, *next;
	current = l.head;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	l = List();
}

TData getDataFirst(List l)
{
	assert(l.head != NULL);

	return l.head->data;
}

TData getDataLast(List l)
{
	assert(l.head != NULL);

	return l.tail->data;
}

TData getDataPos(List l, int pos)
{
	assert(l.head != NULL);

	Node* current = l.head;

	int count = 1;
	while (count != pos) {
		current = current->next;
		count++;
	}
	return current->data;
}


int getTotal(List l)
{
	return l.total;
}

Node* getNodeFromData(List l, TData data)
{
	if (l.head == NULL) {
		return NULL;
	}

	Node* current = l.head;
	while (current->data != data) {
		current = current->next;

		if (current == NULL) {
			return NULL;
		}
	}
	return current;
}

List joinList(List a, List b)
{
	assert(a.head != NULL && b.head != NULL);

	a.tail->next = b.head;
	a.total += b.total;
	return a;
}
