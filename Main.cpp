#include "String.h"
#include "UniquePtr.h"
#include "SharedPtr.h"
#include "List.h"
#include "Vector.h"

int main()
{
	MyString myString;

	MyUniquePtr<int> myUniquePtr;

	MySharedPtr<int> mySharedPtr;

	MyList<int> myList;

	MyVector<int> myVector;

	return 0;
}
