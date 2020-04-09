#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

template <class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _value;

	//平衡因子
	int _bf;

	AVLNode(const T& value = T())
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_value(value)
		,_bf(0)
	{}
};

template <class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		if(subLR)
			subLR->_parent = parent;

		if (parent != _root)
		{
			pNode gparent = parent->_parent;
			if (gparent->_left == parent)
				gparent->_left = subL;
			else
				gparent->_right = subL;
			subL->_parent = gparent;
		}
		else
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		
		parent->_parent = subL;

		//更新平衡因子
		subL->_bf = parent->_bf = 0;
	}


	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;

		if (subRL)
			subRL->_parent = parent;

		if (parent != _root)
		{
			pNode gparent = parent->_parent;
			subR->_parent = gparent;
			if (gparent->_left == parent)
				gparent->_left = subR;
			else
				gparent->_right = subR;
		}
		else
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;

		subR->_bf = parent->_bf = 0;
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
		cur->_parent = parent;

		//更新平衡因子
		while (parent)
		{
			//左边高度增加
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;
			//判断平衡因子
			if (parent->_bf == 0)
				break;
			else if (abs(parent->_bf) == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//进行旋转
				//右边的右边高
				if (parent->_bf == 2 && cur->_bf == 1)
					RotateL(parent);
				//左边的左边高
				else if (parent->_bf == -2 && cur->_bf == -1)
					RotateR(parent);
				//其他情况(左边的右边高  右边的左边高  )
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					int tmp = cur->_right->_bf;
					RotateL(cur);
					RotateR(parent);
					if(tmp == 1)
						cur->_bf = -1;
					if (tmp == -1)
						parent->_bf = 1;
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					int tmp = cur->_left->_bf;
					RotateR(cur);
					RotateL(parent);
					if(tmp == -1)
						cur->_bf = 1;
					if (tmp == 1)
						parent->_bf = -1;
				}

				break;
			}
			else
			{
				cout << "构建树错误" << endl;
				return false;
			}
		}
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
		cout << endl;
	}

	int height(pNode root)
	{
		if (root == nullptr)
			return 0;
		int left = height(root->_left);
		int right = height(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	bool isAVLTree()
	{
		return _isAVLTree(_root);
	}

	bool _isAVLTree(pNode root)
	{
		if (root == nullptr)
			return true;
		int left = height(root->_left);
		int right = height(root->_right);
		if (right - left != root->_bf)
		{
			cout << "节点:" << root->_value << "平衡因子错误" << endl;
			return false;
		}
		//平衡因子绝对值小于2    平衡音字和左右子树高度一致
		return abs(root->_bf) < 2 && _isAVLTree(root->_left)
			&& _isAVLTree(root->_right);
	}

private:
	pNode _root;
};

void test()
{
	AVLTree<int>* avl = new AVLTree<int>();
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		avl->insert(arr[i]);
	}
	avl->inOrder();
	cout << avl->isAVLTree();
}

int main()
{
	test();
	return 0;
}