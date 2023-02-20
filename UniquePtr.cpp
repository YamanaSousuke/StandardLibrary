#include "UniquePtr.h"

// デフォルトコンストラクター
template<typename T>
MyUniquePtr<T>::MyUniquePtr() : data(nullptr)
{

}

// コンストラクター
template<typename T>
MyUniquePtr<T>::MyUniquePtr(T* data) : data(data)
{

}

// ムーブコンストラクター
template<typename T>
MyUniquePtr<T>::MyUniquePtr(MyUniquePtr&& other) noexcept
{
	data = other.data;
	other.data = nullptr;
}

// ムーブ代入演算子
template<typename T>
MyUniquePtr<T>& MyUniquePtr<T>::operator=(MyUniquePtr&& other) noexcept
{
	if (this == &other) {
		return *this;
	}

	data = other.data;
	other.data = nullptr;
	return *this;
}

// デストラクター
template<typename T>
MyUniquePtr<T>::~MyUniquePtr()
{
	if (data != nullptr) {
		delete data;
	}
}

// 間接演算子のオーバーロード
template<typename T>
T& MyUniquePtr<T>::operator*() const
{
	return *data;
}

// アロー演算子のオーバーロード
template<typename T>
T* MyUniquePtr<T>::operator->() const
{
	return data;
}

// ポインタを管理しているかを確認する
template<typename T>
MyUniquePtr<T>::operator bool() const
{
	return data ? true : false;
}

// ポインターの取得
template<typename T>
T* MyUniquePtr<T>::get() const
{
	return data;
}

// リソースの解放
template<typename T>
void MyUniquePtr<T>::reset()
{
	delete data;
	data = nullptr;
}

// リソースの開放と新しいリソースの設定
template<typename T>
void MyUniquePtr<T>::reset(T* newData)
{
	delete data;
	data = newData;
}

// リソースを管理下から離す
template<typename T>
T* MyUniquePtr<T>::release()
{
	T* temp(data);
	data = nullptr;
	return temp;
}