//  Stacy Hartz, Kristen Hartz, Marc Gibson, Luke Duffey
//  CSC 328 Assignment 1
//  Referenced Starting Out with C++ from Control Structures through Objects

#include <iostream>
#include <cstdlib>
#include "set.h"
#include <fstream>

int errorCheck(int);
// Description:     checks for a valid integer
// Precondition:    must check for an integer
// Postcondition:   returns a valid integer

void menuOptions(void);
// Description:     displays menu
// Precondition:    none
// Postcondition:   displays the menu options on the screen

using namespace std;

int main()
{
    Set set1;                   // Creates set
    int num1 = 0, num2 = 0;
    bool flag;                  // To see if value was found when search is called
    int menuOption = 0;
    
    menuOptions();              //prints the menu
    
    while(menuOption != 5)
    {
        menuOption = 0;         //sets the menu option back to 0 to loop again
        
        while(menuOption < 1 || menuOption > 5)
        {
            cout << "\nPlease enter a valid menu option: ";
            menuOption = errorCheck(num1);
        }
        
        switch (menuOption)
        {
            case 1:     // Insert
                cout << "\nEnter the number you want to insert into the set: " << endl;
                num2 = errorCheck(num1);
                set1.insert(num2);
                break;
                
            case 2:     // Search
                cout << "\nEnter the number you want to search for in the set: " << endl;
                num2 = errorCheck(num1);
                flag = set1.search(num2);
                
                if(flag)
                    cout << "\nValue was found in the set.  Current node is now at " << num2 << endl;
                else
                    cout << "\nValue was not found in the set." << endl;
                    
                break;
                
            case 3:     // Remove
                num1 = set1.remove();
                
                if(num1 == -1)
                    cout << "\nThe set is empty." << endl;
                else
                    cout << "\n" << num1 << " was removed from the set." << endl;
                
                break;
                
            case 4:     // Display
                cout << "\nThe numbers in the set are: \n" << set1 << endl;
                break;
                
            case 5:     // Quit
                cout << "\nYou quit!" << endl;
                break;
                
            default:    //bad input
                cout << "\nEnter a valid number\n" << endl;
                break;
        }
    }
    system("PAUSE");
    return 0;
}


void menuOptions(void)
{
    cout << "Menu Options:" << endl;
    cout << "1: Inserts an integer after the current value" << endl;
    cout << "2: Searches for an integer in the set" << endl;
    cout << "3: Removes the current value" << endl;
    cout << "4: Displays the set" << endl;
    cout << "5: Quits the program" << endl;
}


int errorCheck(int num)
{
    // When user enters invalid data
    while(!(cin >> num) || cin.peek() != '\n')
    {
        cout << "\nPlease enter an integer: ";
        cin.clear();
        cin.ignore(30000, '\n');
    }
    return num;
}
