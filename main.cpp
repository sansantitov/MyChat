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
    //"0" - выход
    //"1" - сообщение
    
    //"3" - вход-авторизация(логин-пароль)
    //"4" - регистрация нового пользователя (логин-пароль-имя)


    while (!isExit)
    {
        std::string rr;
        
        while (!isExit)
        {
            rr = chat->login();
            if (rr == "0")
            {
                isExit = true;
                break;
            }
            else if (rr == "4") chat->registr();
            else break; //нормальная авторизация
        }


        while (true)
        {
            std::string message;
            chat->showMsgs();

            std::string userIdTo;


            std::string rr = choice("сообщение-1, авторизация (новый вход)-3, закончить-0: ", "130");

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
                rout("сообщение: ");
                getline(std::cin,message);
                chat->sendMsg(rr=="1"?intUser:0, message);
            }
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

