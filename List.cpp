#include <iostream>
#include "List.h"

void ToString(Node* node);
void Search(Node* node, int element);
void InsertAfterTheElement(Node* node, int search, int element);
void InsertBeforeTheElement(Node* node, int search, int element);
Node* InsertAtBeging(Node* node, int element);

int main()
{
	Node* head = nullptr;
	Node* old = nullptr;

	// ���I�ɗv�f���̎擾
	int numElements = 0;
	// �}������v�f
	int element = 0;
	
	std::cout << "num element" << std::endl;
	std::cin >> numElements;

	for (int i = 0; i < numElements; i++) {
		std::cout << "add element" << std::endl;
		std::cin >> element;

		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = NULL;

		if (i == 0) {
			head = newNode;
		}
		else {
			old->next = newNode;
		}
		old = newNode;
	}

	// �\��
	// ToString(head);

	int searchElement = 0;
	int insertElement = 0;
	// std::cout << "search element" << std::endl;
	// std::cin >> searchElement;
	std::cout << "insert element" << std::endl;
	std::cin >> insertElement;
	
	// InsertBeforeTheElement(head, searchElement, insertElement);
	head = InsertAtBeging(head, insertElement);

	// �\��
	ToString(head);

	return 0;
}

// �\��
void ToString(Node* node)
{
	Node* current = node;
	int count = 0;

	while (1) {
		std::cout << count << ":" << current->value << std::endl;
		count++;
		if (current->next == NULL) {
			break;
		}
		current = current->next;
	}
}

// ����̗v�f�̒T��
void Search(Node* node, int element)
{
	Node* current = node;

	while (1) {
		// �v�f�������������A���ւ̃|�C���^�[��������ΏI��
		if (current->value == element) {
			break;
		}

		if (current->next == NULL) {
			break;
		}

		current = current->next;
	}

	if (current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	else {
		std::cout << current->value << std::endl;
	}
	
}

// ����̗v�f�̌�Ɏw�肵���v�f�̑}��
void InsertAfterTheElement(Node* node, int search, int element)
{
	Node* current = node;

	while (1) {
		if (current->value == search || current->next == NULL) {
			break;
		}
		current = current->next;
	}
	
	// �T�������v�f��������Ȃ������ꍇ
	if (current->value != search && current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	// �T�������v�f����ԍŌ�ɗL�����ꍇ
	else if (current->value == search && current->next == NULL) {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next == NULL;
	}
	// �T�������v�f����ԍŌ�ȊO�ɗL�����ꍇ
	else {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current->next;
		current->next = newNode;
	}
}

// ����̗v�f�̑O�Ɏw�肵���v�f�̑}��
void InsertBeforeTheElement(Node* node, int search, int element)
{
	Node* current = node;
	Node* prev = nullptr;

	while (1) {
		if (current->value == search || current->next == NULL) {
			break;
		}

		prev = current;
		current = current->next;
	}

	// �T�������v�f��������Ȃ������ꍇ
	if (current->value != search && current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	// �擪�Ƀm�[�h�̒ǉ�
	else if (current == node) {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current->next;
		node = newNode;
	}
	// �擪�ȊO�Ƀm�[�h�̒ǉ�
	else {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current;
		prev->next = newNode;
	}
}

// �v�f�����X�g�̐擪�ɑ}��
Node* InsertAtBeging(Node* node, int element)
{
	Node* newNode = new Node;
	newNode->value = element;
	newNode->next = node;
	return node = newNode;
}