#include <iostream>
#include "List.h"
#include <list>

int main()
{
	std::list<int> test = {};
	std::list<int> test2 = {};
	test.push_back(5);
	test.push_back(6);
	test.push_back(7);
	test.push_back(8);
	test.insert(test.begin(), 3, 5);


	// 
	for (auto value : test) {
		std::cout << value << std::endl;
	}

	MyList<int> myList;
	MyList<int> myList2;
	myList.push_back(5);
	myList.push_back(7);
	myList.push_back(8);
	myList.push_back(9);

	myList2.push_back(1);
	myList2.push_back(2);
	myList2.push_back(3);
	myList2.push_back(4);

	myList = myList2;
	myList.ToString();
	
	// for (auto value : myList) {
	// 
	// }
	// myList.begin();
	return 0;
}