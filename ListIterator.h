#pragma once

// ���X�g�ɗ��p����C�e���[�^�[
template<typename T, typename Node>
class listIterator
{
public:
	
private:
	Node* node = nullptr;

public:
	// �R���X�g���N�^
	listIterator(Node* node = nullptr) : node(node) { }
	// �R�s�[�R���X�g���N�^
	listIterator(const listIterator<T, Node>& copy)
	{
		node = copy.getNodePointer();
	}

	// �f�X�g���N�^
	~listIterator() { }

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

	// �������Z�q�̃I�[�o�[���[�h
	bool operator==(const listIterator& it)
	{
		return node == it.node;
	}

	bool operator!=(const listIterator& it)
	{
		return !(*this == it);
	}
};
