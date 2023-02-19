#pragma once

#include <memory>

// �Q�ƃJ�E���g
class ReferenceCount
{
public:
	// �J�E���g�̑���
	void AddRef()
	{
		++count;
	}

	// �J�E���g�̌���
	int Release()
	{
		return --count;
	}

	// �J�E���g�̎擾
	int GetCount()
	{
		return count;
	}

private:
	int count = 0;

	std::shared_ptr<int> test = {};
};