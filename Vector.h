#pragma once

#include "Allocator.h"
#include "VectorIterator.h"

template<typename T, class Alloc = MyAllocator<T>>
class MyVector
{
private:

	Alloc alloc = {};
	T* ptr = nullptr;
	size_t size = 0;
	size_t capacity = 0;

public:
	using iterator = VectorIterator<T>;

public:
	// �f�t�H���g�R���X�g���N�^�[
	explicit MyVector(const Alloc& alloc = Alloc())
	{
		ptr = alloc.allocate(capacity);
	}

	// �T�C�Y�Ə����l���w�肵���R���X�g���N�^�[
	explicit MyVector(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
		: size(num), capacity(num)
	{
		ptr = alloc.allocate(capacity);
	
		for (auto i = 0; i < size; i++) {
			alloc.construct(&ptr[i], value);
		}
	}

	// �����ɗv�f��ǉ�����
	void push_back(const T& value)
	{
		// �T�C�Y�ɗ]�T���Ȃ���΁A�Ċ��蓖�Ă��s��
		if (size + 1 > capacity) {
			reallocateVector(!capacity ? 1 : capacity * 2);
		}

		alloc.construct(&ptr[size++], value);
	}

	// �����̗v�f���폜����
	void pop_back()
	{
		if (size) {
			alloc.destroy(&ptr[size-- - 1]);
		}
	}

	// �擪�v�f���w���C�e���[�^�[�̎擾
	iterator begin()
	{
		return iterator(ptr);
	}

	// �����v�f���w���C�e���[�^�[�̎擾
	iterator end()
	{
		return iterator(ptr + size);
	}

	// �v�f�̕\��
	void ToString()
	{
		for (auto i = 0; i < size; ++i) {
			std::cout << ptr[i] << std::endl;
		}
	}

	// �擪�v�f�̎擾
	T& front()
	{
		// TODO : �G���[�̕\��
		return ptr[0];
	}
	
	// �����v�f�̎擾
	T& back()
	{
		// TODO : �G���[�̕\��
		return ptr[size - 1];
	}

	// �v�f�̑}��(�ʒu�Ɛ��̎w��)
	void insert(iterator position, size_t num, const T& value)
	{
		auto index = position - begin();

		if (size + num > capacity) {
			reallocateVector(capacity + num);
		}

		iterator newPosition(&ptr[index]);

	}

	// �S�Ă̗v�f�̍폜
	void clear()
	{
		while (size) {
			pop_back();
		}
	}

	// �f�X�g���N�^�[
	~MyVector()
	{
		for (iterator it = begin(); it != end(); ++it) {
			alloc.destroy(&(*it));
		}

		alloc.deallocate(ptr);
	}

private:

	// �V�����z��̊��蓖�Ă��s��
	void reallocateVector(size_t newCapacity)
	{
		// �R�s�[
		T* temp = alloc.allocate(newCapacity);
		for (auto i = 0; i < size; ++i) {
			alloc.construct(&temp[i], ptr[i]);
		}
		
		// ���݂̔z���j�����āA�V�����̂ɍX�V������
		this->~MyVector();
		capacity = newCapacity;
		ptr = temp;
	}

	// 
	void moveElementsToRight()
	{
		
	}
};