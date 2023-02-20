#include <iostream>
#include "List.h"
#include "SharedPointer.h"
#include <list>
#include <memory>

int main()
{
	MySharedPointer<int> test1;

	// std::shared_ptr<int> sint;
	// std::shared_ptr<float> sfloat;
	// 
	// sint = sfloat;

	
	{
		MySharedPointer<int> test2(new int(0));
		test1 = test2;
	
		*test2 += 10;
		*test1 += 10;
	}

	std::cout << "before : " << test1.get() << std::endl;
	test1.reset(new int(30));
	std::cout << "after  : " << test1.get() << std::endl;

	// std::cout << *test1 << std::endl;
	return 0;
}