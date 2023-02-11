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

		allocNode.Dealloacte(node);
	}

	// �����Ƀf�[�^�̒ǉ�
	void push_back(const T& value)
	{

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
	Node* node;
	// �T�C�Y
	size_t size;
	
	Alloc allocT;

	// �m�[�h�̊��蓖��
	Allocator<Node> allocNode;

private:
	// �V�����m�[�h�̐���
	void CreateNewNode()
	{
		node = allocNode.Alloacte(1);
		node->next = node;
		node->prev = node;
	}

	// �m�[�h�̐���
	void CreateNode(const T& value = T())
	{
		Node* newNode = allocNode.Allocate(1);
	}
};