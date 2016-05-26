#ifndef _TEST_
#define _TEST_

#include<iostream>
#include<cassert>
using namespace std;

template<class T>
struct _ListNode
{
	T _data;
	_ListNode<T> *_prev;
	_ListNode<T> *_next;

	_ListNode()
		:_prev(NULL)
		, _next(NULL)
	{}

	_ListNode(const T& data)
		:_data(data)
		, _prev(NULL)
		, _next(NULL)
	{}

};

template<class T>
class _ListIterator
{
public:
	typedef _ListIterator <T> Iterator;
	typedef T ValueType;
	typedef T *Pointer;
	typedef T &Reference;  
	typedef _ListNode <T>* LinkType;
	LinkType _node;

	_ListIterator(LinkType node = NULL)
	: _node(node)
	{}

	bool operator==(const _ListIterator<T> &x)const
	{
		return _node == x._node;
	}


	bool operator!=(const _ListIterator<T> &x)const
	{
		return _node != x._node;
	}

	Reference operator *() const    
	{
		return _node->_data; 
	}

	Pointer operator ->() const   
	{
		return &(operator *());
	}


	_ListIterator<T >& operator++()   
	{
		_node = _node->_next;
		return *this;
	}

	_ListIterator<T > operator++(int)
	{
		_ListIterator<T > tmp(_node);
		_node = _node->_next;
		return tmp;
	}

	_ListIterator<T >& operator--()    
	{ 
		_node = _node->_prev;
		return *this;
	}

	_ListIterator<T >& operator--(int)    
	{
		_ListIterator<T > tmp(_node); 
		_node = _node->_prev;
		return tmp;
	}

};


# endif

//≤‚ ‘≤ø∑÷

#include"test.h"
#include<vector>
#include<algorithm>
#include<string>
#include<list>

//vector≤‚ ‘
void Test1()
{
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);

	vector<int>::iterator t1 = v1.begin();

	for (; t1 != v1.end(); ++t1)
	{
		cout << *t1 << endl;

	}

	sort(v1.begin(), v1.end());

	vector<int>::iterator t2 = v1.begin();

	for (; t2 != v1.end(); ++t2)
	{
		cout << *t2 << endl;

	}

}
//¡¥±Ì≤‚ ‘
void Test2()
{
	list<string> l1;
	l1.push_back("aaa");
	l1.push_back("jjj");
	l1.push_back("zzz");
	l1.push_back("eee");
	l1.push_back("fff");
	l1.push_back("bbb");

	list<string>::iterator t1=l1.begin();
	for (; t1 != l1.end(); ++t1)
	{
		cout << *t1 << endl;
	}

	replace(l1.begin(), l1.end(), "jjj", "zzz");

	list<string>::iterator t2 = l1.begin();
	for (; t2 != l1.end(); ++t2)
	{
		cout << *t2 << endl;
	}
}
//¡¥±Ì∫Õ◊÷∑˚¥Æ≤‚ ‘
void Test3()
{

	list<string> l1;
	l1.push_back("aaa");
	l1.push_back("jjj");
	l1.push_back("zzz");
	l1.push_back("eee");
	l1.push_back("fff");
	l1.push_back("bbb");

	list<string>::iterator t1 = l1.begin();
	for (; t1 != l1.end(); ++t1)
	{
		cout << *t1 << endl;
	}

	t1 = find(l1.begin(), l1.end(), "ff");
	if (t1 != l1.end())
	{
		cout << "success" << endl;
	}
	else
		cout << "fail" << endl;
}

void PrintVector(vector<int> &v1)
{
	vector<int>::iterator t1 = v1.begin();

	for (; t1 != v1.end(); ++t1)
	{
		cout << *t1 << endl;

	}
}
//µ¸¥˙∆˜µƒ ß–ß
void Test4()
{
	vector<int> v1;
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(1);
	PrintVector(v1);
	vector<int>::iterator t1 = v1.begin();
	for (; t1 != v1.end();)
	{
		if (*t1 % 2 == 0)
			v1.erase(t1);
		else
			++t1;
	}
	PrintVector(v1);
}

void PrintList(list<string> l1)
{
	list<string>::iterator t1 = l1.begin();
	for (; t1 != l1.end(); ++t1)
	{
		cout << *t1 << endl;
	}

}

void Test5()
{

	list<string> l1;
	l1.push_back("aaa");
	l1.push_back("jjj");
	l1.push_back("zzz");
	l1.push_back("eee");
	l1.push_back("fff");
	l1.push_back("bbb");
	PrintList(l1);
	list<string>::iterator t1 = l1.begin();
	for (; t1 != l1.end();)
	{
		if (*t1 == "eee")
			t1=l1.erase(t1);
		else
			++t1;
	}
	PrintList(l1);
}

int  main()
{
	Test5();
	return 0;
}