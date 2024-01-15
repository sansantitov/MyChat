// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>

#include "Msg.h"
#include "TArray.h"
#include "User.h"
#include "Chat.h"
#include <iostream>
#include "Functions.h"
#ifdef _WIN32
#include <Windows.h>
#endif


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
    
    
    bool isExit = false;
    while (!isExit)
    {
        std::string login, password, name;
        rout("Введите login (0-регистрация нового): ");
        getline(std::cin, login);
        int userIdFrom = -1;
        std::string rr;
        if (login != "0")
        {
            std::cout << "password: ";
            getline(std::cin, password);
            userIdFrom = chat->findUserIdByLoginPassword(login, password);
        }
        else rr = "2";

        if (userIdFrom < 0)
        {
            if (rr != "2")
            {
                rout("login-password не соответствуют пользователю!\n");
                while (!(rr.length() == 1 && strchr("012", rr[0])))
                {
                    rout("повторить-1, регистрация-2, выход-0: ");
                    getline(std::cin, rr);
                }
            }
            
            if (rr == "0") break;
            if (rr == "1") continue;
            rout("*** регистрация ***\n");
            rout("login: ");
            getline(std::cin, login);
            rout("password: ");
            getline(std::cin, password);
            rout("имя: ");
            getline(std::cin, name);
            chat->addUser(login, password, name);
            rout("*** регистрация закончена, войдите ***\n");
            continue;
        }
        while (true)
        {
            std::string message;
            chat->showMsgs();
            std::string rr;
            std::string userIdTo;
            
            while (!(rr.length() == 1 && strchr("0123", rr[0])))
            {
                rout("сообщение личное-1, всем-2, авторизация (новый вход)-3, закончить-0: ");
                getline(std::cin, rr);
            }

            if (rr == "0") {isExit = true; break;}
            else if (rr == "3") {break;}
            int intUser = 0;
            if (rr == "1") 
            {
                while (true)
                {
                    chat->showUsers();
                    rout("Id адресата (всем-0): ");
                    getline(std::cin, userIdTo);
                    intUser = stoi(userIdTo);
                    if (userIdTo == "0" || (intUser > 0 && intUser <= chat->getUserIdCurrent())) break;
                }
            }
            rout("сообщение: ");
            getline(std::cin,message);
            chat->sendMsg(rr=="1"?intUser:0, message);
        }

    }
#ifdef _WIN32
    SetConsoleCP(cp1);
    SetConsoleOutputCP(cp2);
#endif
    delete chat;
    msgs.erase();
    users.erase();

    //_CrtDumpMemoryLeaks();
    return 0;
}

