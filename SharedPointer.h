#pragma once

#include <iostream>

template<typename T>
class MySharedPointer
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	MySharedPointer();
	// �R���X�g���N�^�[
	explicit MySharedPointer(T* data);
	// �R�s�[�R���X�g���N�^�[
	MySharedPointer(const MySharedPointer& other);
	// �f�X�g���N�^�[
	~MySharedPointer();

	// ������Z�q�̃I�[�o�[���[�h
	MySharedPointer& operator=(const MySharedPointer& other);
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
