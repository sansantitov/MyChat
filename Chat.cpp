#include "chat.h"
#include "TArray.h"
#include "User.h"
#include "Msg.h"
#include "Functions.h"

extern TArray<User> users;
extern TArray<Msg> msgs;



 Chat::Chat()
 {
     users[0].setUser(0,"All","1","All users");
     _userIdLogin = -1;
     _userIdCurrent = 0; //0-зарезервировано для выдачи всем
     _msgIdCurrent = -1;
 }

void Chat::addUser(std::string login, std::string password, std::string name)
{
    User* u = new User(++_userIdCurrent, login, password, name);
    //if (users.getLength() == 1) users[0] = *u;
    users.insertAtEnd(*u);
}

int Chat::findUserIdByLoginPassword(std::string login, std::string password)
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
    _userIdLogin = id;
    return id;
}

std::string Chat::findUserNameByUserId(int idUser)
{
    std::string name;
    for (int i = 0; i < users.getLength(); ++i)
    {
        if (users[i].getId() == idUser)
        {
            name = users[i].getName();
            break;
        }
    }
    return name;
}




void Chat::showUsers()
{
    rout("*** Id  Имя **********************\n");
    for (int i = 0; i < users.getLength(); ++i)
    {
        users[i].showUser();
    }
    std::cout << "********************************\n";
}

void Chat::sendMsg(int userIdTo, std::string message)
{
    std::string userName = findUserNameByUserId(_userIdLogin);
    Msg* m = new Msg(++_msgIdCurrent, _userIdLogin, userName, userIdTo, message);
    if (msgs.getLength() == 1 && msgs[0].getMessage()=="") msgs[0] = *m;
    else msgs.insertAtEnd(*m);
}

void Chat::showMsgs()
{
    std::string userName = findUserNameByUserId(_userIdLogin);
    std::cout << "******** " << userName << ": ";
    rout   ("принятые сообщения *******\n");
    for (int i = 0; i < msgs.getLength(); ++i)
    {
        if (msgs[i].getIdTo() == 0 || msgs[i].getIdTo() == _userIdLogin) msgs[i].showMsg();
    }
    std::string s(37+userName.length(), '*');
    std::cout << s << std::endl;
}

int Chat::getUserIdCurrent()
{
    return _userIdCurrent;
}


