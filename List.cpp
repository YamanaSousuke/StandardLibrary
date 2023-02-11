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

// 初期化
void List::Initialize()
{
	// ダミーのノードの作成
	Node* dummyNode = new Node;
	head = current = dummyNode;
	dummyNode->next = dummyNode->prev = dummyNode;
}

// 指定したノードの直後に要素の挿入
void List::InsertAfter(Node* node, int data)
{
	Node* newNode = new Node;
	Node* next = node->next;

	node->next = node->next->prev = newNode;
	SetNode(newNode, data, node, next);
	current = newNode;
}

// 先頭にノードの挿入
void List::push_front(int data)
{
	InsertAfter(head, data);
}

// 末尾にノードの挿入
void List::push_back(int data)
{
	InsertAfter(head->prev, data);
}

// データの表示
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

// ノードの各メンバに値を設定
void List::SetNode(Node* node, int data, Node* prev, Node* next)
{
	node->value = data;
	node->next = next;
	node->prev = prev;
}

// 指定したノードの削除
void List::Remove(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	current = node->prev;
	delete node;

	// ダミーを指していたら一つ先を指し示す
	if (current == head) {
		current = head->next;
	}
}

// 先頭ノードの削除
void List::RemoveFront()
{
	// TODO : リストが空であれば警告の表示
	if (IsEmpty()) {
		std::cout << "not exit node" << std::endl;
		return;
	}

	Remove(head->next);
}

// 末尾ノードの削除
void List::RemoveRear()
{
	// TODO : リストが空であれば警告の表示
	if (IsEmpty()) {
		std::cout << "not exit node" << std::endl;
		return;
	}

	Remove(head->prev);
}

// リストが空かどうか
bool List::IsEmpty()
{
	return head->next == head;
}

// 全てのノードの削除
void List::Clear()
{
	while (!IsEmpty()) {
		RemoveFront();
	}

	// ダミーノードの破棄
	delete head;
}
