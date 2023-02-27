#include "String.h"

// �R���X�g���N�^�[
MyString::MyString()
{
	data = new char[length + 1];
	data[0] = '\0';
}

// ��������w�肵���R���X�g���N�^�[
MyString::MyString(const char* value)
{
	while (value[length] != '\0') {
		length++;
	}

	// ���������m�ۂ��āA1�������R�s�[����
	data = new char[length + 1];
	for (size_t index = 0; index < length + 1; index++) {
		data[index] = value[index];
	}
}

// �f�X�g���N�^�[
MyString::~MyString()
{
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
}

// �R�s�[�R���X�g���N�^�[
MyString::MyString(const MyString& other)
{
	// �R�s�[��Ɋ��Ƀf�[�^������ꍇ�͔j������
	if (data != nullptr) {
		delete[] data;
	}

	// �R�s�[
	length = other.length;
	data = new char[length + 1];
	for (size_t index = 0; index < length + 1; index++) {
		data[index] = other.data[index];
	}
}

// ������Z�q�̃I�[�o�[���[�h
void MyString::operator=(const MyString& other)
{
	// �R�s�[��Ɋ��Ƀf�[�^������ꍇ�͔j������
	if (data != nullptr) {
		delete[] data;
	}
	
	// �R�s�[
	length = other.length;
	data = new char[length + 1];
	for (size_t index = 0; index < length + 1; index++) {
		data[index] = other.data[index];
	}
}

// �Y�������Z�q�̃I�[�o�[���[�h
char& MyString::operator[](unsigned int index) const
{
	return index >= length ? data[length - 1] : data[index];
}

// �������Z�q�̃I�[�o�[���[�h
bool MyString::operator==(const MyString& other) const
{
	if (length != other.length) {
		return false;
	}

	int index = 0;
	while ((data[index] - other.data[index]) == 0 && data[index] != '\0') {
		index++;
	}
	return index == length;
}

// �񓙉����Z�q�̃I�[�o�[���[�h
bool MyString::operator!=(const MyString& other) const
{
	return !(*this == other);
}

// ������̐擪�A�h���X�̎擾
const char* MyString::c_str() const
{
	return data;
}

// ��̕����񂩂ǂ���
bool MyString::empty() const
{
	return length == 0;
}

// �T�C�Y�̎擾
size_t MyString::size() const
{
	return length;
}
