#pragma once

#include <memory>
#include <iostream>

template<typename T>
class smart_pointer
{
public:
	T* ptr;
	// �Q�ƃJ�E���g
	int* refCount;
};

template<typename T>
class shared_pointer
{
public:
	// �R���X�g���N�^�[
	shared_pointer() = default;
	// �����L��R���X�g���N�^�[
	explicit shared_pointer(T* ptrObj)
	{
		data = new smart_pointer<T>();
		data->ptr = ptrObj;
		data->refCount = new int(1);
	}

	// ������Z�q�̃I�[�o�[���[�h
	shared_pointer& operator=(const shared_pointer<T>& other)
	{
		// �R�s�[���鑤�̃��������m�ۂ���Ă���ꍇ
		if (other.data != nullptr) {
			// �R�s�[����鑤�̃����������m��
			if (data == nullptr) {
				data = new smart_pointer<T>();
				data->ptr = other.data->ptr;
				data->refCount = other.data->refCount;
				*(other.data->refCount) += 1;
				return *this;
			}
			else {
				*(data->refCount) -= 1;
				if (data->refCount == 0) {
					delete(data->ptr);
				}

				data->ptr = other.data->ptr;
				*(other.data->refCount) += 1;
				data->refCount = other.data->refCount;
			}
		}
		else {
			
			if (data != nullptr) {
				if (*(data->refCount) == 1) {
					remove(data);
				}
				else {
					*(data->refCount) -= 1;
				}
			}

			data = nullptr;
		}

		return *this;
	}

	// �l�C�e�B�u�|�C���^�[�̎擾
	T* get() const
	{
		return data != nullptr ? data->ptr : nullptr;
	}

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const
	{
		return *(data->ptr);
	}

	// �w�肵���|�C���^�[�̔j��
	void remove(smart_pointer<T>* toRemove)
	{
		delete(toRemove->ptr);
		delete(toRemove->refCount);
		delete(toRemove);
	}

	// ���L���̕���
	void reset()
	{
		if (data != nullptr) {
			// 1�������L���Ă���
			if (*(data->refCount == 1)) {
				remove(data);
				data = nullptr;
			}
			// ���̂Ƌ��L���Ă���
			else {
				*(data->refCount) -= 1;
				delete(data);
				data = nullptr;
			}
		}
	}

	// �V�������L����ݒ肵�āA���݂̏��L����j������
	void reset(T* resouce)
	{
		if (data != nullptr) {
			// 1�������L���Ă���
			if (*(data->refCount == 1)) {
				remove(data);
				data = nullptr;
			}
			// ���̂Ƌ��L���Ă���
			else {
				*(data->refCount) -= 1;
				delete(data);
				data = nullptr;
			}
		}

		data = new smart_pointer<T>();
		data->ptr = resouce;
		data->refCount = new int(1);
	}

	// �f�X�g���N�^�[
	~shared_pointer() {
		if (data != nullptr) {
			if (data->refCount != nullptr) {
				if (*(data->refCount) == 1) {
					delete(data->refCount);
					if (data->ptr != nullptr) {
						delete(data->ptr);
					}
				}
				else {
					*data->refCount -= 1;
				}
			}
			delete(data);
		}
	}
private:
	smart_pointer<T>* data = nullptr;
};
