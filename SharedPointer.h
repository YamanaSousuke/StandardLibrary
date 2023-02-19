#pragma once

#include <memory>

// 参照カウント
class ReferenceCount
{
public:
	// カウントの増加
	void AddRef()
	{
		++count;
	}

	// カウントの減少
	int Release()
	{
		return --count;
	}

	// カウントの取得
	int GetCount()
	{
		return count;
	}

private:
	int count = 0;

	std::shared_ptr<int> test = {};
};