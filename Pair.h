#pragma once

template<typename T1, typename T2>
class MyPair
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	MyPair() : first(), second() { }
	// �R���X�g���N�^�[
	MyPair(const T1& first, const T1& second) : first(first), second(second) { }

	// �f�X�g���N�^�[
	~MyPair() { }
private:
	T1 first;
	T2 second;
};
