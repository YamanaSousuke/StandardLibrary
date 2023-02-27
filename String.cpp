#include "String.h"

// コンストラクター
MyString::MyString()
{
	data = new char[length + 1];
	data[0] = '\0';
}

// 文字列を指定したコンストラクター
MyString::MyString(const char* value)
{
	while (value[length] != '\0') {
		length++;
	}

	// メモリを確保して、1文字ずつコピーする
	data = new char[length + 1];
	for (size_t index = 0; index < length + 1; index++) {
		data[index] = value[index];
	}
}

// デストラクター
MyString::~MyString()
{
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
}

// コピーコンストラクター
MyString::MyString(const MyString& other)
{
	// コピー先に既にデータがある場合は破棄する
	if (data != nullptr) {
		delete[] data;
	}

	// コピー
	length = other.length;
	data = new char[length + 1];
	for (size_t index = 0; index < length + 1; index++) {
		data[index] = other.data[index];
	}
}

// 代入演算子のオーバーロード
void MyString::operator=(const MyString& other)
{
	// コピー先に既にデータがある場合は破棄する
	if (data != nullptr) {
		delete[] data;
	}
	
	// コピー
	length = other.length;
	data = new char[length + 1];
	for (size_t index = 0; index < length + 1; index++) {
		data[index] = other.data[index];
	}
}

// 添え字演算子のオーバーロード
char& MyString::operator[](unsigned int index) const
{
	return index >= length ? data[length - 1] : data[index];
}

// 等価演算子のオーバーロード
bool MyString::operator==(const MyString& other) const
{
	if (length != other.length) {
		return false;
	}

	int index = 0;
	while ((data[index] - other.data[index]) == 0 && data[index] != '\0') {
		index++;
	}
	return index == length;
}

// 非等価演算子のオーバーロード
bool MyString::operator!=(const MyString& other) const
{
	return !(*this == other);
}

// 文字列の先頭アドレスの取得
const char* MyString::c_str() const
{
	return data;
}

// 空の文字列かどうか
bool MyString::empty() const
{
	return length == 0;
}

// サイズの取得
size_t MyString::size() const
{
	return length;
}
