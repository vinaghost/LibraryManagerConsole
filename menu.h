#pragma once
#include "User.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"
#include "LinkedListCard.h"

void menuMain(User &u);


void menuSub(User &u);
void menuSub_handler(User &u, int item);


/*========================Đăng nhập=============================*/
void menuLogin(User &u);
void menuLogin_handler(User &u, int item);


/*========================Tài khoản=============================*/

void menuUser(User &u);
void menuUser_handler(User &u, int item);
void menuChoice(User &u);

/*========================Độc giả=============================*/
void menuReader(User &u);
void menuReader(User &u, ListReader &lReader);
void menuReader_handler(User &u, ListReader &lReader, int item);
void menuChoice(User &u, ListReader &lReader);

/*========================Sách=============================*/
void menuBook(User &u);
void menuBook(User &u, ListBook &lBook);
void menuBook_handler(User &u, ListBook &lBook, int item);
void menuChoice(User &u, ListBook &lBook);

/*========================Phiếu=============================*/
void menuPhieu(User &u);
void menuPhieu(User &u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);
void menuPhieu_handler(User &u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader, int item);
void menuChoice(User &u, ListPhieu &lPhieuMuon, ListPhieu &lPhieuTra, ListBook &lBook, ListReader &lReader);

