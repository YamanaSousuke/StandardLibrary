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
	// �擪�Ƀm�[�h�̑}��
	void InsertFront(int data);
	// �m�[�h�̊e�����o�ɒl��ݒ�
	void SetNode(Node* node, int data, Node* next, Node* prev);

	// �w�肵���m�[�h�̍폜
	void Remove(Node* node);
	// �擪�m�[�h�̍폜
	void RemoveFront();
	// ���X�g���󂩂ǂ���
	bool IsEmpty();
	// �S�Ẵm�[�h�̍폜
	void Clear();
private:
	// �擪�m�[�h�ւ̃|�C���^�[
	Node* head = nullptr;
	// ���ڃm�[�h�ւ̃|�C���^�[
	Node* current = nullptr;
};
