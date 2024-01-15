#pragma once
#include <string>

class User
{
public:
	User(); 
    User(int, std::string, std::string, std::string); //id,login,psw,name;
    void setUser(int, std::string, std::string, std::string); //id,login,psw,name
	void showUser();

    int getId();
    std::string getLogin();
    std::string getPsw();
    std::string getName();
private:
	int _id;
    std::string _login;
    std::string _psw;
    std::string _name;
};

