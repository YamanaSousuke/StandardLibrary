#pragma once

#include <iostream>

template<typename T>
class MySharedPointer
{
public:
	// �R���X�g���N�^�[
	MySharedPointer() { }

	// �����L��R���X�g���N�^�[
	explicit MySharedPointer(T* data)
	{
		this->data = data;
		count = new int(1);
	}

	// �R�s�[�R���X�g���N�^�[
	MySharedPointer(const MySharedPointer& other)
	{
		if (other.data != nullptr) {
			data = new T();
			data = other.data;
			count = other.count;
			*count += 1;
		}
	}

	// �f�X�g���N�^�[
	~MySharedPointer()
	{
		if (count != nullptr) {
			// �Ō�̏��L��
			if (*count == 1) {
				delete count;
				if (data != nullptr) {
					delete data;
				}
			}
			// �Q�ƃJ�E���g��������
			else {
				*count -= 1;
			}
		}
	}

	// ������Z�q�̃I�[�o�[���[�h
	MySharedPointer& operator=(const MySharedPointer& other)
	{
		// �R�s�[���鑤�̏��L��������
		if (other.data != nullptr) {
			// �R�s�[����鑤�̏��L�����Ȃ�
			if (data == nullptr) {
				data = new T();
				data = other.data;
				count = other.count;
				*count += 1;
				return *this;
			}
			// �R�s�[����鑤�̏��L��������
			else {
				*count -= 1;
				// �R�s�[����鑤�̏��L�����Ō�̏ꍇ�͎Q�ƃJ�E���g�̔j��
				if (*count == 0) {
					delete count;
				}

				// ���\�[�X�ւ̃|�C���^�[�𒣂�ւ���
				data = other.data;
				count = other.count;
				*count += 1;
			}
		}

		return *this;
	}

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const
	{
		return *data;
	}

	// �A�h���X���Z�q�̃I�[�o�[���[�h
	T* operator->() const
	{
		return data;
	}

	// �l�C�e�B�u�|�C���^�[�̎擾
	T* get() const
	{
		return data;
	}

	// �Q�ƃJ�E���g�̎擾
	int use_count() const
	{
		return *count;
	}

	// ���L���̔j��
	void reset()
	{
		if (count != nullptr) {
			// �Ō�̈�Ȃ̂Ŕj������
			if (*count == 1) {
				delete count;
				count = nullptr;
				delete data;
				data = nullptr;
			}
			// �܂��c���Ă���̂ŁA�Q�ƃJ�E���g�����炷
			else {
				*count -= 1;
			}
		}
	}

	// ���L����������A�V���ȃ��\�[�X�̏��L����ݒ肷��
	void reset(T* newData)
	{
		if (count != nullptr) {
			// �Ō�̈�Ȃ̂Ŕj������
			if (*count == 1) {
				delete count;
				count = nullptr;
				delete data;
				data = nullptr;
			}
			// �܂��c���Ă���̂ŁA�Q�ƃJ�E���g�����炷
			else {
				*count -= 1;
			}
		}

		data = newData;
		count = new int(1);
	}
private:
	// ���\�[�X
	T* data = nullptr;
	// �Q�ƃJ�E���g
	int* count = nullptr;
};
