#include "List.h"

template <class Item>
List<Item>::List()
{
  count = 0;
  
  for(int i = 0; i < 50; i++)
    array[i] = 0;
}

template <class Item>
void List<Item>::insert(const Item& entry)
{
  if(count < 50)
  {
    array[count] = entry;
    count++;
  }
}

template <class Item>
void List<Item>::print() const
{
  for(int i = 0; i < count; i++)
    cout << array[i] << endl;
}

template <class Item>
bool List<Item>::search(Item search, Item loc)
{
	if(search == array[loc])
		return true;
	else
		return false;
}

template <class Item>
int List<Item>::finditem(Item target)
{
	for(int i = 0; i < 50; i++)
	{
		if(search(target, i) == true)
		{
			return i;
		}
	}
	return -1;
}
