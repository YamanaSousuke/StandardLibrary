#pragma once

// リストに利用するイテレーター
template<typename T, typename Node>
class listIterator
{
public:
	
private:
	Node* node = nullptr;

public:
	// コンストラクタ
	listIterator(Node* node = nullptr) : node(node) { }
	// コピーコンストラクタ
	listIterator(const listIterator<T, Node>& copy)
	{
		node = copy.getNodePointer();
	}

	// デストラクタ
	~listIterator() { }

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
	listIterator& operator--()
	{
		node = node->prev;
		return *this;
	}

	listIterator& operator++()
	{
		node = node->next;
		return *this;
	}

	// 等価演算子のオーバーロード
	bool operator==(const listIterator& it)
	{
		return node == it.node;
	}

	bool operator!=(const listIterator& it)
	{
		return !(*this == it);
	}
};
