#pragma once

#include "Allocator.h"
#include "VectorIterator.h"

template<typename T, class Alloc = MyAllocator<T>>
class MyVector
{
private:

	Alloc alloc = {};
	T* ptr = nullptr;
	size_t size = 0;
	size_t capacity = 0;

public:
	using iterator = VectorIterator<T>;

public:
	// デフォルトコンストラクター
	explicit MyVector(const Alloc& alloc = Alloc())
	{
		ptr = alloc.allocate(capacity);
	}

	// サイズと初期値を指定したコンストラクター
	explicit MyVector(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
		: size(num), capacity(num)
	{
		ptr = alloc.allocate(capacity);
	
		for (auto i = 0; i < size; i++) {
			alloc.construct(&ptr[i], value);
		}
	}

	// 先頭要素を指すイテレーターの取得
	iterator begin()
	{
		return iterator(ptr);
	}

	// 末尾要素を指すイテレーターの取得
	iterator end()
	{
		return iterator(ptr + size);
	}

	// 要素の表示
	void ToString()
	{
		for (auto i = 0; i < size; ++i) {
			std::cout << ptr[i] << std::endl;
		}
	}

	// デストラクター
	~MyVector()
	{
		for (iterator it = begin(); it != end(); ++it) {
			alloc.destroy(&(*it));
		}

		alloc.deallocate(ptr);
	}

private:

	// void reallocateVector(size_t newCapacity)
	// {
	// 	T* temp = alloc.allocate(newCapacity);
	// 
	// 	for (auto i = 0; i < size; ++i) {
	// 		alloc.construct(&temp[i], ptr[i]);
	// 	}
	// 
	// 	// this->
	// }
};