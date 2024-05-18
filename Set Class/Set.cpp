#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "set.h"

using namespace std;

// CONSTRUCTOR
Set::Set()
{
    head = 0;                                           
    current = 0;                                        
    temp = 0;                                           
}


// DESTRUCTOR  (Referenced page 1152 in our textbook)
Set::~Set()
{
    Node *ptr1, *ptr2;                                  //To traverse the set and point to the next node
    ptr1 = head;                                        //pointer 1 is assigned to the head pointer's node
    
    while(ptr1 != 0)                                    //loops until pointer 1 = null
    {
        ptr2 = ptr1 -> next;                            //pointer 2 is assigned the node in front of pointer 1
        delete ptr1;                                    //ptr 1 node is deleted
        ptr1 = ptr2;                                    //ptr 1 is brought to ptr 2
    }

    head = 0;                                           //assigns head to null      |these make sure the pointers are squared away neatly
    current = 0;                                        //assigns current to null
    temp = 0;                                           //assigns temp tp null
}


void Set::insert(const int value)
{
    bool flag;                                          //flag is used to check if value is already in the linked list
    Node *hold = current;                               //Holds where the current node is
    flag = search(value);                               //Checks to see if value is already in the set
    
    if(flag)    // Value is found
    {
        cout << "That number is already in the set." << endl;   //prints to the console if value is already in the linked list
        current = hold;                                         //when search function is called current changes |brings current back to hold
    }
    else        // Value is not found
    {
        if(!head)                                               //if head = null
        {
            head = new Node;                                    //head points to new node
            current = head;                                     //current points to head
            current -> data = value;                            //current puts the value into the new node
            head -> next = 0;                                   //only one node so points to the end
        }
        else                                                    // Inserts a new node after the current node
        {
            if(current -> next == 0)                            // Adds new node to the tail, if current node is the last node
            {
                current -> next = new Node;                     //current next points to the new node
                current = current -> next;                      //current moves to the new node
                current -> data = value;                        //current data equals value
                current -> next = 0;                            //current next points to the end of the list
            }
            else                                                // Adds new node after current node, if current node is in between 2 nodes
            {
                temp = new Node;                                
                temp -> next = current -> next;
                current -> next = temp;
                temp -> data = value;
                current = current -> next;
                temp = 0;
            }
        }
    }
}


bool Set::search(const int value)
{
    bool flag = false;                                          // Checks to see if value is already in the set
    Node *ptr = head;                                           // Traverses through the set
    
    while(ptr != 0)                                             // Goes through the entire set
    {
        if(ptr -> data == value)                                // Value is found
        {
            current = ptr;
            flag = true;
            break;
        }
        else                                                    // Value is not found
        {
            ptr = ptr -> next;
        }
    }
    return flag;
}


int Set::remove()
{
    Node *ptr = head;
    int num1 = -1;                                              // default is that the Set is empty
    
    if(head)                                                    // if Set is not empty
    {
        num1 = current -> data;                                 //num1 equals the value we want removed (current)
        
        if(head == current)                                     // Deletes current when it's the first node
        {
            current = head;
            head = current -> next;
            delete current;
            current = head;
        }
        else                                                    // Deletes current when it's the last node
        {
            if(current -> next == 0)
            {
                temp = current;
                current = head;
                
                for(ptr; ptr != 0 ; ptr = ptr -> next)          // Traverse through the nodes
                {
                    if(ptr -> next == temp)
                    {
                        delete temp;
                        ptr -> next = 0;
                        temp = 0;
                    }
                }
            }
            else                                                // Deletes current when it's in between 2 nodes |copies the node in front of current to current, then deletes that node
            {
                current -> data = current -> next -> data;      //changing currents data to temps data
                temp = current -> next;                         //assign temp to current -> next
                current -> next = temp -> next;                 //assign current -> next to the node after temp
                current = head;                                 //current goes away to head
                delete temp;                                    //delete temp
                temp = 0;                                       //temp = null
            }
        }
    }
    return num1;                                                //returns either -1 or the value removed.
}


ostream& operator << (ostream& outp, const Set& s)
{
    Set::Node *ptr;
    int newLine = 1;
    
    for(ptr = s.head; ptr != 0 ; ptr = ptr -> next)            //loops through the entire linked list
    {
        outp << setw(10) << left << ptr -> data;
        if(newLine == 4)                                       //if 4 values have been printed. create a new line setting newLine counter to 0
        {
            outp << "\n" << endl;
            newLine = 0;
        }
        newLine++;                                             //increments newLine
    }
    return outp;                                               //returns outp so it can be a chained instruction
}
