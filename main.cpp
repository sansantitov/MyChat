#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

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
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#ifdef _WIN32
    int cp1 = GetConsoleCP();
    int cp2 = GetConsoleOutputCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    system("cls");
    Chat* chat = new Chat();
    
    
    bool isExit = false;
    while (!isExit)
    {
        string login, password, name;
        cout << "login: ";
        getline(cin, login);
        cout << "password: ";
        getline(cin, password);
        int userIdFrom = chat->findUserIdByLoginPassword(login, password);

        if (userIdFrom < 0)
        {
            string rr;
            rout ("login-password не соответствуют пользователю!\n");
            while (!(rr.length() == 1 && strchr("012", rr[0])))
            {
                rout("повторить-1, регистрация-2, выход-0: ");
                getline(cin, rr);
            }
            if (rr == "0") break;
            if (rr == "1") continue;
            rout("*** регистрация ***\n");
            rout("login: ");
            getline(cin, login);
            rout("password: ");
            getline(cin, password);
            rout("имя: ");
            getline(cin, name);
            chat->addUser(login, password, name);
            rout("*** регистрация закончена ***\n");
            rout("войдите:\n");
            continue;
        }
        while (true)
        {
            string message;
            chat->showMsgs();

            string rr;
            string userIdTo;
            
            while (!(rr.length() == 1 && strchr("0123", rr[0])))
            {
                rout("сообщение личное-1, всем-2, авторизация (новый вход)-3, закончить-0: ");
                getline(cin, rr);
            }

            if (rr == "0") {isExit = true; break;}
            else if (rr == "3") {break;}
            if (rr == "1") 
            {
                chat->showUsers();
                rout("Id адресата (всем-0):\n");
                getline(cin, userIdTo);
            }
            rout("сообщение:\n");
            getline(cin,message);
            chat->sendMsg(rr=="1"?stoi(userIdTo):0, message);
            rout("*** отправлено ***\n");
        }

    }
#ifdef _WIN32
    SetConsoleCP(cp1);
    SetConsoleOutputCP(cp2);
#endif
    delete chat;
    msgs.erase();
    users.erase();

    _CrtDumpMemoryLeaks();
    return 0;
}

