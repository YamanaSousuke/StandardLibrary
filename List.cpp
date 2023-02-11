#include <iostream>
#include "List.h"
#include <list>

int main()
{
	// std::list<int> test = {};

	MyList<int> myList(5, 5);
	myList.ToString();
	return 0;
}