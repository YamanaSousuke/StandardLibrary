#pragma once

#include <exception>
#include <iostream>

template<class T>
class Allocator
{
public:
	Allocator() { std::cout << "Allocator Init" << std::endl; }
	// Allocator(const Allocator&) { }

	// valueのアドレスを返す
	// T* Address(T& value) const { return &value; }
	// ストレージの確保
	T* Alloacte(size_t num)
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

	void Construct(T& value)
	{
		new T(value);
	}

	// 領域の解放
	void Dealloacte(T* p)
	{
		delete p;
	}
private:
};

// リスト
template<class T, class Alloc = Allocator<T>>
class MyList
{
public:
	// コンストラクタ
	explicit MyList(const Alloc& alloc = Alloc()) : size(0), allocT(alloc)
	{
		CreateNewNode();
	}

	// デストラクタ
	~MyList()
	{
		while (size > 0) {
			pop_back();
		}

		allocNode.Dealloacte(dummyNode);
	}

	// 先頭に要素の追加
	void push_front(const T& value)
	{
		Node* newNode = CreateNode(value);
		newNode->prev = dummyNode;
		newNode->next = dummyNode->next;
		dummyNode->next->prev = newNode;
		dummyNode->next = newNode;
	}

	// 末尾に要素の追加
	void push_back(const T& value)
	{
		Node* newNode = CreateNode(value);
		newNode->prev = dummyNode->prev;
		newNode->next = dummyNode;
		dummyNode->prev->next = newNode;
		dummyNode->prev = newNode;
		size++;
	}

	// 末尾ノードの削除
	void pop_back()
	{
		if (size) {
			std::cout << "delete last element" << std::endl;
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
	Node* dummyNode;
	// サイズ
	size_t size;
	
	Alloc allocT;

	// ノードの割り当て
	Allocator<Node> allocNode;

private:
	// 新しいノードの生成
	void CreateNewNode()
	{
		dummyNode = allocNode.Alloacte(1);
		dummyNode->next = dummyNode;
		dummyNode->prev = dummyNode;
	}

	// ノードの生成
	Node* CreateNode(const T& value = T())
	{
		Node* newNode = allocNode.Allocate(1);
		allocT.Construct(value);
		return newNode;
	}
};