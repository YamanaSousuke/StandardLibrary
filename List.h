#pragma once

// ノード
struct Node {
	int value = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

// リスト
class List
{
public:
	// 初期化
	void Initialize();
	// 指定したノードの直後に要素の挿入
	void InsertAfter(Node* node, int data);
	// 先頭にノードの挿入
	void InsertFront(int data);
	// 末尾にノードの挿入
	void InsertRear(int data);

	// ノードの各メンバに値を設定
	void SetNode(Node* node, int data, Node* next, Node* prev);

	// 指定したノードの削除
	void Remove(Node* node);
	// 先頭ノードの削除
	void RemoveFront();
	// リストが空かどうか
	bool IsEmpty();
	// 全てのノードの削除
	void Clear();
private:
	// 先頭ノードへのポインター
	Node* head = nullptr;
	// 着目ノードへのポインター
	Node* current = nullptr;
};
