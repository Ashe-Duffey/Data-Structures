#include <iostream>

#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
	public:
		Clock();
		
		void sethour(int newhour);
		void setmin(int minute);
		
		void addmin();
		
		friend Clock operator+(Clock start, int add);
	private:
		int hour;
		int min;
};

#endif
