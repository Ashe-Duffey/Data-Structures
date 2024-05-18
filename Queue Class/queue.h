// CLASS PROVIDED:  Queue
//
// CONSTRUCTOR for the Queue class: Queue
//   Queue()
//      Description:      constructor will initialize front, back, and count to zero
//      Preconditions:    none
//      Postcondition:    queue is empty
//
// DESTRUCTOR for the Queue class: Queue
//   ~Queue()
//      Description:      destructor loops and deletes every node in the queue
//      Preconditions:    none
//      Postcondition:    queue is empty
//
// MODIFICATION MEMBER FUNCTIONS for the Queue class
//   void enqueue(int value)
//      Description:     inserts a value to the back of the queue
//      Precondition:    value must be an integer
//      Postcondition:   new node is created and inserted to the back of the queue, back points to new node
//
//   int dequeue()
//      Description:      removes value from the front of the queue
//      Preconditions:    none
//      Postcondition:    value is no longer in the queue and front node is now the node after the value removed, returns value removed or -1 if queue is empty
//
// CONSTANT MEMBER FUNCTIONS for the Queue class
//   const int queuefront()
//      Description:      retrieves value at the front of the queue
//      Preconditions:    none
//      Postcondition:    returns the front value in the queue or -1 if queue is empty
//
//   const int queueback()
//      Description:      retrieves value at the back of the queue
//      Preconditions:    none
//      Postcondition:    returns the back value in the queue or -1 if queue is empty

#ifndef queue_h
#define queue_h
#include <iostream>

using namespace std;

class Queue
{
    public:
        //CONSTRUCTOR
        Queue();
        
        //DESTRUCTOR
        ~Queue();
    
        //MODIFICATION MEMBER FUNCTIONS
        void enqueue(int);
        int dequeue();
    
        //CONSTANT MEMBER FUNCTIONS
        const int queuefront();
        const int queueback();
    
    private:
        struct Node
        {
            int data;
            Node *next;
        };
    
        Node *front;         //front node in queue
        Node *back;          //back node in queue
    
        int count;           //number of items in the queue
    
};

#endif
