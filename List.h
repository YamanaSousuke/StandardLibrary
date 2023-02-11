#pragma once

#include <exception>
#include <iostream>

template<class T>
class MyAllocator
{
public:
	MyAllocator() { }

	// ストレージの確保
	T* allocate(size_t num)
	{
		T* ret = nullptr;
		const size_t size = num * sizeof(T);
	
		try {
			ret = new T[size];
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		return ret;
	}

	void construct(T* p, const T& value)
	{
		*p = value;
	}

	// 領域の解放
	void deallocate(T* p)
	{
		delete p;
	}

	// 割り当てられたストレージ内のオブジェクトの破棄
	void destroy(T* p)
	{
		p->~T();
	}
};

// リスト
template<class T, class Alloc = MyAllocator<T>>
class MyList
{
public:
	// コンストラクタ
	explicit MyList(const Alloc& alloc = Alloc())
	{
		createDummyNode();
	}

	// サイズと要素を指定したコンストラクタ
	explicit MyList(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
	{
		createDummyNode();
		while (size < num) {
			push_back(value);
		}
	}

	// デストラクタ
	~MyList()
	{
		clear();
		allocNode.deallocate(dummyNode);
	}

	// 先頭に要素の追加
	void push_front(const T& value)
	{
		Node* newNode = createNode(value);
		newNode->prev = dummyNode;
		newNode->next = dummyNode->next;
		dummyNode->next->prev = newNode;
		dummyNode->next = newNode;
		size++;
	}

	// 先頭要素の削除
	void pop_front()
	{
		if (size > 0) {
			deleteNode(dummyNode->next);
		}
	}

	// 末尾に要素の追加
	void push_back(const T& value)
	{
		Node* newNode = createNode(value);
		newNode->prev = dummyNode->prev;
		newNode->next = dummyNode;
		dummyNode->prev->next = newNode;
		dummyNode->prev = newNode;
		size++;
	}

	// 末尾の要素の削除
	void pop_back()
	{
		if (size > 0) {
			deleteNode(dummyNode->prev);
		}
	}

	// リストに要素があるか
	bool empty() const
	{
		return size == 0;
	}

	// サイズの取得
	size_t getSize() const
	{
		return size;
	}
	
	// 要素数に合わせてリサイズする
	void resize(size_t num, const T& value = T())
	{
		// 要素数が足りないので、新しく追加する
		while (num > size) {
			push_back(value);
		}

		// 要素数が足りているので、削除する
		while (num < size) {
			pop_back();
		}
	}

	// 全ての要素の削除
	void clear()
	{
		while (size > 0) {
			pop_back();
		}
	}

	// 要素の表示
	void ToString()
	{
		Node* next = dummyNode->next;
		while (next != dummyNode) {
			std::cout << next->data << std::endl;
			next = next->next;
		}
	}
private:
	// ノード
	struct Node {
		T data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

	// ノード
	Node* dummyNode = nullptr;
	// サイズ
	size_t size = 0;
	
	Alloc allocT = {};

	// ノードの割り当て
	MyAllocator<Node> allocNode = {};

private:
	// ダミーのノードの生成
	void createDummyNode()
	{
		dummyNode = allocNode.allocate(1);
		dummyNode->next = dummyNode;
		dummyNode->prev = dummyNode;
	}

	// 新しいノードの生成
	Node* createNode(const T& value = T())
	{
		Node* newNode = allocNode.allocate(1);
		allocT.construct(&newNode->data, value);
		return newNode;
	}

	// 指定したノードの削除
	void deleteNode(Node* toDelete)
	{
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;

		allocT.destroy(&toDelete->data);
		allocNode.deallocate(toDelete);
		size--;
	}
};