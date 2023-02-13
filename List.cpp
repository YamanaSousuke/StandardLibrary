#include <iostream>
#include "List.h"
#include <list>

int main()
{
	// std::list<int> test = {};
	// test.push_back(5);
	// test.push_back(6);
	// test.push_back(7);
	// test.push_back(8);
	// test.erase(test.begin());
	// 
	// for (auto value : test) {
	// 	std::cout << value << std::endl;
	// }

	MyList<int> myList;
	myList.push_back(5);
	myList.push_back(6);
	myList.push_back(7);
	myList.push_back(8);
	myList.erase(myList.begin());
	myList.ToString();
	
	// for (auto value : myList) {
	// 
	// }
	// myList.begin();
	return 0;
}