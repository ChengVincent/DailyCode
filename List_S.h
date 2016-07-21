#ifndef _LIST_S_
#define _LIST_S_

#include<iostream>
using namespace std;


//�ڵ�ṹ��
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
//��������
template<class T>
class List_S
{
public:
	//�޲ι���
	List_S()
		:_head(NULL)
	{}

	//�вι���
	List_S(T data)
		:_head(new List_S_Node<T>(data))
	{}

	//��ӽڵ�
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

	//��ɾ�ڵ�
	void PopBack()
	{
		//�޽ڵ�
		if (NULL == _head)
			return;
		//һ���ڵ�
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			return;
		}
		//����ڵ�
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

	//ǰ�ӽڵ�
	void PushFront(T data)
	{
		//һ���ڵ�
		if (NULL == _head)
		{
			_head = new List_S_Node<T>(data);
			return;
		}

		List_S_Node<T>* cur = _head;
		_head = new List_S_Node<T>(data);
		_head->_next = cur;
	}

	//ǰɾ�ڵ�
	void PopFront()
	{
		//�޽ڵ�
		if (NULL == _head)
			return;
		//һ���ڵ�
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

	//��ӡ�ڵ�
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

	//�������
	void DeleteList()
	{
		//�޽ڵ�
		if (NULL == _head)
			return;
		//һ���ڵ�
		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			return;
		}
		//����ڵ�
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

	//��ת����
	void ReverseList()
	{
		//0/1���ڵ㲻����ת
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

	//�����ӡһ������
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

