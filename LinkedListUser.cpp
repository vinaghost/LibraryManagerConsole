#include "LinkedListUser.h"
#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initListUser(ListUser &l)
{
	l.head = NULL;
	l.tail = NULL;
	l.total = 0;

}

NodeUser* CreatNodeUser(User data)
{
	NodeUser *result = (NodeUser*)malloc(sizeof(NodeUser));

	int count = 3;

	while (!isCapPhatThanhCong((void*)result, "tao NodeUser")) {

		result = (NodeUser*)malloc(sizeof(NodeUser));
		count--;
		if (count == 0) return NULL;
	}

	result->data = data;
	result->next = NULL;

	return result;
}

NodeUser* addFirst(ListUser &l, NodeUser *p)
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

NodeUser* addLast(ListUser &l, NodeUser *p)
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

NodeUser* addPos(ListUser &l, NodeUser *p, int pos)
{
	if (p == NULL) return NULL;
	if (pos > l.total) return NULL;
	if (l.head == NULL) {
		l.head = p;
		l.tail = p;
		l.total++;
		return p;
	}

	NodeUser *tmp = l.head;
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

NodeUser* addFirst(ListUser &l, User data)
{
	NodeUser *p = CreatNodeUser(data);

	if (p == NULL) {
		return NULL;
	}
	return addFirst(l, p);
}

NodeUser* addLast(ListUser & l, User data)
{
	NodeUser *p = CreatNodeUser(data);

	if (p == NULL) {
		return NULL;
	}
	return addLast(l, p);
}

NodeUser* addPos(ListUser & l, User data, int pos)
{
	NodeUser *p = CreatNodeUser(data);

	if (p == NULL) {
		return NULL;
	}
	return addPos(l, p, pos);
}

void deletePos(ListUser &l, int pos)
{
	if (l.head == NULL) {
		return;
	}

	if (pos > l.total) {
		return;
	}
	NodeUser* current = l.head;
	if (pos == 1) {

		l.head = l.head->next;
		free(current);
		return;
	}

	int count = 1;

	while (current != NULL) {
		if (count == pos - 1) {

			NodeUser* next = (current->next)->next;

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

void deleteListUser(ListUser &l)
{
	if (l.head == NULL) {
		return;
	}

	NodeUser *current, *next;
	current = l.head;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	initListUser(l);
}

NodeUser* getNodeUserPos(ListUser l, int pos)
{

	NodeUser* current = l.head;

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

int getTotal(ListUser l)
{
	return l.total;
}

void loadListUser(ListUser &l)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "r+");

	if (userFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", USER_FILE);
		return;
	}

	User fUser;
	char birth[DAY_LENGTH];
	char str[200];

	int count = 1;
	while (fgets(str, sizeof(str), userFile) != NULL) {

		sscanf(str, "%[^,\n], %[^,\n], %d, %[^,\n], %[^,\n], %[^,\n], %[^,\n], %d %d", fUser.name, fUser.password, &fUser.permission, fUser.HoTen, fUser.CMND, birth, fUser.DiaChi, &fUser.Nam, &fUser.active);

		fUser.location = count;
		fUser.ngaySinh = StringToDate(birth);
		addFirst(l, fUser);

		count++;
	}


	fclose(userFile);

}

void writeListUserToFile(ListUser l)
{
	FILE *userFile;

	userFile = fopen(USER_FILE, "w");

	if (userFile == NULL) {
		printf("[ERROR] Khong tim thay file %s", USER_FILE);
		return;
	}

	NodeUser* nUser;
	while (l.head != NULL) {

		nUser = l.head;


		char* birth = DateToString(nUser->data.ngaySinh);
		fprintf(userFile, "%s, %s, %d, %s, %s, %s, %s, %d, 1\n", nUser->data.name, nUser->data.password, nUser->data.permission, nUser->data.HoTen, nUser->data.CMND, birth, nUser->data.DiaChi, nUser->data.Nam);
		free(birth);
		l.head = l.head->next;
	}

	fclose(userFile);
}
