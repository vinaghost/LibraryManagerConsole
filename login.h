
#ifndef _LOGIN_H_

#define _LOGIN_H_

#include "User.h"

// hàm isExistUser
//
// Đối số:
// User u - user được người dùng nhập
// 
// Trả về: User tìm thấy còn không tìm thấy sẽ là User rỗng
User isExistUser(User u);


// hàm isPassWordSame
//
// Đối số:
// User u - user được người dùng nhập
// User f - user tìm trong file
//
// Trả về: 1 nếu trùng password 0 nếu sai password
int isPassWordSame(User u, User f);

#endif // !_LOGIN_H_
