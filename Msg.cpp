#include "Msg.h"
Msg::Msg()
{
	{
		time_t curTime = time(NULL);
		tm curTM;
		localtime_s(&curTM, &curTime);
		_datetime = curTM;
		_id = 0;
		_message = "";
		_from = 0;
		_to = 0;
	}
}

void Msg::setMsg(int id, string message, int from, int to)
{
	{
		time_t curTime = time(NULL);
		tm curTM;
		localtime_s(&curTM, &curTime);
		_datetime = curTM;
		_id = id;
		_message = message;
		_from = from;
		_to = to;
	}
}
