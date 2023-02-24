#pragma once

// MyVectorに使用するイテレーター
template<typename T>
class VectorIterator
{
public:
	// デフォルトコンストラクター
	VectorIterator(T* ptr = nullptr); /* : ptr(ptr) { }*/
private:
	// 配列の要素を指すポインター
	T* ptr = nullptr;
};
