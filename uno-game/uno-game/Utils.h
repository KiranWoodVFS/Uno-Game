#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <conio.h>
#include <stdlib.h>

#define string std::string
#define vector std::vector
#define to_string std::to_string
#define shuffle std::shuffle

#define BLUE_COLOUR_LOG(X, Y) std::cout << "\033[94m" X(Y) // blue

#define LOG(X) << X
#define LOG_LN(X) << X << std::endl
#define LOG_EMPTY_LN() std::cout << std::endl

#define WAIT_FOR_INPUT _getch()
#define CLEAR_CONSOLE system("cls")

//Tobias utils
#define LOG_SPACE() std::cout << " "
#define COLOR_LOG(CODE, X, Y) std::cout << "\033[" << (CODE) << "m" X(Y)