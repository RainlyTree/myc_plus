#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<utility>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class V>
struct RBNode
{
	RBNode<V>* _left;
	RBNode<V>* _right;
	RBNode<V>* _parent;
	V _value;
	COLOR _color;

	RBNode(const V& value = V())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template <class V>
struct RBIerator
{
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBIerator<V> Self;
	pNode _node;

	RBIerator(pNode node)
		:_node(node)
	{}

	V& operator*()
	{
		return _node->_value;
	}

	V& operator->()
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		if (_node->_right)
		{
			_node = _node->_right;
			while (_node->_left)
			{
				_node = _node->_left;
			}
		}
		else
		{
			pNode parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if(_node->_right != parent)
				_node = parent;
		}
		return *this;
	}

	Self& operator--()
	{
		if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
			{
				_node = _node->_right;
			}
		}
		else
		{
			pNode parent = _node->_parent;
			while (_node = parent->_left)
			{
				_node = parent;
				parent = parent->_parent;
			}
			if (_node->_left != parent)
				_node = parent;
		}
		return *this;
	}
};

template <class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V> Node;
	typedef Node* pNode;
	typedef RBIerator<V> iterator;

	iterator begin()
	{
		return iterator(_header->_left);
	}

	iterator end()
	{
		return iterator(_header);
	}

	iterator rbegin()
	{
		return iterator(_header->_right);
	}

	iterator rend()
	{
		return iterator(_header);
	}

	RBTree()
	{
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}

	pair<iterator, bool> insert(const V& value)
	{
		//创建根节点
		if (_header->_parent == nullptr)
		{
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return make_pair(iterator(root),true);
		}
		//搜索位置
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		//通过仿函数对象获取V对应的K
		KeyOfValue kov;
		while (cur)
		{
			parent = cur;
			//按照Key值确定位置

			//位置相同插入失败
			if (kov(cur->_value) == kov(value))
				return make_pair(iterator(cur),false);
			else if (kov(cur->_value) > kov(value))
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(value);
		pNode newNode = cur;
		if (kov(parent->_value) > kov(cur->_value))
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;

		//调整和更新(颜色)
		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			//叔叔在右边
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					//需要进行右旋 旋转完结束调整
					RotateR(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
			//叔叔在左边
			else
			{
				pNode uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					//需要进行左旋
					RotateL(gfather);
					gfather->_color = RED;
					parent->_color = BLACK;
					break;
				}
			}
		}

		_header->_parent->_color = BLACK;

		//更新_header->_left , _right;
		_header->_left = leftMost();
		_header->_right = rightMost();

		return make_pair(iterator(newNode), true);
	}

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;

		if (subLR)
			subLR->_parent = parent;

		if (parent != _header->_parent)
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
			_header->_parent = subL;
			subL->_parent = _header;
		}

		parent->_parent = subL;

	}


	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;

		if (subRL)
			subRL->_parent = parent;

		if (parent != _header->_parent)
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
			_header->_parent = subR;
			subR->_parent = _header;
		}
		parent->_parent = subR;
	}

	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_right != nullptr)
		{
			cur = cur->_right;
		}
		return cur;
	}

	bool isRBTree()
	{
		pNode root = _header->_parent;
		if (root == nullptr)
			return ture;
		if (root->_color == RED)
		{
			cout << "根节点必须是黑色的" << endl;
			return false;
		}
		//判断每个路径黑色个数相同
		pNode cur = root;
		int blackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
				++blackCount;
			cur = cur->_right;
		}

		int k = 0;
		return _isRBTree(root, k, blackCount);
	}

	bool _isRBTree(pNode root, int curBlackCount, int totalBlack)
	{

		if (root == nullptr)
			if (curBlackCount != totalBlack)
			{
				cout << "黑色节点个数不同" << endl;
				return false;
			}
			else
				return true;

		if (root->_color == BLACK)
			++curBlackCount;

		pNode parent = root->_parent;
		if (parent && parent->_color == RED && root->_color == RED)
		{
			cout << "有红色连续节点" << endl;
			return false;
		}

		return _isRBTree(root->_left, curBlackCount, totalBlack)
			&& _isRBTree(root->_right, curBlackCount, totalBlack);
	}

private:
	pNode _header;
};

template <class K,class V>
class MyMap
{
	struct MapKeyofValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};
public:
	typedef typename RBTree<K, pair<K, V>, MapKeyofValue>::iterator iterator;

	iterator begin()
	{
		return _rb.begin();
	}

	iterator end()
	{
		return _rb.end();
	}

	iterator rbegin()
	{
		return _rb.rbegin();
	}

	pair<iterator, bool> insert(const pair<K, V>& data)
	{
		return _rb.insert(data);
	}

	V& operator[](const K& key)
	{
		pair<iterator, bool> ret = _rb.insert(make_pair(key, V()));
		iterator it = ret.first;
		return (*it).second;
	}
private:
	RBTree<K, pair<K, V>, MapKeyofValue> _rb;
};

template <class K>
class MySet
{
	struct SetKeyofValue
	{
		const K& operator()(const K& data)
		{
			return data;
		}
	};
public:
	typedef typename RBTree<K, K, SetKeyofValue>::iterator iterator;
	pair<iterator, bool> insert(const K& data)
	{
		return _rb.insert(data);
	}
private:
	RBTree<K, K, SetKeyofValue> _rb;
};

void testMap()
{
	MyMap<int, int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(2, 2));
	mp.insert(make_pair(3, 3));
	mp.insert(make_pair(4, 4));
}

int main()
{
	testMap();
	return 0;
}