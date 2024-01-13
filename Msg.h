#pragma once
//#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class Msg
{
public:
	Msg();
	void setMsg(int,string,int,int); //id, datetime, message, idFrom, idTo 
private:
	int _id;
	tm _datetime;
	string _message;
	int _from;
	int _to;
	
};

