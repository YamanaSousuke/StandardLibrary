#pragma once

// �m�[�h
struct Node {
	int value = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

// ���X�g
class List
{
public:
	// ������
	void Initialize();
	// �w�肵���m�[�h�̒���ɗv�f�̑}��
	void InsertAfter(Node* node, int data);
	// �擪�ɗv�f��ǉ�
	void push_front(int data);
	// �����ɗv�f��ǉ�
	void push_back(int data);
	// �f�[�^�̕\��
	void ToString();
	// �m�[�h�̊e�����o�ɒl��ݒ�
	void SetNode(Node* node, int data, Node* next, Node* prev);
	// �w�肵���m�[�h�̍폜
	void Remove(Node* node);
	// �擪����v�f���폜	
	void pop_front();
	// ��������v�f���폜
	void pop_back();
	// �R���e�i���󂩂ǂ����𔻒肷��
	bool empty();
	// �S�v�f�폜
	void clear();
private:
	// �擪�m�[�h�ւ̃|�C���^�[
	Node* head = nullptr;
	// ���ڃm�[�h�ւ̃|�C���^�[
	Node* current = nullptr;
};
