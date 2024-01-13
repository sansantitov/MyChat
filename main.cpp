#include "Msg.h"
#include "TArray.h"
#include "User.h"
#include "Chat.h"
#include <iostream>
#include <string>
#include "Functions.h"
#ifdef _WIN32
#include <Windows.h>
#endif
using namespace std;

TArray<User> users(1);
TArray<Msg> msgs(1);

int main()
{
#ifdef _WIN32
    int cp1 = GetConsoleCP();
    int cp2 = GetConsoleOutputCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    system("cls");

    Chat* chat = new Chat();
    string login = "", password = "", name = "", message = "";
    int rr, userIdFrom, userIdDest;
    bool isExit = false;
    while (!isExit)
    {
        cout << "login: ";
        cin >> login;
        cout << "password: ";
        cin >> password;
        int userIdFrom = chat->findUserId(login,password);

        if (userIdFrom < 0)
        {
            rr = 0;
            rout ("login-password не соответствуют пользователю!\n");
            rout("повторить-1, регистрация-2, выход-0: ") ;
            cin >> rr;
            if (rr == 0) break;
            if (rr == 1) continue;
            rout("*** регистрация ***\n");
            rout("login: ");
            cin >> login;
            rout("password: ");
            cin >> password;
            rout("имя: ");
            cin >> name;
            chat->addUser(login, password, name);
            rout("*** регистрация закончена ***\n");
            rout("войдите:\n");
            continue;
        }
        while (true)
        {
            rr = 0;
            rout("сообщение личное-1, всем-2, авторизация-3, закончить-0: ") ;
            cin >> rr;
            userIdDest = 0;
            if (rr == 0) {isExit = true; break;}
            if (rr == 3) {break;}
            if (rr == 1)
            {
                chat->showUsers();
                rout("адресат:\n");
                cin >> userIdDest;
            }
            rout("сообщение:\n");
            cin >> message;
            chat->sendMsg(userIdFrom, userIdDest, message);
            rout("*** отправлено ***\n");
        }

    }
#ifdef _WIN32
    //system("chcp 1251");
    SetConsoleCP(cp1);
    SetConsoleOutputCP(cp2);
#endif
    return 0;
}

