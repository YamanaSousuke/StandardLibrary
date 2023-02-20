#pragma once

// 指定されたリソースへのポインタの所有権を唯一持っているように振舞うスマートポインタ
template<typename T>
class MyUniquePtr
{
public:
	// デフォルトコンストラクター
	MyUniquePtr();
	// コンストラクター
	MyUniquePtr(T* data);
	// コピー禁止
	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;
	// ムーブコンストラクター
	MyUniquePtr(MyUniquePtr&& other) noexcept;
	// ムーブ代入演算子
	MyUniquePtr& operator=(MyUniquePtr&& other) noexcept;
	// デストラクター
	~MyUniquePtr();

	// 間接演算子のオーバーロード
	T& operator*() const;
	// アロー演算子のオーバーロード
	T* operator->() const;
	// ポインタを管理しているかを確認する
	operator bool() const;
	// ポインターの取得
	T* get() const;
	// リソースの解放
	void reset();
	// リソースの開放と新しいリソースの設定
	void reset(T* newData);
	// リソースを管理下から離す
	T* release();
private:
	// リソース
	T* data;
};
