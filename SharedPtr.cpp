#include "SharedPointer.h"

// デフォルトコンストラクター
template<typename T>
MySharedPtr<T>::MySharedPtr() : data(nullptr)
{

}

// コンストラクター
template<typename T>
MySharedPtr<T>::MySharedPtr(T* data) : data(data)
{
	count = new int(1);
}

// コピーコンストラクター
template<typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr& other)
{
	if (other.data != nullptr) {
		data = new T();
		data = other.data;
		count = other.count;
		*count += 1;
	}
}

// デストラクター
template<typename T>
MySharedPtr<T>::~MySharedPtr()
{
	if (count != nullptr) {
		// 最後の所有権
		if (*count == 1) {
			delete count;
			if (data != nullptr) {
				delete data;
			}
		}
		// 参照カウントを下げる
		else {
			*count -= 1;
		}
	}
}

// 代入演算子のオーバーロード
template<typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr& other)
{
	// コピーする側の所有権がある
	if (other.data != nullptr) {
		// コピーされる側の所有権がない
		if (data == nullptr) {
			data = new T();
			data = other.data;
			count = other.count;
			*count += 1;
			return *this;
		}
		// コピーされる側の所有権がある
		else {
			*count -= 1;
			// コピーされる側の所有権が最後の場合は参照カウントの破棄
			if (*count == 0) {
				delete count;
			}

			// リソースへのポインターを張り替える
			data = other.data;
			count = other.count;
			*count += 1;
		}
	}

	return *this;
}

// 間接演算子のオーバーロード
template<typename T>
T& MySharedPtr<T>::operator*() const
{
	return *data;
}

// アロー演算子のオーバーロード
template<typename T>
T* MySharedPtr<T>::operator->() const
{
	return data;
}

// ポインターの取得
template<typename T>
T* MySharedPtr<T>::get() const
{
	return data;
}

// 参照カウントの取得
template<typename T>
int MySharedPtr<T>::use_count() const
{
	return 0;
}

// 所有権の破棄
template<typename T>
void MySharedPtr<T>::reset()
{
	if (count != nullptr) {
		// 最後の一つなので破棄する
		if (*count == 1) {
			delete count;
			count = nullptr;
			delete data;
			data = nullptr;
		}
		// まだ残っているので、参照カウントを減らす
		else {
			*count -= 1;
		}
	}
}

// 所有権を放棄し、新たなリソースの所有権を設定する
template<typename T>
void MySharedPtr<T>::reset(T* newData)
{
	if (count != nullptr) {
		// 最後の一つなので破棄する
		if (*count == 1) {
			delete count;
			count = nullptr;
			delete data;
			data = nullptr;
		}
		// まだ残っているので、参照カウントを減らす
		else {
			*count -= 1;
		}
	}

	data = newData;
	count = new int(1);
}
