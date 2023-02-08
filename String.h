#pragma once

// ������N���X
class MyString
{
public:
	// �R���X�g���N�^�[
	MyString();
	MyString(const char* value);
	// �f�X�g���N�^�[
	~MyString();
	// �R�s�[�R���X�g���N�^�[
	MyString(const MyString& other);
	// ������Z�q�̃I�[�o�[���[�h
	void operator=(const MyString& other);
	// �Y�������Z�q�̃I�[�o�[���[�h
	char& operator[](unsigned int index) const;
	// �������Z�q�̃I�[�o�[���[�h
	bool operator==(const MyString& other) const;
	// �񓙉����Z�q�̃I�[�o�[���[�h
	bool operator!=(const MyString& other) const;

	// ������̐擪�A�h���X�̎擾
	const char* c_str() const;
	// ��̕����񂩂ǂ���
	bool empty() const;
	// �T�C�Y�̎擾
	size_t size() const;
private:
	// ���\�[�X
	char* data = nullptr;
	// ������̒���
	size_t length = 0;
};
