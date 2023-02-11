#pragma once

#include <exception>
#include <iostream>

template<class T>
class MyAllocator
{
public:
	MyAllocator() { }

	// �X�g���[�W�̊m��
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

	// �̈�̉��
	void deallocate(T* p)
	{
		delete p;
	}

	// ���蓖�Ă�ꂽ�X�g���[�W���̃I�u�W�F�N�g�̔j��
	void destroy(T* p)
	{
		p->~T();
	}
};

// ���X�g
template<class T, class Alloc = MyAllocator<T>>
class MyList
{
public:
	// �R���X�g���N�^
	explicit MyList(const Alloc& alloc = Alloc())
	{
		createDummyNode();
	}

	// �T�C�Y�Ɨv�f���w�肵���R���X�g���N�^
	explicit MyList(size_t num, const T& value = T(), const Alloc& alloc = Alloc())
	{
		createDummyNode();
		while (size < num) {
			push_back(value);
		}
	}

	// �f�X�g���N�^
	~MyList()
	{
		clear();
		allocNode.deallocate(dummyNode);
	}

	// �擪�ɗv�f�̒ǉ�
	void push_front(const T& value)
	{
		Node* newNode = createNode(value);
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
		Node* newNode = createNode(value);
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

private:
	// �_�~�[�̃m�[�h�̐���
	void createDummyNode()
	{
		dummyNode = allocNode.allocate(1);
		dummyNode->next = dummyNode;
		dummyNode->prev = dummyNode;
	}

	// �V�����m�[�h�̐���
	Node* createNode(const T& value = T())
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
};