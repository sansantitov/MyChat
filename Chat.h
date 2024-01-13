#pragma once
#include <string>
#include <iostream>
using namespace std;



class Chat
{
public:
    Chat();
	void addUser(string, string, string); //login, password, name
    int findUserId(string, string); //login, password
    void showUsers(); //login, password
    void sendMsg(int, int, string); //userIdFrom, userIdDest, message
//private:
//	int currentUserId;
	
};

