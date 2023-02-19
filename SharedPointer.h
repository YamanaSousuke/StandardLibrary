#pragma once

#include <memory>
#include <iostream>

template<typename T>
class smart_pointer
{
public:
	T* ptr;
	// 参照カウント
	int* refCount;
};

template<typename T>
class shared_pointer
{
public:
	// コンストラクター
	shared_pointer() = default;
	// 引数有りコンストラクター
	explicit shared_pointer(T* ptrObj)
	{
		data = new smart_pointer<T>();
		data->ptr = ptrObj;
		data->refCount = new int(1);
	}

	// 代入演算子のオーバーロード
	shared_pointer& operator=(const shared_pointer<T>& other)
	{
		// コピーする側のメモリが確保されている場合
		if (other.data != nullptr) {
			// コピーされる側のメモリが未確保
			if (data == nullptr) {
				data = new smart_pointer<T>();
				data->ptr = other.data->ptr;
				data->refCount = other.data->refCount;
				*(other.data->refCount) += 1;
				return *this;
			}
			else {
				*(data->refCount) -= 1;
				if (data->refCount == 0) {
					delete(data->ptr);
				}

				data->ptr = other.data->ptr;
				*(other.data->refCount) += 1;
				data->refCount = other.data->refCount;
			}
		}
		else {
			
			if (data != nullptr) {
				if (*(data->refCount) == 1) {
					remove(data);
				}
				else {
					*(data->refCount) -= 1;
				}
			}

			data = nullptr;
		}

		return *this;
	}

	// ネイティブポインターの取得
	T* get() const
	{
		return data != nullptr ? data->ptr : nullptr;
	}

	// 間接演算子のオーバーロード
	T& operator*() const
	{
		return *(data->ptr);
	}

	// 指定したポインターの破棄
	void remove(smart_pointer<T>* toRemove)
	{
		delete(toRemove->ptr);
		delete(toRemove->refCount);
		delete(toRemove);
	}

	// 所有権の放棄
	void reset()
	{
		if (data != nullptr) {
			// 1つだけ所有している
			if (*(data->refCount == 1)) {
				remove(data);
				data = nullptr;
			}
			// 他のと共有している
			else {
				*(data->refCount) -= 1;
				delete(data);
				data = nullptr;
			}
		}
	}

	// 新しい所有権を設定して、現在の所有権を破棄する
	void reset(T* resouce)
	{
		if (data != nullptr) {
			// 1つだけ所有している
			if (*(data->refCount == 1)) {
				remove(data);
				data = nullptr;
			}
			// 他のと共有している
			else {
				*(data->refCount) -= 1;
				delete(data);
				data = nullptr;
			}
		}

		data = new smart_pointer<T>();
		data->ptr = resouce;
		data->refCount = new int(1);
	}

	// デストラクター
	~shared_pointer() {
		if (data != nullptr) {
			if (data->refCount != nullptr) {
				if (*(data->refCount) == 1) {
					delete(data->refCount);
					if (data->ptr != nullptr) {
						delete(data->ptr);
					}
				}
				else {
					*data->refCount -= 1;
				}
			}
			delete(data);
		}
	}
private:
	smart_pointer<T>* data = nullptr;
};
