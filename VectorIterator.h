#pragma once

// MyVector�Ɏg�p����C�e���[�^�[
template<typename T>
class VectorIterator
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	VectorIterator(T* ptr = nullptr); /* : ptr(ptr) { }*/
private:
	// �z��̗v�f���w���|�C���^�[
	T* ptr = nullptr;
};
