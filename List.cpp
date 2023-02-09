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

	// 動的に要素数の取得
	int numElements = 0;
	// 挿入する要素
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

	// 表示
	// ToString(head);

	int searchElement = 0;
	int insertElement = 0;
	// std::cout << "search element" << std::endl;
	// std::cin >> searchElement;
	std::cout << "insert element" << std::endl;
	std::cin >> insertElement;
	
	// InsertBeforeTheElement(head, searchElement, insertElement);
	head = InsertAtBeging(head, insertElement);

	// 表示
	ToString(head);

	return 0;
}

// 表示
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

// 特定の要素の探索
void Search(Node* node, int element)
{
	Node* current = node;

	while (1) {
		// 要素が見つかったか、次へのポインターが無ければ終了
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

// 特定の要素の後に指定した要素の挿入
void InsertAfterTheElement(Node* node, int search, int element)
{
	Node* current = node;

	while (1) {
		if (current->value == search || current->next == NULL) {
			break;
		}
		current = current->next;
	}
	
	// 探索した要素が見つからなかった場合
	if (current->value != search && current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	// 探索した要素が一番最後に有った場合
	else if (current->value == search && current->next == NULL) {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next == NULL;
	}
	// 探索した要素が一番最後以外に有った場合
	else {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current->next;
		current->next = newNode;
	}
}

// 特定の要素の前に指定した要素の挿入
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

	// 探索した要素が見つからなかった場合
	if (current->value != search && current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	// 先頭にノードの追加
	else if (current == node) {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current->next;
		node = newNode;
	}
	// 先頭以外にノードの追加
	else {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current;
		prev->next = newNode;
	}
}

// 要素をリストの先頭に挿入
Node* InsertAtBeging(Node* node, int element)
{
	Node* newNode = new Node;
	newNode->value = element;
	newNode->next = node;
	return node = newNode;
}