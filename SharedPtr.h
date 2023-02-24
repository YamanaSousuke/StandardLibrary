#pragma once

#include <iostream>

template<typename T>
class MySharedPtr
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	MySharedPtr();
	// �R���X�g���N�^�[
	explicit MySharedPtr(T* data);
	// �R�s�[�R���X�g���N�^�[
	MySharedPtr(const MySharedPtr& other);
	// �f�X�g���N�^�[
	~MySharedPtr();

	// ������Z�q�̃I�[�o�[���[�h
	MySharedPtr& operator=(const MySharedPtr& other);
	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const;
	// �A���[���Z�q�̃I�[�o�[���[�h
	T* operator->() const;

	// �|�C���^�[�̎擾
	T* get() const;
	// �Q�ƃJ�E���g�̎擾
	int use_count() const;
	// ���L���̔j��
	void reset();
	// ���L����������A�V���ȃ��\�[�X�̏��L����ݒ肷��
	void reset(T* newData);
private:
	// ���\�[�X
	T* data = nullptr;
	// �Q�ƃJ�E���g
	int* count = nullptr;
};
