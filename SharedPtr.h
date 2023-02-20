#pragma once

#include <iostream>

template<typename T>
class MySharedPointer
{
public:
	// デフォルトコンストラクター
	MySharedPointer();
	// コンストラクター
	explicit MySharedPointer(T* data);
	// コピーコンストラクター
	MySharedPointer(const MySharedPointer& other);
	// デストラクター
	~MySharedPointer();

	// 代入演算子のオーバーロード
	MySharedPointer& operator=(const MySharedPointer& other);
	// 間接演算子のオーバーロード
	T& operator*() const;
	// アロー演算子のオーバーロード
	T* operator->() const;

	// ポインターの取得
	T* get() const;
	// 参照カウントの取得
	int use_count() const;
	// 所有権の破棄
	void reset();
	// 所有権を放棄し、新たなリソースの所有権を設定する
	void reset(T* newData);
private:
	// リソース
	T* data = nullptr;
	// 参照カウント
	int* count = nullptr;
};
