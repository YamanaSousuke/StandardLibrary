#include <iostream>
#include "List.h"

int main()
{
	List list = {};
	list.Initialize();

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

// 先頭にノードの挿入
void List::InsertFront(int data)
{
	Node* newNode = new Node;
	Node* dummy = head->next;

	head->next = head->next->prev = newNode;
	SetNode(newNode, data, head, dummy);
	current = newNode;
}

// ノードの各メンバに値を設定
void List::SetNode(Node* node, int data, Node* next, Node* prev)
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
