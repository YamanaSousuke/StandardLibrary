#pragma once

#include <exception>
#include <iostream>
#include "ListIterator.h"
#include "Allocator.h"

// ���X�g
template<class T, class Alloc = MyAllocator<T>>
class MyList
{
private:
	// �m�[�h
	struct Node {
		T data = 0;
		Node* next = nullptr;
		Node* prev = nullptr;
	};

	// �m�[�h
	Node* dummyNode = nullptr;
	// �T�C�Y
	size_t size = 0;

	Alloc allocT = {};

	// �m�[�h�̊��蓖��
	MyAllocator<Node> allocNode = {};

public:
	using iterator = listIterator<T, Node>;

public:
	// �R���X�g���N�^�[
	explicit MyList(const Alloc& alloc = Alloc())
	{
		createDummyNode();
	}

	// �T�C�Y�Ɨv�f���w�肵���R���X�g���N�^�[
	explicit MyList(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
	{
		createDummyNode();
		while (size < num) {
			push_back(value);
		}
	}

	// �f�X�g���N�^�[
	~MyList()
	{
		clear();
		allocNode.deallocate(dummyNode);
	}

	// ������Z�q�̃I�[�o�[���[�h
	MyList& operator=(const MyList& other)
	{
		MyList copy(other);
		return copy;
	}

	// �擪�ɗv�f�̒ǉ�
	void push_front(const T& value)
	{
		Node* newNode = createNewNode(value);
		newNode->prev = dummyNode;
		newNode->next = dummyNode->next;
		dummyNode->next->prev = newNode;
		dummyNode->next = newNode;
		size++;
	}

	// �擪�v�f�̍폜
	void pop_front()
	{
		if (size > 0) {
			deleteNode(dummyNode->next);
		}
	}

	// �����ɗv�f�̒ǉ�
	void push_back(const T& value)
	{
		Node* newNode = createNewNode(value);
		newNode->prev = dummyNode->prev;
		newNode->next = dummyNode;
		dummyNode->prev->next = newNode;
		dummyNode->prev = newNode;
		size++;
	}

	// �����̗v�f�̍폜
	void pop_back()
	{
		if (size > 0) {
			deleteNode(dummyNode->prev);
		}
	}

	// ���X�g�ɗv�f�����邩
	bool empty() const
	{
		return size == 0;
	}

	// �T�C�Y�̎擾
	size_t getSize() const
	{
		return size;
	}
	
	// �v�f���ɍ��킹�ă��T�C�Y����
	void resize(size_t num, const T& value = T())
	{
		// �v�f��������Ȃ��̂ŁA�V�����ǉ�����
		while (num > size) {
			push_back(value);
		}

		// �v�f��������Ă���̂ŁA�폜����
		while (num < size) {
			pop_back();
		}
	}

	// �S�Ă̗v�f�̍폜
	void clear()
	{
		while (size > 0) {
			pop_back();
		}
	}

	// �v�f�̕\��
	void ToString()
	{
		Node* next = dummyNode->next;
		while (next != dummyNode) {
			std::cout << next->data << std::endl;
			next = next->next;
		}
	}

	// ���X�g�̐擪�v�f���w���C�e���[�^�[
	iterator begin()
	{
		return size ? iterator(dummyNode->next) : iterator(dummyNode);
	}

	// �_�~�[�m�[�h���w���C�e���[�^�[
	iterator end()
	{
		return iterator(dummyNode);
	}

	// �v�f�̑}��
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

	// 1�̗v�f��j������
	iterator erase(iterator position)
	{
		return erase(position, position.getNodePointer()->next);
	}

	// �͈͂��w�肵�ėv�f�̔j��
	iterator erase(iterator first, iterator last)
	{
		while (first != last) {
			deleteNode((++first).getNodePointer()->prev);
		}

		return last;
	}

	// �v�f�̑}��(��2�����Ɍ��̎w��)
	void insert(iterator position, size_t num, const T& value)
	{
		while (num-- > 0) {
			position = insert(position, value);
		}
	}

	// �擪�v�f
	T& front()
	{
		return dummyNode->next->data;
	}

	// �����v�f
	T& back()
	{
		return dummyNode->prev->data;
	}

	// �R���e�i�̍đ��(�C�e���[�^�[�Ŕ͈͂̎w��)
	void assign(iterator first, iterator last)
	{
		size_t i = 0;
		for (iterator it = begin(); first != last; ++it, ++first, ++i) {
			// �T�C�Y������Ȃ���΁A�g������
			if (i >= size) {
				push_back(*first);
			}
			// ���ɂ���΁A������Ă���l�����蓖�Ă�
			else {
				allocT.destroy(&(*it));
				allocT.construct(&(*it), *first);
			}
		}

		// num�̐��𒴂��Ă��镪�͍폜����
		while (size > i) {
			pop_back();
		}
	}

	// �R���e�i�̍đ��(���ƒl�̎w��)
	void assign(size_t num, const T& value)
	{
		size_t i = 0;
		for (iterator it = begin(); i < num; ++it, ++i) {
			// �T�C�Y������Ȃ���΁A�g������
			if (i >= size) {
				push_back(value);
			}
			// ���ɂ���΁A������Ă���l�����蓖�Ă�
			else {
				allocT.destroy(&(*it));
				allocT.construct(&(*it), value);
			}
		}

		// num�̐��𒴂��Ă��镪�͍폜����
		while (size > i) {
			pop_back();
		}
	}

	// �w�肵���v�f��S�Ĕj������
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

	// �������w�肵�ėv�f��j������
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

	// �d�������v�f�̍폜(�R���e�i���\�[�g�ςł��邱��)
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

	// 1�̗v�f���ړ�������
	void splice(iterator position, MyList& list, iterator before)
	{
		// �v�f�����炷
		Node* temp = before.getNodePointer();
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;

		// �V�����v�f�ɕt��������
		temp->prev = position.getNodePointer()->prev;
		temp->next = position.getNodePointer();
		position.getNodePointer()->prev->next = temp;
		position.getNodePointer()->prev = temp;

		--list.size;
		++size;
	}

	void merge(MyList& x)
	{
		// �������X�g�Ȃ��r���Ȃ�
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

	// ���X�g�̓���ւ�
	void swap(MyList& other)
	{
		swap(size, other.size);
		swap(dummyNode, other.dummyNode);
		swap(allocT, other.allocT);
		swap(allocNode, other.allocNode);
	}

private:
	// �_�~�[�̃m�[�h�̐���
	void createDummyNode()
	{
		dummyNode = allocNode.allocate(1);

		dummyNode->next = dummyNode;
		dummyNode->prev = dummyNode;
	}

	// �V�����m�[�h�̐���
	Node* createNewNode(const T& value = T())
	{
		Node* newNode = allocNode.allocate(1);
		allocT.construct(&newNode->data, value);
		return newNode;
	}

	// �w�肵���m�[�h�̍폜
	void deleteNode(Node* toDelete)
	{
		toDelete->prev->next = toDelete->next;
		toDelete->next->prev = toDelete->prev;

		allocT.destroy(&toDelete->data);
		allocNode.deallocate(toDelete);
		size--;
	}

	// 2�̕ϐ��̓���ւ�
	template<typename T>
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
};