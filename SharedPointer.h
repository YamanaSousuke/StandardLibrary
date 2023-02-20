#pragma once

template<typename T>
class MySharedPointer
{
public:
	// �R���X�g���N�^�[
	MySharedPointer()
	{
		count = new int(-1);
	}

	// �����L��R���X�g���N�^�[
	explicit MySharedPointer(T* data)
	{
		count = new int(1);
		this->data = data;
	}

	// �f�X�g���N�^�[
	~MySharedPointer()
	{
		// �Ō�̈�Ȃ̂Ŕj������
		if (use_count() == 1) {
			delete count;
			delete data;
		}
		// �Q�ƃJ�E���g�����j������
		else if (use_count() == -1) {
			delete count;
		}
		// �܂��c���Ă���̂ŁA�Q�ƃJ�E���g�����炷
		else {
			set_count(use_count() - 1);
		}
	}

	// ������Z�q�̃I�[�o�[���[�h
	MySharedPointer& operator=(const MySharedPointer& other)
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

	// �A�h���X���Z�q�̃I�[�o�[���[�h
	T* operator->() const
	{
		return data;
	}

	// �l�C�e�B�u�|�C���^�[�̎擾
	T* get() const
	{
		return data;
	}

	// �Q�ƃJ�E���g�̎擾
	int use_count()
	{
		return *count;
	}

	// ���L���̔j��
	void reset()
	{
		if (data != nullptr) {
			// �Ō�̈�Ȃ̂Ŕj������
			if (*count == 1) {
				delete count;
				delete data;
			}
			// �܂��c���Ă���̂ŁA�Q�ƃJ�E���g�����炷
			else {
				*count -= 1;
				delete data;
			}
		}
	}

	// �Q�ƃJ�E���g�̐ݒ�
	void set_count(int count)
	{
		*(this->count) = count;
	}
private:
	// ���\�[�X
	T* data = nullptr;
	// �Q�ƃJ�E���g
	int* count = nullptr;
};
