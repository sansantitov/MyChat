#include "chat.h"
#include "TArray.h"
#include "User.h"
#include "Msg.h"
#include "Functions.h"
extern TArray<User> users;
extern TArray<Msg> msgs;



 Chat::Chat()
 {
     users[0].setUser(0,"admin","1","Admin");
     //currentUserId = -1;
 }

void Chat::addUser(string login, string password, string name)
{
    int id = users.getLength();
    User* u = new User(id, login, password, name);
    users.insertAtEnd(*u);
}

int Chat::findUserId(string login, string password)
{
    int id = -1;
    for (int i = 0; i < users.getLength(); ++i)
    {
        if (users[i].getLogin() == login && users[i].getPsw() == password)
        {
            id = users[i].getId();
            break;
        }
    }
    //currentUserId = id;
    return id;
}

void Chat::showUsers()
{
    rout("*** Id  Имя (Login) **************\n");
    for (int i = 0; i < users.getLength(); ++i)
    {
        string name = users[i].getName();
        string str = "    " + to_string(users[i].getId()) + "  " + users[i].getName() + "(" + users[i].getLogin() + ")\n";
        cout << str;
    }
    rout("********************************\n");
}

void Chat::sendMsg(int userIdFrom, int userIdDest, string message)
{
    
}
