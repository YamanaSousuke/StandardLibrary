#pragma once

// リストに利用するイテレーター
template<typename T, typename Node>
class ListIterator
{
public:
	
private:
	Node* node = nullptr;

public:
	// コンストラクタ
	ListIterator(Node* node = nullptr) : node(node) { }
	// コピーコンストラクタ
	ListIterator(const ListIterator<T, Node>& copy)
	{
		node = copy.getNodePointer();
	}

	// デストラクタ
	~ListIterator() { }

	// イテレータが指し示す実際のノードへポインタ
	Node* getNodePointer() const
	{
		return node;
	}

	// 間接演算子のオーバーロード
	T& operator*() const
	{
		return node->data;
	}

	// 前置演算子のオーバーロード
	ListIterator& operator--()
	{
		node = node->prev;
		return *this;
	}

	ListIterator& operator++()
	{
		node = node->next;
		return *this;
	}

	// 等価演算子のオーバーロード
	bool operator==(const ListIterator& it)
	{
		return node == it.node;
	}

	bool operator!=(const ListIterator& it)
	{
		return !(*this == it);
	}
};
