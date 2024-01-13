#pragma once
#include <string>
using namespace std;
class User
{
public:
	User(); 
	User(int, string, string, string); //id,login,psw,name; 
	void setUser(int, string, string, string); //id,login,psw,name
    int getId();
    string getLogin();
    string getPsw();
    string getName();
private:
	int _id;
	string _login;
	string _psw;
	string _name;
};

