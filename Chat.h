#pragma once
#include <string>
#include <iostream>
using namespace std;



class Chat
{
public:
    Chat();
	void addUser(string, string, string); //login, password, name
    int findUserIdByLoginPassword(string, string); //login, password
    string findUserNameByUserId(int);  //idUser
    void showUsers(); 
    void showMsgs();
    void sendMsg(int, string); //userIdTo, message
private:
    int _userIdLogin;
	int _userIdCurrent;
    int _msgIdCurrent;
	
};

