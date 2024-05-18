// CLASS PROVIDED:  Set
//
// CONSTRUCTOR for the Set class:
//   Set()
//     Description:      constructor will initialize Set objects
//     Preconditions:    none
//     Postcondition:    the set is empty
//
// DESTRUCTOR for the Set class:
//   ~Set()
//     Description:     deletes every node in the list until the set is empty
//     Preconditions:   none
//     Postcondition:   the set is empty
//
// MODIFICATION MEMBER FUNCTIONS for the Set class
//   void insert (const int value)
//     Description:      insert an integer into the set after the current node
//     Precondition:     value must be an integer and can't be a duplicate of an integer already in the set
//     Postcondition:    current node is replaced with the inserted value if value isn't in set, otherwise current node stays the same
//
//  bool search (const int value)
//     Description:      search for an integer in the set
//     Precondition:     value must be an integer
//     Postcondition:    returns true if value is found and the node becomes the current node, returns false if value is not found and current node doesn't change
//
//  int remove()
//     Description:     removes the current node from the set
//     Precondition:    none
//     Postcondition:   value is no longer in the set and the current node is the head node
//
//  friend ostream& operator << (ostream&, const Set&)
//     Description:     overload the output operator
//     Precondition:    none
//     Postcondition:   allows a set to be outputted to the screen with the values lined up in columns, 4 on each line


#include <iostream>

using namespace std;

#ifndef SET_H
#define SET_H

class Set
{
    public:
        Set();      // CONSTRUCTOR
        ~Set();     // DESTRUCTOR
    
        // MODIFICATION MEMBER FUNCTIONS
        void insert(const int);
        bool search(const int);
        int remove();
    
        friend ostream& operator << (ostream&, const Set&);
   
    private:
        struct Node
        {
            int data;       // Piece of data
            Node* next;     // Pointer to the location of the next node
        };
    
        Node* head;         // First node in the set
        Node* current;      // Current node in the set
        Node* temp;         // Temporary node is created in the set
};

#endif
