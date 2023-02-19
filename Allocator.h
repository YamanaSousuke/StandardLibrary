#pragma once

// �������̊m�ۂƔj��
template<class T>
class MyAllocator
{
public:
	MyAllocator() { }

	// �X�g���[�W�̊m��
	T* allocate(size_t num)
	{
		T* ret = nullptr;
		const size_t size = num * sizeof(T);

		try {
			ret = new T[size];
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		return ret;
	}

	void construct(T* p, const T& value)
	{
		*p = value;
	}

	// �̈�̉��
	void deallocate(T* p)
	{
		delete p;
	}

	// ���蓖�Ă�ꂽ�X�g���[�W���̃I�u�W�F�N�g�̔j��
	void destroy(T* p)
	{
		p->~T();
	}
};
