#pragma once
#include "User.h"
#include "LinkedListReader.h"

void menuMain(User &u);


void menuSub(User &u);
void menuSub_handler(User &u, int item);

void menuLogin(User &u);
void menuLogin_handler(User &u, int item);

void menuReader(User &u);
void menuReader_handler(User &u, ListReader lReader, int item);

