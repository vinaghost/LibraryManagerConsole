#pragma once
#include "const.h"
#include "User.h"
#include "LinkedListReader.h"
#include "LinkedListBook.h"




FUNCTION_CASE viewReader(User u, ListReader lReader);
FUNCTION_CASE addReader(User u, ListReader &lReader);
FUNCTION_CASE findReaderAsName(User u, ListReader &lReader, ListReader &findReader);
FUNCTION_CASE findReaderAsCMND(User u, ListReader &lReader, ListReader &findReader);

FUNCTION_CASE viewBook(User u, ListBook lBook);
FUNCTION_CASE addBook(User u, ListBook &lBook);
FUNCTION_CASE findBookAsName(User u, ListBook &lBook, ListBook &findBook);
FUNCTION_CASE findBookAsCMND(User u, ListBook &lBook, ListBook &findBook);