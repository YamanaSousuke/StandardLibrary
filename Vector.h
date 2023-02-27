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

	// 末尾に要素を追加する
	void push_back(const T& value)
	{
		// サイズに余裕がなければ、再割り当てを行う
		if (size + 1 > capacity) {
			reallocateVector(!capacity ? 1 : capacity * 2);
		}

		alloc.construct(&ptr[size++], value);
	}

	// 末尾の要素を削除する
	void pop_back()
	{
		if (size) {
			alloc.destroy(&ptr[size-- - 1]);
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

	// 先頭要素の取得
	T& front()
	{
		// TODO : エラーの表示
		return ptr[0];
	}
	
	// 末尾要素の取得
	T& back()
	{
		// TODO : エラーの表示
		return ptr[size - 1];
	}

	// 要素の挿入(位置と数の指定)
	void insert(iterator position, size_t num, const T& value)
	{
		auto index = position - begin();

		if (size + num > capacity) {
			reallocateVector(capacity + num);
		}

		iterator newPosition(&ptr[index]);

	}

	// 全ての要素の削除
	void clear()
	{
		while (size) {
			pop_back();
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

	// 新しく配列の割り当てを行う
	void reallocateVector(size_t newCapacity)
	{
		// コピー
		T* temp = alloc.allocate(newCapacity);
		for (auto i = 0; i < size; ++i) {
			alloc.construct(&temp[i], ptr[i]);
		}
		
		// 現在の配列を破棄して、新しいのに更新をする
		this->~MyVector();
		capacity = newCapacity;
		ptr = temp;
	}

	// 
	void moveElementsToRight()
	{
		
	}
};