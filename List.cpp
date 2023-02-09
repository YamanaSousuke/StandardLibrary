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

	// “®“I‚É—v‘f”‚Ìæ“¾
	int numElements = 0;
	// ‘}“ü‚·‚é—v‘f
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

	// •\¦
	// ToString(head);

	int searchElement = 0;
	int insertElement = 0;
	// std::cout << "search element" << std::endl;
	// std::cin >> searchElement;
	std::cout << "insert element" << std::endl;
	std::cin >> insertElement;
	
	// InsertBeforeTheElement(head, searchElement, insertElement);
	head = InsertAtBeging(head, insertElement);

	// •\¦
	ToString(head);

	return 0;
}

// •\¦
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

// “Á’è‚Ì—v‘f‚Ì’Tõ
void Search(Node* node, int element)
{
	Node* current = node;

	while (1) {
		// —v‘f‚ªŒ©‚Â‚©‚Á‚½‚©AŸ‚Ö‚Ìƒ|ƒCƒ“ƒ^[‚ª–³‚¯‚ê‚ÎI—¹
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

// “Á’è‚Ì—v‘f‚ÌŒã‚Éw’è‚µ‚½—v‘f‚Ì‘}“ü
void InsertAfterTheElement(Node* node, int search, int element)
{
	Node* current = node;

	while (1) {
		if (current->value == search || current->next == NULL) {
			break;
		}
		current = current->next;
	}
	
	// ’Tõ‚µ‚½—v‘f‚ªŒ©‚Â‚©‚ç‚È‚©‚Á‚½ê‡
	if (current->value != search && current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	// ’Tõ‚µ‚½—v‘f‚ªˆê”ÔÅŒã‚É—L‚Á‚½ê‡
	else if (current->value == search && current->next == NULL) {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next == NULL;
	}
	// ’Tõ‚µ‚½—v‘f‚ªˆê”ÔÅŒãˆÈŠO‚É—L‚Á‚½ê‡
	else {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current->next;
		current->next = newNode;
	}
}

// “Á’è‚Ì—v‘f‚Ì‘O‚Éw’è‚µ‚½—v‘f‚Ì‘}“ü
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

	// ’Tõ‚µ‚½—v‘f‚ªŒ©‚Â‚©‚ç‚È‚©‚Á‚½ê‡
	if (current->value != search && current->next == NULL) {
		std::cout << "not found" << std::endl;
	}
	// æ“ª‚Éƒm[ƒh‚Ì’Ç‰Á
	else if (current == node) {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current->next;
		node = newNode;
	}
	// æ“ªˆÈŠO‚Éƒm[ƒh‚Ì’Ç‰Á
	else {
		Node* newNode = new Node;
		newNode->value = element;
		newNode->next = current;
		prev->next = newNode;
	}
}

// —v‘f‚ğƒŠƒXƒg‚Ìæ“ª‚É‘}“ü
Node* InsertAtBeging(Node* node, int element)
{
	Node* newNode = new Node;
	newNode->value = element;
	newNode->next = node;
	return node = newNode;
}