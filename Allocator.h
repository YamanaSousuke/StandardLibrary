#pragma once

// メモリの確保と破棄
template<class T>
class MyAllocator
{
public:
	MyAllocator() { }

	// ストレージの確保
	T* allocate(size_t num)
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

	void construct(T* p, const T& value)
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
