// #include <iostream>
// #include "List.h"
#include "SharedPointer.h"
#include "UniquePtr.h"
// #include <list>
// #include <memory>

int main()
{
	MyUniquePtr<int> test2(new int(1));
	MyUniquePtr<int> test;
	// *test = 10;
	test = std::move(test2);
	std::cout << "test value  : " << *test << std::endl;

	return 0;
}