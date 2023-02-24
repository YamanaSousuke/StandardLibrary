#pragma once

// MyVectorに使用するイテレーター
template<typename T>
class VectorIterator
{
public:
	// デフォルトコンストラクター
	VectorIterator(T* ptr = nullptr) : ptr(ptr) { }

	// 前置演算子のオーバーロード
	VectorIterator& operator++()
	{
		++ptr;
		return *this;
	}

	// 間接演算子のオーバーロード
	T& operator*() const
	{
		return *ptr;
	}

	// アロー演算子のオーバーロード
	T* operator->() const
	{
		return ptr;
	}

	// 等価演算子のオーバーロード
	bool operator==(const VectorIterator& other) const
	{
		return ptr == other.ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}
private:
	// 配列の要素を指すポインター
	T* ptr = nullptr;
};
