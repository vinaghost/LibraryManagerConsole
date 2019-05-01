#pragma once
#include "User.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"

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




void menuBook(User &u);
void menuBook(User &u, ListBook &lBook);
void menuBook_handler(User &u, ListBook &lBook, int item);

void menuBook_sub(User &u, ListBook &lBook, ListBook &findBook);
void menuBook_sub_handler(User &u, ListBook &lBook, ListBook &findBook, int item);

void menuChoice(User &u, ListBook &lBook);