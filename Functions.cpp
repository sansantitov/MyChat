#include "Functions.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif


void rout(std::string text)
{
#ifdef _WIN32
    int cp = GetConsoleOutputCP();
    SetConsoleOutputCP(65001);
    std::cout << text;
    SetConsoleOutputCP(cp);
#endif
}





