#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstdlib>
#include <string>

//   comments

using namespace std;

class Person
{
	public:
		Person();
		
		void setfirstname (string val);
		void setlastname (string val);
		void setaddress (string val);
		
		string getfirstname();
		string getlastname();
		string getaddress();
		
		void display();
		
	protected:
			
		string firstname;
		string lastname;
		string address;
};

class Student : public Person
{
	public:
		Student();
		
		void setidnum (string val);
		void setcredits (int val);
		void setquality (int val);
		void setgpa();
		
		string getidnum();
		int getcredits();
		int getquality();
		float getgpa();
		
		void display();
		
	private:
		string idnum;
		float gpa;
		int credits;
		int quality;
		
};

#endif
