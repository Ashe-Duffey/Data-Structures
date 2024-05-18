#include "Clock.h"

Clock::Clock()
{
	hour = 1;
	min = 1;
}

void Clock::sethour(int newhour)
{
	hour = newhour;
}

void Clock::setmin(int minute)
{
	min = minute;
}

void Clock::addmin()
{
	min++;
	if(min == 60)
	{
		hour++;
		min = 0;
	}
}

Clock operator+(Clock start, int add)
{
	for(int i = 0; i < add; i++)
	{
		start.addmin();
	}
	return start;
}
