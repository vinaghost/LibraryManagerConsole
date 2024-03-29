#pragma once
#include "const.h"
#include "User.h"
#include "LinkedListUser.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"
#include "LinkedListCard.h"


/*========================1. Tài khoản==================================*/
void changePass(User &u, ListUser &lUser);
void changeInfo(User &u, ListUser &lUser);
void createUser(User &u, ListUser &lUser);

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
void creatTheMuon(User u, ListPhieu &lPhieuMuon, ListBook &lBook, ListReader &lReader);
void creatTheTra(User u, ListPhieu &lPhieuMuon, ListBook &lBook, ListReader &lReader);


void viewNumBook(User u, ListBook lBook);
void viewNumBookAsType(User u, ListBook lBook);
void viewNumReader(User u, ListReader lReader);
void viewNumReaderAsGender(User u, ListReader lReader);
void viewBookAsBorrow(User u, ListPhieu lPhieu);
void viewNumBookLate(User u, ListPhieu lPhieu);