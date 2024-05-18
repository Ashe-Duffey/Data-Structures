#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class Item>
class List
{
  public:
    List();
    void insert(const Item& entry);
    void print() const;
    bool search(Item search, Item loc);
    int finditem(Item search);
  private:
    Item array[50];
    int count;
};

#include "List.cpp"

#endif
