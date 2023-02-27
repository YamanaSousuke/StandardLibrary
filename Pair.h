#pragma once

template<typename T1, typename T2>
class MyPair
{
public:
	// デフォルトコンストラクター
	MyPair() : first(), second() { }
	// コンストラクター
	MyPair(const T1& first, const T1& second) : first(first), second(second) { }

	// デストラクター
	~MyPair() { }
private:
	T1 first;
	T2 second;
};
