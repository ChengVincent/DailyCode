#ifndef _LIST_S_
#define _LIST_S_

#include<iostream>
using namespace std;


//节点结构体
template<class T>
struct List_S_Node
{
	T _data;
	struct List_S_Node<T>* _next;

	List_S_Node(T data)
		:_data(data)
		,_next(NULL)
	{}

};
//单链表类
template<class T>
class List_S
{
public:
	//无参构造
	List_S()
		:_head(NULL)
	{}

	//有参构造
	List_S(T data)
		:_head(new List_S_Node<T>(data))
	{}

	//后加节点
	void PushBack(T data)
	{
		if (NULL == _head)
		{
			_head = new List_S_Node<T>(data);
			return;
		}

		List_S_Node<T>* cur = _head;
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = new List_S_Node<T>(data);
	}

	//后删节点
	void PopBack()
	{
		//无节点
		if (NULL == _head)
			return;
		//一个节点
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			return;
		}
		//多个节点
		List_S_Node<T>* cur = _head;
		List_S_Node<T>* pCur =NULL;
		while (cur->_next)
		{
			pCur = cur;
			cur = cur->_next;
		}
		delete cur;
		pCur->_next = NULL;
	}

	//前加节点
	void PushFront(T data)
	{
		//一个节点
		if (NULL == _head)
		{
			_head = new List_S_Node<T>(data);
			return;
		}

		List_S_Node<T>* cur = _head;
		_head = new List_S_Node<T>(data);
		_head->_next = cur;
	}

	//前删节点
	void PopFront()
	{
		//无节点
		if (NULL == _head)
			return;
		//一个节点
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			return;
		}

		List_S_Node<T>* cur = _head->_next;
		delete _head;
		_head = cur;
	}

	//打印节点
	void PrintList()
	{
		List_S_Node<T>* cur = _head;
		while (cur)
		{
			cout << cur->_data << "->";
			cur = cur->_next;
		}
		cout << "NULL" << endl;
	}

	//清除链表
	void DeleteList()
	{
		//无节点
		if (NULL == _head)
			return;
		//一个节点
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			return;
		}
		//多个节点
		List_S_Node<T>* cur=_head;
		List_S_Node<T>* delPos = NULL;
		while (cur->_next)
		{
			delPos = cur;
			cur = cur->_next;
			delete  delPos;
		}
		delete cur;
		_head = NULL;
	}

	//逆转链表
	void ReverseList()
	{
		//0/1个节点不用逆转
		if (NULL == _head || NULL == _head->_next)
			return;

		List_S_Node<T>* newHead = NULL;
		while (_head)
		{
			List_S_Node<T>* temp = _head;
			_head = _head->_next;
			temp->_next = newHead;
			newHead = temp;
		}
		_head = newHead;
	}

	//逆向打印一个链表
	void FromTailToHead()
	{
		_FromTailToHead(_head);
		cout << "NULL" << endl;
	}

	void _FromTailToHead(List_S_Node<T>* node)
	{
		if (node)
		{
			_FromTailToHead(node->_next);
			cout << node->_data << "->";
		}
	}

	~List_S()
	{
		DeleteList();
	}
private:
	List_S_Node<T>* _head;
};

#endif

