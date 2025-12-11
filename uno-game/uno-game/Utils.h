#pragma once
#include <iostream>
#include <string>
#include <vector>

#define string std::string
#define vector std::vector

#define LOG(X) << X
#define LOG_LN(X) << X << std::endl
#define LOG_EMPTY_LN() std::cout << std::endl

#define WAIT_FOR_INPUT _getch()
