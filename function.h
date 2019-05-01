#pragma once
#include "const.h"
#include "User.h"
#include "LinkedListReader.h"



FUNCTION_CASE viewReader(User u, ListReader lReader);
FUNCTION_CASE addReader(User u, ListReader &lReader);
FUNCTION_CASE findReaderAsName(User u, ListReader &lReader);