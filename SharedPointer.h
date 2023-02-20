#pragma once

template<typename T>
class MySharedPointer
{
public:
	// コンストラクター
	MySharedPointer()
	{
		count = new int(-1);
	}

	// 引数有りコンストラクター
	explicit MySharedPointer(T* data)
	{
		count = new int(1);
		this->data = data;
	}

	// デストラクター
	~MySharedPointer()
	{
		// 最後の一つなので破棄する
		if (use_count() == 1) {
			delete count;
			delete data;
		}
		// 参照カウントだけ破棄する
		else if (use_count() == -1) {
			delete count;
		}
		// まだ残っているので、参照カウントを減らす
		else {
			set_count(use_count() - 1);
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
	int use_count()
	{
		return *count;
	}

	// 所有権の破棄
	void reset()
	{
		if (data != nullptr) {
			// 最後の一つなので破棄する
			if (*count == 1) {
				delete count;
				delete data;
			}
			// まだ残っているので、参照カウントを減らす
			else {
				*count -= 1;
				delete data;
			}
		}
	}

	// 参照カウントの設定
	void set_count(int count)
	{
		*(this->count) = count;
	}
private:
	// リソース
	T* data = nullptr;
	// 参照カウント
	int* count = nullptr;
};
