#include "Functions.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void rout(string text)
{
#ifdef _WIN32
    UINT cp = GetConsoleOutputCP();
    SetConsoleOutputCP(65001);
    cout << text;
    SetConsoleOutputCP(cp);
#endif
}



