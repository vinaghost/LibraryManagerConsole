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


void creatTheMuon(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);
void creatTheTra(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);


void viewNumBook(User u, ListBook lBook);
void viewNumBookAsType(User u, ListBook lBook, Book aBook[]);
void viewNumReader(User u, ListReader lReader);
void viewNumReaderAsGender(User u, ListReader lReader, Reader aReader[2]);
void viewBookAsBorrow(User u, ListPhieu lPhieu);
void viewNumReaderLate(User u, ListPhieu lPhieu);