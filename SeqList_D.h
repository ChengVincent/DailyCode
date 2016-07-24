#ifndef _SEQLIST_D_H_
#define _SEQLIST_D_H_

#include<iostream>
#include<cassert>
#include<malloc.h>
using namespace std;

//默认初始容量
#define DEFAULT_CAPACITY 3

template<class T>
class SeqList_D
{
public:
	//无参构造
	SeqList_D()
	:_array(new T[3])
	, _size(0)
	, _capacity(3)
	{}

	//有参数构造函数
	SeqList_D(T value)
	:_array(new T[3])
	, _size(1)
	, _capacity(3)
	{
		_array[0] = value;
	}

	//尾部追加数据
	void PushBack(T value)
	{
		CheckCapacity();
		_array[_size] = value;
		_size++;
	}

	//打印数据
	void PrintSeqList_D()
	{
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _array[i] << endl;
		}
	}

	//插入一个数据
	void Insert(size_t position,T value)
	{
		CheckCapacity();
		if (position<1 || position>_size)
		{
			cout << "该位置不能插入数据" << endl;
			return;
		}
		for (size_t i = _size; i >= position; --i)
		{
			_array[i] = _array[i-1];
		}
		_array[position-1] = value;
		_size++;
	}

	//检查容量
	void CheckCapacity()
	{
		if (_capacity == _size)
		{
			_array = (T*)realloc(_array, sizeof(T)*_capacity * 2);
			if (_array == NULL)//realloc申请内存失败返回空
			{
				cout << "申请内存失败" << endl;
				return;
			}
			_capacity *= 2;
		}
	}

	//按照位置删除
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

	//按照数据删除第一个匹配数据
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


     //按照位置删除所有匹配数据
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
				//删除后后面的数据填充当前位置，需作判断
			}
		}
	}

	//冒泡排序
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

	//析构函数
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