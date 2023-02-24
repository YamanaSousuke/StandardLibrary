#pragma once

// MyVector�Ɏg�p����C�e���[�^�[
template<typename T>
class VectorIterator
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	VectorIterator(T* ptr = nullptr) : ptr(ptr) { }

	// �O�u���Z�q�̃I�[�o�[���[�h
	VectorIterator& operator++()
	{
		++ptr;
		return *this;
	}

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const
	{
		return *ptr;
	}

	// �A���[���Z�q�̃I�[�o�[���[�h
	T* operator->() const
	{
		return ptr;
	}

	// �������Z�q�̃I�[�o�[���[�h
	bool operator==(const VectorIterator& other) const
	{
		return ptr == other.ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}
private:
	// �z��̗v�f���w���|�C���^�[
	T* ptr = nullptr;
};
