#pragma once

#include <iostream>

template<typename T>
class MySharedPointer
{
public:
	// コンストラクター
	MySharedPointer() { }

	// 引数有りコンストラクター
	explicit MySharedPointer(T* data)
	{
		this->data = data;
		count = new int(1);
	}

	// コピーコンストラクター
	MySharedPointer(const MySharedPointer& other)
	{
		if (other.data != nullptr) {
			data = new T();
			data = other.data;
			count = other.count;
			*count += 1;
		}
	}

	// デストラクター
	~MySharedPointer()
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
	MySharedPointer& operator=(const MySharedPointer& other)
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
	T& operator*() const
	{
		return *data;
	}

	// アドレス演算子のオーバーロード
	T* operator->() const
	{
		return data;
	}

	// ネイティブポインターの取得
	T* get() const
	{
		return data;
	}

	// 参照カウントの取得
	int use_count() const
	{
		return *count;
	}

	// 所有権の破棄
	void reset()
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
	void reset(T* newData)
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
private:
	// リソース
	T* data = nullptr;
	// 参照カウント
	int* count = nullptr;
};
