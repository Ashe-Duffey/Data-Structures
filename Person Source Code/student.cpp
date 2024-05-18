#include <iostream>
#include <cstdlib>
#include "student.h"

using namespace std;

Person::Person()
{
	firstname = "Default ";
	lastname = "Default ";
	address = "Default ";
}

void Person::setfirstname (string value)
{
	bool check = true;
	for(int i = 0; i < value.length(); i++)
	{
		if(isspace(value[i]))
			check = false;
	}
	if(value.length() <= 15 && check == true) {
		firstname = value;
	}
		
}

void Person::setlastname (string value)
{
	bool check = true;
	for(int i = 0; i < value.length(); i++)
	{
		if(isspace(value[i]))
			check = false;
	}
	if(value.length() <= 15 && check == true)
		lastname = value;	
}

void Person::setaddress (string value)
{
	if(value.length() <= 20)
		address = value;	
}

string Person::getfirstname()
{
	return firstname;
}

string Person::getlastname()
{
	return lastname;
}

string Person::getaddress()
{
	return address;
}

void Person::display()
{
	int addstart = 35;
	cout << lastname << ", " << firstname;
	addstart = addstart - lastname.length();
	addstart = addstart - firstname.length();
	for(int i = 0; i < addstart; i++)
	{
		cout << " ";
	}
	cout << address << endl;
}

Student::Student()
{
		idnum = "0";
		gpa = 0;
		credits = 0;
		quality = 0;
	
}

void Student::setidnum (string val)
{
	idnum = val;
}

void Student::setcredits (int val)
{
	if(credits >= 0 && credits <= 199)
		credits = val;
}

void Student::setquality (int val)
{
	if(quality >= 0 && quality <= 796)
		quality = val;
}

void Student::setgpa()
{
	float math;
	if(quality > 0) {	
		math = (float)quality / (float)credits;
	}
	if(math >= 0.0)
		gpa = math;
}

string Student::getidnum()
{
	return idnum;
}

int Student::getcredits()
{
	return credits;
}

int Student::getquality()
{
	return quality;
}

float Student::getgpa()
{
	return gpa;
}

void Student::display() 
{
	int gpastart = 15;									//sets the amount of spaces GPA is from the start of the line
	int namestart = 6;
	
	cout << idnum;										//starts line with ID
	
	namestart = namestart - idnum.length();				//find the start of the names
	
	for(int i = 0; i < namestart; i++)					// create buffer to names.
	{
		cout << " ";
	}
	
	
	cout << getfirstname() + ", " + getlastname();		//prints name
	
	gpastart = gpastart - getfirstname().length();		//modifies g[pastart based on length of full name
	gpastart = gpastart - getlastname().length();
	
	for(int i = 0; i < gpastart; i++)					//spaces to gpastart value
	{
		cout << " ";
	}
		
	cout << gpa;										//prints GPA
}


