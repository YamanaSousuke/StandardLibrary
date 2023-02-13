#pragma once

// ���X�g�ɗ��p����C�e���[�^�[
template<typename T, typename Node>
class ListIterator
{
public:
	
private:
	Node* node = nullptr;

public:
	// �R���X�g���N�^
	ListIterator(Node* node = nullptr) : node(node) { }
	// �R�s�[�R���X�g���N�^
	ListIterator(const ListIterator<T, Node>& copy)
	{
		node = copy.getNodePointer();
	}

	// �f�X�g���N�^
	~ListIterator() { }

	// �C�e���[�^���w���������ۂ̃m�[�h�փ|�C���^
	Node* getNodePointer() const
	{
		return node;
	}

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const
	{
		return node->data;
	}

	// �O�u���Z�q�̃I�[�o�[���[�h
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

	// �������Z�q�̃I�[�o�[���[�h
	bool operator==(const ListIterator& it)
	{
		return node == it.node;
	}

	bool operator!=(const ListIterator& it)
	{
		return !(*this == it);
	}
};
