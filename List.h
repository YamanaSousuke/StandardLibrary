#pragma once

#include <exception>
#include <iostream>

template<class T>
class Allocator
{
public:
	Allocator() { std::cout << "Allocator Init" << std::endl; }
	// Allocator(const Allocator&) { }

	// value�̃A�h���X��Ԃ�
	// T* Address(T& value) const { return &value; }
	// �X�g���[�W�̊m��
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

	// �̈�̉��
	void Dealloacte(T* p)
	{
		delete p;
	}
private:
};

// ���X�g
template<class T, class Alloc = Allocator<T>>
class MyList
{
public:
	// �R���X�g���N�^
	explicit MyList(const Alloc& alloc = Alloc()) : size(0), allocT(alloc)
	{
		CreateNewNode();
	}

	// �f�X�g���N�^
	~MyList()
	{
		while (size > 0) {
			pop_back();
		}

		allocNode.Dealloacte(dummyNode);
	}

	// �擪�ɗv�f�̒ǉ�
	void push_front(const T& value)
	{
		Node* newNode = CreateNode(value);
		newNode->prev = dummyNode;
		newNode->next = dummyNode->next;
		dummyNode->next->prev = newNode;
		dummyNode->next = newNode;
	}

	// �����ɗv�f�̒ǉ�
	void push_back(const T& value)
	{
		Node* newNode = CreateNode(value);
		newNode->prev = dummyNode->prev;
		newNode->next = dummyNode;
		dummyNode->prev->next = newNode;
		dummyNode->prev = newNode;
		size++;
	}

	// �����m�[�h�̍폜
	void pop_back()
	{
		if (size) {
			std::cout << "delete last element" << std::endl;
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
	Node* dummyNode;
	// �T�C�Y
	size_t size;
	
	Alloc allocT;

	// �m�[�h�̊��蓖��
	Allocator<Node> allocNode;

private:
	// �V�����m�[�h�̐���
	void CreateNewNode()
	{
		dummyNode = allocNode.Alloacte(1);
		dummyNode->next = dummyNode;
		dummyNode->prev = dummyNode;
	}

	// �m�[�h�̐���
	Node* CreateNode(const T& value = T())
	{
		Node* newNode = allocNode.Allocate(1);
		allocT.Construct(value);
		return newNode;
	}
};