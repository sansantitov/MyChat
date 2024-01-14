#include "User.h"
#include <iostream>

User::User()
{

	_id = -1;
	_login = "";
	_psw = "";
	_name = "";

}


User::User(int id, string login, string psw, string name)
{
	
	_id = id;
	_login = login;
	_psw = psw;
	_name = name;
	
}


void User::setUser(int id, string login, string psw, string name)
{

	_id = id;
	_login = login;
	_psw = psw;
	_name = name;

}

void User::showUser()
{
	const string str = "     " + to_string( _id) + "  " + _name+"\n";
	std::cout << str;
}

int User::getId()
{
    return _id;
}

string User::getLogin()
{
    return _login;
}

string User::getPsw()
{
    return _psw;
}

string User::getName()
{
    return _name;
}
