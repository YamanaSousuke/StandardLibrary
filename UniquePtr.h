#pragma once

// �w�肳�ꂽ���\�[�X�ւ̃|�C���^�̏��L����B�ꎝ���Ă���悤�ɐU�����X�}�[�g�|�C���^
template<typename T>
class MyUniquePtr
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	MyUniquePtr();
	// �R���X�g���N�^�[
	MyUniquePtr(T* data);
	// �R�s�[�֎~
	MyUniquePtr(const MyUniquePtr&) = delete;
	MyUniquePtr& operator=(const MyUniquePtr&) = delete;
	// ���[�u�R���X�g���N�^�[
	MyUniquePtr(MyUniquePtr&& other) noexcept;
	// ���[�u������Z�q
	MyUniquePtr& operator=(MyUniquePtr&& other) noexcept;
	// �f�X�g���N�^�[
	~MyUniquePtr();

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const;
	// �A���[���Z�q�̃I�[�o�[���[�h
	T* operator->() const;
	// �|�C���^���Ǘ����Ă��邩���m�F����
	operator bool() const;
	// �|�C���^�[�̎擾
	T* get() const;
	// ���\�[�X�̉��
	void reset();
	// ���\�[�X�̊J���ƐV�������\�[�X�̐ݒ�
	void reset(T* newData);
	// ���\�[�X���Ǘ������痣��
	T* release();
private:
	// ���\�[�X
	T* data;
};
