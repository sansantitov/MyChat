#pragma once
#include <iostream>

class Msg
{
public:
	Msg();
    Msg(int, int, std::string, int, std::string); //id, idFrom, nameFrom, idTo, message
    void showMsg();
    std::string getTime();
    int getIdTo();
    std::string getMessage();

private:
	int _id;
    std::string _datetime;
    std::string _message;
	int _idFrom;
    std::string _nameFrom;
	int _idTo;
};

