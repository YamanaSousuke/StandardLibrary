#include <iostream>
#include "List.h"

int main()
{
	List list = {};
	list.Initialize();

	list.push_front(5);
	list.push_front(3);
	list.push_front(4);
	list.ToString();


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

// �w�肵���m�[�h�̒���ɗv�f�̑}��
void List::InsertAfter(Node* node, int data)
{
	Node* newNode = new Node;
	Node* next = node->next;

	node->next = node->next->prev = newNode;
	SetNode(newNode, data, node, next);
	current = newNode;
}

// �擪�Ƀm�[�h�̑}��
void List::push_front(int data)
{
	InsertAfter(head, data);
}

// �����Ƀm�[�h�̑}��
void List::push_back(int data)
{
	InsertAfter(head->prev, data);
}

// �f�[�^�̕\��
void List::ToString()
{
	if (IsEmpty()) {
		std::cout << "not exit node" << std::endl;
		return;
	}

	Node* node = head->next;
	while (node != head) {
		std::cout << node->value << std::endl;
		node = node->next;
	}
}

// �m�[�h�̊e�����o�ɒl��ݒ�
void List::SetNode(Node* node, int data, Node* prev, Node* next)
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

// �����m�[�h�̍폜
void List::RemoveRear()
{
	// TODO : ���X�g����ł���Όx���̕\��
	if (IsEmpty()) {
		std::cout << "not exit node" << std::endl;
		return;
	}

	Remove(head->prev);
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
