#pragma once
#include "User.h"
#include "LinkedListUser.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"
#include "LinkedListCard.h"

void menuMain(User &u);

void menuSub(User &u);


void menuChoice();
/*========================Đăng nhập=============================*/
void menuLogin(User &u);
void menuLogin_handler(User &u, int item);


/*========================Tài khoản=============================*/
void menuUser(User &u, ListUser &lUser);

/*========================Độc giả=============================*/
void menuReader(User &u, ListReader &lReader);

/*========================Sách=============================*/
void menuBook(User &u, ListBook &lBook);

/*========================Phiếu=============================*/
void menuPhieu(User &u, ListPhieu &lPhieuMuon, ListBook &lBook, ListReader &lReader);

/*========================Thống kê=============================*/
void menuStatistics(User &u, ListPhieu &lPhieuMuon, ListBook &lBook, ListReader &lReader);

