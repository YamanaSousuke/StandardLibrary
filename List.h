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
	// 先頭に要素を追加
	void push_front(int data);
	// 末尾に要素を追加
	void push_back(int data);
	// データの表示
	void ToString();
	// ノードの各メンバに値を設定
	void SetNode(Node* node, int data, Node* next, Node* prev);
	// 指定したノードの削除
	void Remove(Node* node);
	// 先頭から要素を削除	
	void pop_front();
	// 末尾から要素を削除
	void pop_back();
	// コンテナが空かどうかを判定する
	bool empty();
	// 全要素削除
	void clear();
private:
	// 先頭ノードへのポインター
	Node* head = nullptr;
	// 着目ノードへのポインター
	Node* current = nullptr;
};
