#ifndef _SEQLIST_D_H_
#define _SEQLIST_D_H_

#include<iostream>
#include<cassert>
#include<malloc.h>
using namespace std;

//Ĭ�ϳ�ʼ����
#define DEFAULT_CAPACITY 3

template<class T>
class SeqList_D
{
public:
	//�޲ι���
	SeqList_D()
	:_array(new T[3])
	, _size(0)
	, _capacity(3)
	{}

	//�в������캯��
	SeqList_D(T value)
	:_array(new T[3])
	, _size(1)
	, _capacity(3)
	{
		_array[0] = value;
	}

	//β��׷������
	void PushBack(T value)
	{
		CheckCapacity();
		_array[_size] = value;
		_size++;
	}

	//��ӡ����
	void PrintSeqList_D()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << endl;
		}
	}

	//����һ������
	void Insert(size_t position,T value)
	{
		CheckCapacity();
		if (position<1 || position>_size)
		{
			cout << "��λ�ò��ܲ�������" << endl;
			return;
		}
		for (size_t i = _size; i >= position; --i)
		{
			_array[i] = _array[i-1];
		}
		_array[position-1] = value;
		_size++;
	}

	//�������
	void CheckCapacity()
	{
		if (_capacity == _size)
		{
			_array = (T*)realloc(_array, sizeof(T)*_capacity * 2);
			if (_array == NULL)//realloc�����ڴ�ʧ�ܷ��ؿ�
			{
				cout << "�����ڴ�ʧ��" << endl;
				return;
			}
			_capacity *= 2;
		}
	}

	//����λ��ɾ��
	void RemovePos(size_t position)
	{
		if (_size == 0)
			return;
		if (position > _size || position < 1)
			return;
		for (size_t i = position - 1; i < _size-1; ++i)
		{
			_array[i] = _array[i + 1];
		}
		_size--;
	}

	//��������ɾ����һ��ƥ������
	void RemoveData(T value)
	{
		if (_size == 0)
			return;
		for (size_t i = 0; i < _size; ++i)
		{
			if (_array[i] == value)
			{
				RemovePos(i + 1);
				return;
			}
		}
		
	}


     //����λ��ɾ������ƥ������
	void RomoveAllData(T value)
	{
		if (_size == 0)
			return;
		for (size_t i = 0; i < _size; ++i)
		{
			if (_array[i] == value)
			{
				RemovePos(i + 1);
				i -= 1;
				//ɾ��������������䵱ǰλ�ã������ж�
			}
		}
	}

	//ð������
	void BubbleSort()
	{
		if (_size <= 1)
			return;
		for (int i = _size; i >=0; --i)
		{
			for (int j = 0; j < i;++j)
			if (_array[j] < _array[j + 1])
				swap(_array[j], _array[j + 1]);
		}
	}

	//��������
	~SeqList_D()
	{
		delete[] _array;
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};


#endif