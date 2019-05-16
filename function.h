#pragma once
#include "const.h"
#include "User.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"
#include "LinkedListCard.h"


/*========================1. Tài khoản==================================*/
void changePass(User &u);
void changeInfo(User &u);
void createUser(User &u);

/*========================2. Quản lí độc giả==================================*/
void viewReader(User u, ListReader lReader);
void addReader(User u, ListReader &lReader);
void editReader(User u, ListReader &lReader);
void deleteReader(User u, ListReader &lReader);
void findReaderAsName(User u, ListReader &lReader);
void findReaderAsCMND(User u, ListReader &lReader);

/*========================3. Quản lí sách==================================*/
void viewBook(User u, ListBook lBook);
void addBook(User u, ListBook &lBook);
void editBook(User u, ListBook &lBook);
void deleteBook(User u, ListBook &lBook);
void findBookAsName(User u, ListBook &lBook);
void findBookAsISBN(User u, ListBook &lBook);

/*========================4. Thẻ ==================================*/
void creatTheMuon(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);
void creatTheTra(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);

void soluongBook(ListBook lBook);
void soluongReader(ListReader lReader);
void Book_theotheloai(ListBook lBook, Book aBook[]);
void Reader_theogioitinh(ListReader lReader, Reader aReader[2]);
void Card_trehan(ListPhieu lPhieu);
void creatTheTra(User u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);

/*========================5.Thống kê ==================================*/
void viewNumBook(User u, ListBook lBook);