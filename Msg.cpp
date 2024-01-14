#include "Msg.h"
#include "Functions.h"
#include <iostream>

Msg::Msg()
{
	time_t curTime = time(NULL);
	tm curTM;
	localtime_s(&curTM, &curTime);
	strftime(_datetime, 100, "%d.%m.%C %T ", &curTM);
	_id = 0;
	_message = "";
	_idFrom = 0;
	_nameFrom = "";
	_idTo = 0;
		
	
}

Msg::Msg(int id, int idFrom, string nameFrom, int idTo, string message)
{
	
	time_t curTime = time(NULL);
	tm curTM;
	localtime_s(&curTM, &curTime);
	strftime(_datetime, 100, "%d.%m.%C %T ", &curTM);
	_id = id;
	_message = message;
	_idFrom = idFrom;
	_nameFrom = nameFrom;
	_idTo = idTo;
}

void Msg::showMsg()
{
	if (!_message.empty())
	{
		string dtStr = _datetime;
		const string str = dtStr + " "+ _nameFrom + ":  " + _message + "\n";
		std::cout << str;
	}
}
