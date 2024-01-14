#pragma once
//#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Msg
{
public:
	Msg();
	Msg(int, int, string, int, string); //id, idFrom, nameFrom, idTo, message 
	void showMsg(); 
private:
	int _id;
	char _datetime[100];
	string _message;
	int _idFrom;
	string _nameFrom;
	int _idTo;
	
	
};

