#pragma once

// �w�肳�ꂽ���\�[�X�ւ̃|�C���^�̏��L����B�ꎝ���Ă���悤�ɐU�����X�}�[�g�|�C���^
template<typename T>
class MyUniquePtr
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	MyUniquePtr() : data(nullptr) { }
	// �R���X�g���N�^�[
	MyUniquePtr(T* data) : data(data) { }
	// �R�s�[�֎~
	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;
	// ���[�u�R���X�g���N�^�[
	MyUniquePtr(MyUniquePtr&& other) noexcept
	{
		data = other.data;
		other.data = nullptr;
	}
	// ���[�u������Z�q
	MyUniquePtr& operator=(MyUniquePtr&& other) noexcept
	{
		if (this == &other) {
			return *this;
		}

		data = other.data;
		other.data = nullptr;
		return *this;
	}

	// �f�X�g���N�^�[
	~MyUniquePtr()
	{
		if (data != nullptr) {
			delete data;
		}
	}

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const
	{
		return *data;
	}

	// �A���[���Z�q�̃I�[�o�[���[�h
	T* operator->() const
	{
		return data;
	}

	// �|�C���^���Ǘ����Ă��邩���m�F����
	operator bool() const
	{
		return data ? true : false;
	}

	// �l�C�e�B�u�|�C���^�[�̎擾
	T* get() const
	{
		return data;
	}

	// ���\�[�X�̉��
	void reset()
	{
		delete data;
		data = nullptr;
	}

	// ���\�[�X�̊J���ƐV�������\�[�X�̐ݒ�
	void reset(T* newData)
	{
		delete data;
		data = newData;
	}

	// ���\�[�X���Ǘ������痣��
	T* release()
	{
		T* temp(data);
		data = nullptr;
		return temp;
	}
private:
	// ���\�[�X
	T* data;
};
