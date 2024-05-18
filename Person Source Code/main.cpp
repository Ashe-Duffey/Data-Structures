#include "student.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int i = 0;
	string id, cd, ql;
	int intid, intcd, intql;
	string fn, ln, add;											//initailizing variables
	Student *ptr = new Student[20];
	
	
	ifstream inp ("input.txt");									//opens the file input.txt
																//this is where a very odd error occurs. I don't know if this is an OS thing or a code thing, but it instead of reading the existing
																//input.txt file it creates a new one and reads from that. Really odd issue and I can't find how to fix it anywhere.
																//the read and print portions of the code seem to work fine because they read and print the empty input.txt just fine.
																//if this works well for you, please notify me, I wnat to know if this is an issue with my computer or antivirus software prohibiting
																//reading from the directory.
	
	
	if (inp.fail())												//Error checks the file being opened
	{
		cout << "Error opening the file";
	}
	
	else
	{
		while(!inp.eof())										//will repeat until file inp returns eof
		{
			//inp >> fn;
			getline(inp,fn);
			cout << fn + " ";
			ptr[0 + i].setfirstname(fn);						//records and sets first name
		
			//inp >> ln;
			getline(inp,ln);
			cout << ln + " ";
			ptr[0 + i].setlastname(ln);							//records and sets last name
		
			//inp >> add;
			getline(inp,add);
			cout << add + " ";
			ptr[0 + i].setaddress(add);							//records and sets address
		
			//inp >> id;
			getline(inp,id);
			//istringstream issid (id);
			//issid >> intid;
			cout << id + " ";
			ptr[0 + i].setidnum(id);							//records and sets id 
		
			//inp >> cd;
			getline(inp,cd);
			istringstream isscd (cd);
			isscd >> intcd;
			cout << intcd + " ";
			ptr[0 + i].setcredits(intcd);							//records and sets credits
		
			//inp >> ql;
			getline(inp,ql);
			istringstream issql (ql);
			issql >> intql;
			cout << intql + " ";
			ptr[0 + i].setquality(intql);							//records and sets quality
			
			ptr[0 + i].setgpa();								//calculates and sets gpa
			
			i++;												//moves to next storage variable in array
		}
		inp.close();											//closes file
	}
		
	
	for(int n = 0; n < i; n++)									//runs the display function for each storage variable until the end of student				
	{
		cout << "\n";
		ptr[n].display();
	}
	
	
	
	return 0;
}
