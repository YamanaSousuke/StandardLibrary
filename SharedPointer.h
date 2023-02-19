#pragma once

#include <memory>

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
