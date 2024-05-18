#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "queue.h"

using namespace std;

// CONSTRUCTOR
Queue::Queue()
{
    // Initializes everything to 0
    front = 0;
    back = 0;
    count = 0;
}

// DESTRUCTOR
Queue::~Queue()                     //referenced page 1152/1184 in Starting Out with C++ from Control Structures through Objects by Tony Gaddis
{
    Node *ptr1 = front;             //traverses the queue
    Node *ptr2;                     //traverses the queue

    while (ptr1 != 0) {             //deletes nodes until the queue is empty
        ptr2 = ptr1 -> next;
        delete ptr1;
        ptr1 = ptr2;
    }
}

void Queue::enqueue(int value)
{
    Node *temp = 0;
    temp = new Node;
    temp -> data = value;
    temp -> next = 0;
    
    if(count == 0) {                //queue is empty
        front = temp;
        back = temp;
    }
    else {                          //queue is not empty
        back -> next = temp;
        back = temp;
    }
    count++;
}

int Queue::dequeue()
{
    int num = -1;                   //queue is empty
    Node *temp = 0;
    
    if(count != 0) {                //queue is not empty
        num = front -> data;
        temp = front;
        front = front -> next;
        delete temp;
        count--;
    }
    return num;
}

const int Queue::queuefront()
{
    int num = -1;                   //queue is empty
    
    if(count != 0)                  //queue is not empty
        num = front -> data;
        
    return num;
}

const int Queue::queueback()
{
    int num = -1;                   //queue is empty
    
    if(count != 0)                  //queue is not empty
        num = back -> data;
        
    return num;
}
