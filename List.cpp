#include <iostream>
#include "List.h"
#include "SharedPointer.h"
#include <list>
#include <memory>

int main()
{
	MySharedPointer<int> test1;

	// MySharedPointer<int> test0(new int(1));
	// MySharedPointer<int> test00(new int(1));

	{
		MySharedPointer<int> test2(new int(0));
		test1 = test2;

		*test2 += 10;
		*test1 += 10;
	}

	std::cout << *test1 << std::endl;
	return 0;
}