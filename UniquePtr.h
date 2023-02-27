#pragma once

// 指定されたリソースへのポインタの所有権を唯一持っているように振舞うスマートポインタ
template<typename T>
class MyUniquePtr
{
public:
	// デフォルトコンストラクター
	MyUniquePtr() { }
	// コンストラクター
	explicit MyUniquePtr(T* data) { }
	// コピー禁止
	MyUniquePtr(const MyUniquePtr&) = delete;
	// ムーブコンストラクター
	MyUniquePtr(MyUniquePtr&& other) noexcept
	{
		data = other.data;
		other.data = nullptr;
	}

	// デストラクター
	~MyUniquePtr()
	{
		if (data != nullptr) {
			delete data;
		}
	}

	// コピー禁止
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;
	// ムーブ代入演算子
	MyUniquePtr& operator=(MyUniquePtr&& other) noexcept
	{
		if (this == &other) {
			return *this;
		}

		data = other.data;
		other.data = nullptr;
		return *this;
	}

	// 間接演算子のオーバーロード
	T& operator*() const
	{
		return *data;
	}

	// アロー演算子のオーバーロード
	T* operator->() const
	{
		return data;
	}

	// ポインタを管理しているかを確認する
	operator bool() const
	{
		return data ? true : false;
	}

	// ポインターの取得
	T* get() const
	{
		return data;
	}

	// リソースの解放
	void reset()
	{
		delete data;
		data = nullptr;
	}

	// リソースの開放と新しいリソースの設定
	void reset(T* newData)
	{
		delete data;
		data = newData;
	}

	// リソースを管理下から離す
	T* release()
	{
		T* temp(data);
		data = nullptr;
		return temp;
	}
private:
	// リソース
	T* data;
};
