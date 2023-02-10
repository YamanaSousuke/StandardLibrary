#include <iostream>
#include "List.h"

int main()
{
	List list = {};
	list.Initialize();

	list.Clear();
	return 0;
}

// ������
void List::Initialize()
{
	// �_�~�[�̃m�[�h�̍쐬
	Node* dummyNode = new Node;
	head = current = dummyNode;
	dummyNode->next = dummyNode->prev = dummyNode;
}

// �擪�Ƀm�[�h�̑}��
void List::InsertFront(int data)
{
	Node* newNode = new Node;
	Node* dummy = head->next;

	head->next = head->next->prev = newNode;
	SetNode(newNode, data, head, dummy);
	current = newNode;
}

// �m�[�h�̊e�����o�ɒl��ݒ�
void List::SetNode(Node* node, int data, Node* next, Node* prev)
{
	node->value = data;
	node->next = next;
	node->prev = prev;
}

// �w�肵���m�[�h�̍폜
void List::Remove(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	current = node->prev;
	delete node;

	// �_�~�[���w���Ă���������w������
	if (current == head) {
		current = head->next;
	}
}

// �擪�m�[�h�̍폜
void List::RemoveFront()
{
	// TODO : ���X�g����ł���Όx���̕\��
	if (IsEmpty()) {
		std::cout << "not exit node" << std::endl;
		return;
	}

	Remove(head->next);
}

// ���X�g���󂩂ǂ���
bool List::IsEmpty()
{
	return head->next == head;
}

// �S�Ẵm�[�h�̍폜
void List::Clear()
{
	while (!IsEmpty()) {
		RemoveFront();
	}

	// �_�~�[�m�[�h�̔j��
	delete head;
}
