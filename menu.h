#pragma once
#include "User.h"
#include "LinkedListReader.h"

void menuMain(User &u);


void menuSub(User &u);
void menuSub_handler(User &u, int item);

void menuLogin(User &u);
void menuLogin_handler(User &u, int item);

void menuReader(User &u);
void menuReader(User &u, ListReader &lReader);
void menuReader_handler(User &u, ListReader &lReader, int item);

void menuReader_sub(User &u, ListReader &lReader, ListReader &findReader);
void menuReader_sub_handler(User &u, ListReader &lReader, ListReader &findReader, int item);
/*====================Chồng hàm================== */
//Độc giả
void menuChoice(User &u, ListReader &lReader); 