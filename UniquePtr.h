#pragma once

// 指定されたリソースへのポインタの所有権を唯一持っているように振舞うスマートポインタ
template<typename T>
class MyUniquePtr
{
public:
	// デフォルトコンストラクター
	MyUniquePtr() : data(nullptr) { }
	// コンストラクター
	MyUniquePtr(T* data) : data(data) { }
	// コピー禁止
	MyUniquePtr(const MyUniquePtr&) = delete;
	// デストラクター
	~MyUniquePtr()
	{
		delete data;
	}
	
	// ネイティブポインターの取得
	T* get() const
	{
		return data;
	}


private:
	T* data;
};
