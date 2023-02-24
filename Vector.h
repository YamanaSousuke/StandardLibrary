#pragma once

#include "Allocator.h"

template<typename T, class Alloc = MyAllocator<T>>
class MyVector
{
private:

	Alloc alloc = {};
	T* ptr = nullptr;
	size_t size = 0;
	size_t capacity = 0;
public:
	// �f�t�H���g�R���X�g���N�^�[
	explicit MyVector(const Alloc& alloc = Alloc())
	{
		ptr = alloc.allocate(capacity);
	}

	explicit MyVector(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
		: size(num), capacity(num)
	{
		ptr = alloc.allocate(capacity);
	
		for (auto i = 0; i < size; i++) {
			alloc.construct(&ptr[i], value);
		}
	}

private:


};