#pragma once

#include <memory>

template<typename T>
class smart_pointer
{
public:
	T* ptr;
	// 参照カウント
	int* refCount;
};



template<typename T>
class shared_pointer
{
public:
	// コンストラクター
	shared_pointer() = default;

	// デストラクター
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
