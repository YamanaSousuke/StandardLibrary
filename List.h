#pragma once

#include <exception>
#include <iostream>
#include "ListIterator.h"
#include "Allocator.h"

// リスト
template<class T, class Alloc = MyAllocator<T>>
class MyList
{
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

public:
	using iterator = listIterator<T, Node>;

public:
	// コンストラクター
	explicit MyList(const Alloc& alloc = Alloc())
	{
		createDummyNode();
	}

	// サイズと要素を指定したコンストラクター
	explicit MyList(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
	{
		createDummyNode();
		while (size < num) {
			push_back(value);
		}
	}

	// デストラクター
	~MyList()
	{
		clear();
		allocNode.deallocate(dummyNode);
	}

	// 代入演算子のオーバーロード
	MyList& operator=(const MyList& other)
	{
		MyList copy(other);
		return copy;
	}

	// 先頭に要素の追加
	void push_front(const T& value)
	{
		Node* newNode = createNewNode(value);
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
		Node* newNode = createNewNode(value);
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

	// リストの先頭要素を指すイテレーター
	iterator begin()
	{
		return size ? iterator(dummyNode->next) : iterator(dummyNode);
	}

	// ダミーノードを指すイテレーター
	iterator end()
	{
		return iterator(dummyNode);
	}

	// 要素の挿入
	iterator insert(iterator position, const T& value)
	{
		Node* newNode = createNewNode(value);
		newNode->prev = position.getNodePointer()->prev;
		newNode->next = position.getNodePointer();

		newNode->prev->next = newNode;
		newNode->next->prev = newNode;

		++size;
		return --position;
	}

	// 1つの要素を破棄する
	iterator erase(iterator position)
	{
		return erase(position, position.getNodePointer()->next);
	}

	// 範囲を指定して要素の破棄
	iterator erase(iterator first, iterator last)
	{
		while (first != last) {
			deleteNode((++first).getNodePointer()->prev);
		}

		return last;
	}

	// 要素の挿入(第2引数に個数の指定)
	void insert(iterator position, size_t num, const T& value)
	{
		while (num-- > 0) {
			position = insert(position, value);
		}
	}

	// 先頭要素
	T& front()
	{
		return dummyNode->next->data;
	}

	// 末尾要素
	T& back()
	{
		return dummyNode->prev->data;
	}

	// コンテナの再代入(イテレーターで範囲の指定)
	void assign(iterator first, iterator last)
	{
		size_t i = 0;
		for (iterator it = begin(); first != last; ++it, ++first, ++i) {
			// サイズが足りなければ、拡張する
			if (i >= size) {
				push_back(*first);
			}
			// 既にあれば、解放してから値を割り当てる
			else {
				allocT.destroy(&(*it));
				allocT.construct(&(*it), *first);
			}
		}

		// numの数を超えている分は削除する
		while (size > i) {
			pop_back();
		}
	}

	// コンテナの再代入(個数と値の指定)
	void assign(size_t num, const T& value)
	{
		size_t i = 0;
		for (iterator it = begin(); i < num; ++it, ++i) {
			// サイズが足りなければ、拡張する
			if (i >= size) {
				push_back(value);
			}
			// 既にあれば、解放してから値を割り当てる
			else {
				allocT.destroy(&(*it));
				allocT.construct(&(*it), value);
			}
		}

		// numの数を超えている分は削除する
		while (size > i) {
			pop_back();
		}
	}

	// 指定した要素を全て破棄する
	void remove(const T& value)
	{
		for (iterator it = end(); it.getNodePointer()->next != end().getNodePointer();) {
			if (it.getNodePointer()->next->data == value) {
				deleteNode(it.getNodePointer()->next);
			}
			else {
				++it;
			}
		}
	}

	// 条件を指定して要素を破棄する
	template<class Predicate>
	void remove_if(Predicate pred)
	{
		for (iterator it = end(); it.getNodePointer()->next != end().getNodePointer();) {
			if (pred(it.getNodePointer()->next->data)) {
				deleteNode(it.getNodePointer()->next);
			}
			else {
				++it;
			}
		}
	}

	// 重複した要素の削除(コンテナがソート済であること)
	void unique()
	{
		for (iterator it = end(); it.getNodePointer()->next != end().getNodePointer();) {
			if (it != end() && *it == it.getNodePointer()->next->data) {
				deleteNode(it.getNodePointer()->next);
			}
			else {
				++it;
			}
		}
	}

	// 1つの要素を移動させる
	void splice(iterator position, MyList& list, iterator before)
	{
		// 要素を減らす
		Node* temp = before.getNodePointer();
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;

		// 新しい要素に付け加える
		temp->prev = position.getNodePointer()->prev;
		temp->next = position.getNodePointer();
		position.getNodePointer()->prev->next = temp;
		position.getNodePointer()->prev = temp;

		--list.size;
		++size;
	}

	void merge(MyList& x)
	{
		// 同じリストなら比較しない
		if (&x == this) {
			return;
		}

		iterator thisIt = end();

		for (iterator xIt = x.end(); xIt.getNodePointer()->next != x.end().getNodePointer();) {
			if (thisIt.getNodePointer()->next == end().getNodePointer() || xIt.getNodePointer()->next->data < thisIt.getNodePointer()->next->data) {
				splice(thisIt.getNodePointer()->next, x, xIt.getNodePointer()->next);
			}
			else {
				++thisIt;
			}
		}
	}

	// リストの入れ替え
	void swap(MyList& other)
	{
		swap(size, other.size);
		swap(dummyNode, other.dummyNode);
		swap(allocT, other.allocT);
		swap(allocNode, other.allocNode);
	}

private:
	// ダミーのノードの生成
	void createDummyNode()
	{
		dummyNode = allocNode.allocate(1);

		dummyNode->next = dummyNode;
		dummyNode->prev = dummyNode;
	}

	// 新しいノードの生成
	Node* createNewNode(const T& value = T())
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

	// 2つの変数の入れ替え
	template<typename T>
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
};