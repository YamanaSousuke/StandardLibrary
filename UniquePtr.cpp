#include "UniquePtr.h"

// �f�t�H���g�R���X�g���N�^�[
template<typename T>
MyUniquePtr<T>::MyUniquePtr() : data(nullptr)
{

}

// �R���X�g���N�^�[
template<typename T>
MyUniquePtr<T>::MyUniquePtr(T* data) : data(data)
{

}

// ���[�u�R���X�g���N�^�[
template<typename T>
MyUniquePtr<T>::MyUniquePtr(MyUniquePtr&& other) noexcept
{
	data = other.data;
	other.data = nullptr;
}

// ���[�u������Z�q
template<typename T>
MyUniquePtr<T>& MyUniquePtr<T>::operator=(MyUniquePtr&& other) noexcept
{
	if (this == &other) {
		return *this;
	}

	data = other.data;
	other.data = nullptr;
	return *this;
}

// �f�X�g���N�^�[
template<typename T>
MyUniquePtr<T>::~MyUniquePtr()
{
	if (data != nullptr) {
		delete data;
	}
}

// �Ԑډ��Z�q�̃I�[�o�[���[�h
template<typename T>
T& MyUniquePtr<T>::operator*() const
{
	return *data;
}

// �A���[���Z�q�̃I�[�o�[���[�h
template<typename T>
T* MyUniquePtr<T>::operator->() const
{
	return data;
}

// �|�C���^���Ǘ����Ă��邩���m�F����
template<typename T>
MyUniquePtr<T>::operator bool() const
{
	return data ? true : false;
}

// �|�C���^�[�̎擾
template<typename T>
T* MyUniquePtr<T>::get() const
{
	return data;
}

// ���\�[�X�̉��
template<typename T>
void MyUniquePtr<T>::reset()
{
	delete data;
	data = nullptr;
}

// ���\�[�X�̊J���ƐV�������\�[�X�̐ݒ�
template<typename T>
void MyUniquePtr<T>::reset(T* newData)
{
	delete data;
	data = newData;
}

// ���\�[�X���Ǘ������痣��
template<typename T>
T* MyUniquePtr<T>::release()
{
	T* temp(data);
	data = nullptr;
	return temp;
}