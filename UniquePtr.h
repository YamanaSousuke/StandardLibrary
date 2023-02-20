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
	// �f�X�g���N�^�[
	~MyUniquePtr()
	{
		delete data;
	}
	
	// �l�C�e�B�u�|�C���^�[�̎擾
	T* get() const
	{
		return data;
	}


private:
	T* data;
};
