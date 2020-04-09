#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

template <class T>
struct BSTNode
{
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _value;

	BSTNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_value(value)
	{}
};

template <class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	pNode find(const T& value)
	{
		pNode cur = _root;
		while (cur)
		{
			if (cur->_value == value)
				return cur;
			else if (cur->_value > value)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return cur;
	}

	bool insert(const T& value)
	{
		if (_root == nullptr)
		{
			_root = new Node(value);
			return true;
		}

		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value == value)
				return false;
			else if (cur->_value > value)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(value);
		if (parent->_value > value)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	bool erase(const T& value)
	{
		if (_root == nullptr)
			return false;
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_value == value)
				break;
			else if (cur->_value > value)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}
		//判断节点是否存在
		if (cur == nullptr)
			return false;
		
		//要删除的元素 的左边没有任何元素的情况
		if (cur->_left == nullptr)
		{
			//删除位置不为根
			if (cur != _root)
			{
				//更新父节点
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else
				_root = cur->_right;
			delete cur;
			cur = nullptr;
		}
		//要删除的元素 的右边没有任何元素的情况
		else if (cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else
				_root = cur->_left;
			delete cur;
			cur = nullptr;
		}
		//要删除的元素 左右都有元素的情况
		else
		{
			//找左子树的最右节点
			pNode pNext = cur->_left;
			pNode parent = cur;
			while (pNext->_right)
			{
				parent = pNext;
				pNext = pNext->_right;
			}
			//交换删除值与当前节点
			cur->_value = pNext->_value;
			if (parent->_left == pNext)
				parent->_left = pNext->_left;
			else
				parent->_right = pNext->_left;
			//删除最后的节点
			delete pNext;
			pNext = nullptr;
		}
		return true;
	}


	void _inOrder(pNode _root)
	{
		if (_root)
		{
			_inOrder(_root->_left);
			cout << _root->_value << " ";
			_inOrder(_root->_right);
		}
	}

	void inOrder()
	{
		_inOrder(_root);
	}

private:
	BSTNode<T>* _root = nullptr;
};

void test()
{
	BSTree<int> bst;
	cout << bst.insert(100) << endl;
	cout << bst.insert(1) << endl;
	cout << bst.insert(2) << endl;
	cout << bst.insert(10) << endl;
	cout << bst.insert(24) << endl;
	cout << bst.insert(4) << endl;
	bst.inOrder();
}
int main()
{
	test();
	return 0;
}