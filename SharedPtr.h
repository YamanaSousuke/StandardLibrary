#pragma once

// �w�肳�ꂽ���\�[�X�ւ̏��L�������L����X�}�[�g�|�C���^
template<typename T>
class MySharedPtr
{
public:
	// �f�t�H���g�R���X�g���N�^�[
	MySharedPtr() : data(nullptr) { }

	// �R���X�g���N�^�[
	explicit MySharedPtr(T* data) : data(data)
	{
		count = new int(1);
	}

	// �R�s�[�R���X�g���N�^�[
	MySharedPtr(const MySharedPtr& other)
	{
		if (other.data != nullptr) {
			data = new T();
			data = other.data;
			count = other.count;
			*count += 1;
		}
	}

	// �f�X�g���N�^�[
	~MySharedPtr()
	{
		if (count != nullptr) {
			// �Ō�̏��L��
			if (*count == 1) {
				delete count;
				if (data != nullptr) {
					delete data;
				}
			}
			// �Q�ƃJ�E���g��������
			else {
				*count -= 1;
			}
		}
	}

	// ������Z�q�̃I�[�o�[���[�h
	MySharedPtr& operator=(const MySharedPtr& other)
	{
		// �R�s�[���鑤�̏��L��������
		if (other.data != nullptr) {
			// �R�s�[����鑤�̏��L�����Ȃ�
			if (data == nullptr) {
				data = new T();
				data = other.data;
				count = other.count;
				*count += 1;
				return *this;
			}
			// �R�s�[����鑤�̏��L��������
			else {
				*count -= 1;
				// �R�s�[����鑤�̏��L�����Ō�̏ꍇ�͎Q�ƃJ�E���g�̔j��
				if (*count == 0) {
					delete count;
				}

				// ���\�[�X�ւ̃|�C���^�[�𒣂�ւ���
				data = other.data;
				count = other.count;
				*count += 1;
			}
		}

		return *this;
	}

	// �Ԑډ��Z�q�̃I�[�o�[���[�h
	T& operator*() const
	{
		return *data;
	}

	// �A���[���Z�q�̃I�[�o�[���[�h
	T* operator->() const
	{
		return data;
	}

	// �|�C���^�[�̎擾
	T* get() const
	{
		return data;
	}

	// �Q�ƃJ�E���g�̎擾
	int use_count() const
	{
		return *count;
	}

	// ���L���̔j��
	void reset()
	{
		if (count != nullptr) {
			// �Ō�̈�Ȃ̂Ŕj������
			if (*count == 1) {
				delete count;
				count = nullptr;
				delete data;
				data = nullptr;
			}
			// �܂��c���Ă���̂ŁA�Q�ƃJ�E���g�����炷
			else {
				*count -= 1;
			}
		}
	}

	// ���L����������A�V���ȃ��\�[�X�̏��L����ݒ肷��
	void reset(T* newData)
	{
		if (count != nullptr) {
			// �Ō�̈�Ȃ̂Ŕj������
			if (*count == 1) {
				delete count;
				count = nullptr;
				delete data;
				data = nullptr;
			}
			// �܂��c���Ă���̂ŁA�Q�ƃJ�E���g�����炷
			else {
				*count -= 1;
			}
		}

		data = newData;
		count = new int(1);
	}

private:
	// ���\�[�X
	T* data = nullptr;
	// �Q�ƃJ�E���g
	int* count = nullptr;
};
