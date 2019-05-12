#pragma once
#include "const.h"
#include "User.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"
#include "LinkedListCard.h"


void changePass(User &u);
void changeInfo(User &u);
void createUser(User &u);

void viewReader(User u, ListReader lReader);
void addReader(User u, ListReader &lReader);
void editReader(User u, ListReader &lReader);
void deleteReader(User u, ListReader &lReader);
void findReaderAsName(User u, ListReader &lReader);
void findReaderAsCMND(User u, ListReader &lReader);

void viewBook(User u, ListBook lBook);
void addBook(User u, ListBook &lBook);
void editBook(User u, ListBook &lBook);
void deleteBook(User u, ListBook &lBook);
void findBookAsName(User u, ListBook &lBook);
void findBookAsISBN(User u, ListBook &lBook);


void creatTheMuon(User u, ListPhieu &lPhieu);