#pragma once

// 文字列クラス
class MyString
{
public:
	// コンストラクター
	MyString();
	MyString(const char* value);
	// デストラクター
	~MyString();
	// コピーコンストラクター
	MyString(const MyString& other);
	// 代入演算子のオーバーロード
	void operator=(const MyString& other);
	// 添え字演算子のオーバーロード
	char& operator[](unsigned int index) const;
	// 等価演算子のオーバーロード
	bool operator==(const MyString& other) const;
	// 非等価演算子のオーバーロード
	bool operator!=(const MyString& other) const;

	// 文字列の先頭アドレスの取得
	const char* c_str() const;
	// 空の文字列かどうか
	bool empty() const;
	// サイズの取得
	size_t size() const;
private:
	// リソース
	char* data = nullptr;
	// 文字列の長さ
	size_t length = 0;
};
