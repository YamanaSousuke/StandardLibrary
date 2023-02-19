#include <iostream>
#include "List.h"
#include "SharedPointer.h"
#include <list>
#include <memory>

int main()
{
	/*std::shared_ptr<int> ptr;
	{
		std::shared_ptr<int> ptr2(new int());

		ptr = ptr2;

		*ptr += 10;
		*ptr2 += 10;
	}
	std::cout << *ptr << std::endl;*/


	shared_pointer<int> ptr;
	{
		shared_pointer<int> ptr2(new int());

		ptr = ptr2;
		// 
		*ptr += 10;
		*ptr2 += 10;
	}
	std::cout << *ptr << std::endl;
	return 0;
}