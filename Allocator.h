#pragma once

#include <exception>
#include <iostream>

// メモリの確保と破棄
template<class T>
class MyAllocator
{
public:
	// デフォルトコンストラクター
	MyAllocator() { }

	// ストレージの確保
	T* allocate(size_t num) const
	{
		T* ret = nullptr;
		const size_t size = num * sizeof(T);

		try {
			ret = new T[size];
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		return ret;
	}

	void construct(T* p, const T& value) const
	{
		*p = value;
	}

	// 領域の解放
	void deallocate(T* p)
	{
		delete p;
	}

	// 割り当てられたストレージ内のオブジェクトの破棄
	void destroy(T* p)
	{
		p->~T();
	}
};
