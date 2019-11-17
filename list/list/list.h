#pragma once

#include<iostream>
#include<algorithm>
using namespace std;

template <class T>
struct ListNode
{
	T _date;
	ListNode<T>* _prev;
	ListNode<T>* _next;

	ListNode(const T& value = T())
		:_date(value)
		, _prev(nullptr)
		, _next(nullptr)
	{
	}
};



template <class T, class Ref, class ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	// Ref == T&      ptr == T*
	typedef ListIterator<T, Ref, ptr> Self;

	pNode _node;

	ListIterator (pNode node)
		:_node(node)
	{}

	//可读可写
	Ref operator*()
	{
		return _node->_date;
	}

	ptr operator->()
	{
		return &operator*();
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node.next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return *this;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
	}
};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T, T&, T*> iterator;
	typedef ListIterator<T, const T&,const T*> const_iterator;

	List()
	{
		CreatHead();
	}

	void CreatHead()
	{
		_head = new Node;
		_head->_prev = _head;
		_head->_next = _head;
	}

	void PushBack(const T& value)
	{
		//pNode newNode = new Node(value);
		//pNode tail = _head->_prev;

		//tail->_next = newNode;
		//newNode->_prev = tail;
		//newNode->_next = _head;
		//_head->_prev = newNode;
		Insert(end(), value);
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}

	void PushFront(const T& value)
	{
		Insert(begin(), value);
	}

	void PopBack()
	{
		Erase(--end());
	}

	void PopFront()
	{
		Erase(begin());
	}

	void Insert(iterator pos, const T& value)
	{
		pNode cur = pos._node;
		pNode newNode = new Node(value);
		pNode prev = cur->_prev;
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = cur;
		cur->_prev = newNode;
	}

	iterator Erase(iterator pos)
	{
		//头结点不能删除
		if (pos != end())
		{
			pNode cur = pos._node;
			pNode prev = cur->_prev;
			pNode next = cur->_next;
			delete cur;
			cur = nullptr;
			prev->_next = next;
			next->_prev = prev;
			//更新当前位置的元素
			pos = iterator(next);
		}
		return pos;
	}

	template <class InputIterator>
	List(InputIterator First, InputIterator Last)
	{
		CreatHead();
		while (First != Last)
		{
			PushBack(*First);
			++First;
		}
	}


	void Clear()
	{
		if (Empty())
		{
			pNode cur = _head->_next;
			while (cur != _head)
			{
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}
			cur->_next = _head;
			cur->_prev = _head;
		}
	}

	List(const List<T>& lst)
	{
		CreatHead();
		for (const auto& e : lst)
		{
			PushBack(e);
		}
	}

	List<T>& operator=(List<T> lst)
	{
		//Clear();
		//for (const auto& e : lst)
		//{
		//	PushBack(e);
		//}

		swap(_head, lst._head);
		return *this;
	}

	bool Empty()
	{
		return _head == _head->_next;
	}

	size_t Size()
	{
		size_t sz = 0;
		for (const auto& e : *this)
		{
			sz++;
		}
		return sz;
	}

	~List()
	{
		Clear();
		if (_head)
		{
			delete _head;
			_head = nullptr;
		}
	}

private:
	pNode _head;
};