#pragma once
#include <iostream>

class Chat
{
public:
    Chat();
    void addUser(std::string, std::string, std::string); //login, password, name
    int findUserIdByLoginPassword(std::string, std::string); //login, password
    std::string findUserNameByUserId(int);  //idUser
    void showUsers(); 
    void showMsgs();
    void sendMsg(int, std::string); //userIdTo, message
    int getUserIdCurrent();
    void registr();
    int getUserIdLogin();
    std::string login();

private:
    int _userIdLogin;
	int _userIdCurrent;
    int _msgIdCurrent;
	
};

