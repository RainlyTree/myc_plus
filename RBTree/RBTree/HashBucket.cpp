#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
using namespace std;

template <class V>
struct HashNode
{
	HashNode<V>* _next;
	V _data;

	HashNode(const V& data)
		:_data(data)
		,_next(nullptr)
	{}
};

template <class K, class V, class KeyOfValue, class HFun>
class HashBucket;


template<class K, class V, class KeyOfValue, class HFun>
struct HIterator
{

	template <class K, class V, class KeyOfValue, class HFun>
	friend class HashBucket;

	typedef HashNode<V> Node;
	typedef Node* pNode;
	typedef HashBucket<K, V, KeyOfValue, HFun> htable;
 	typedef HIterator<K, V, KeyOfValue, HFun> Slef;

	pNode _node;
	htable* _ht;

	HIterator(pNode node, htable* ht)
		:_node(node)
		,_ht(ht)
	{}

	V& operator*()
	{
		return _node->_data;
	}

	V& operator->()
	{
		return *_node->_data;
	}

	bool operator!=(const Slef& it)
	{
		return _node != it._node;
	}

	Slef operator++()
	{
		if (_node->_next)
			_node = _node->_next;
		else
		{
			//找到下一个哈希表下一个非空链表的头节点
			//计算节点在表中的位置
			KeyOfValue kov;
			HFun hf;
			//int idx = kov(_node->_data) % _ht->getTableSize();
			//友元类
			int idx = hf(kov(_node->_data)) % _ht->_table.size();
			++idx;
			for (; idx < _ht->_table.size(); ++idx)
			{
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
			}
			//有可能后面都为空的
			if (idx == _ht->_table.size())
				_node = nullptr;
		}
		return *this;
	}

};


//提供的HFun将其他类型转换成int型
template <class K, class V, class KeyOfValue, class HFun>
class HashBucket
{
public:
	typedef HashNode<V> Node;
	typedef Node* pNode;

	typedef HIterator<K, V, KeyOfValue, HFun> iterator;

	iterator begin()
	{
		//找到第一个非空
		for (int i = 0; i < _table.size(); ++i)
		{
			if (_table[i])
				return iterator(_table[i], this);
		}
		return end();
	}

	iterator end()
	{
		return iterator(nullptr, this);
	}

	bool insert(const V& data)
	{
		//检查容量
		checkCapacity();

		//搜索key是否存在

		//计算位置
		KeyOfValue kov;
		HFun hf;
		int idx = hf(kov(data)) % _table.size();
		pNode cur = _table[idx];
		while (cur)
		{
			if (hf(kov(cur->_data)) == kov(data))
				return false;
			cur = cur->_next;
		}
		//插入,头插
		cur = new Node(data);
		cur->_next = _table[idx];
		_table[idx] = cur;

		++_size;
		return true;

	}

	//素数表：降低哈希冲突
	size_t getPrime(size_t sum);


	void checkCapacity()
	{
		//负载因子：可以大一些
		if (_size == _table.size())
		{
			size_t newC = _table.size() == 0 ? 10 : 2 * _table.size();
			//创建新的vector
			vector<pNode> newT;
			newT.resize(newC);
			KeyOfValue kov;
			HFun hf;
			//遍历旧表，重新挂载新的表中
			for (int i = 0; i < _table.size(); ++i)
			{
				//获取当前位置的链表头
				pNode = cur = _table[i];
				//遍历每个节点，重新计算位置
				while (cur)
				{
					pNode next = cur->_next;
					
					int idx = hf(kov(cur->_data)) % newT.size();
					cur->_next = newT[idx];
					newT[idx] = cur;
					cur = next;
				}

				_table[i] = nullptr;
			}
			swap(_table, newT);
		}
	}

	bool erase(const K& key)
	{
		KeyOfValue kov;
		int idx = kov(key) % _table.size();
		pNode parent = nullptr;
		pNode cur = _table[idx];
		while (cur)
		{
			parent = cur;
			if (kov(cur->key) == kov(key))
				break;
			cur = cur->_next;
		}
		if (cur == nullptr)
			return false;
		parent->_next = cur->_next;
		cur = nullptr;
		return true;
	}

	size_t getTableSize()
	{
		return _table.size();
	}

	pNode find(const K& key)
	{
		//计算位置
		KeyOfValue kov;
		int idx = kov(key) % _table.size();
		pNode cur = _table[idx];
		while (cur)
		{
			if (kov(cur->key) == kov(key))
				return cur;
			cur = cur->_next;
		}

		return nullptr;
	}

private:
	vector<pNode> _table;
	size_t _size = 0;
};

template<class K>
struct KeyOfValue
{
	const K& operator()(const K& key)
	{
		return key;
	}
};


template<class K>
struct HashFun
{
	//计算哈希值的()重载函数
	int operator()(const K& key)
	{
		return key;
	}
};

template<>
struct HashFun<string>
{
	//计算哈希值的()重载函数
	int hash = 0;
	int operator()(const string& key)
	{
		for(const auto& ch : key)
			hash = hash * 131 + ch;
		return hash;
	}
};

template<class K,class V, class HFun = HashFun<K>>
class UnorderedMap
{
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& data)
		{
			return data.first;
		}
	};

public:
	typedef typename HashBucket<K, pair<K, V>, MapKeyOfValue, HFun>::iterator iterator;
	bool insert(const pair<K, V>& data)
	{
		return _hb.insert(data);
	}

	iterator begin()
	{
		return _hb.begin();
	}

	iterator end()
	{
		return _hb.end();
	}

private:
	HashBucket<K, pair<K, V>, MapKeyOfValue, HFun> _hb;
};

template<class K, class HFun = HashFun<K>>
class UnorderedSet
{
	struct SetKeyOfValue
	{
		const K& operator()(const K& data)
		{
			return data.first;
		}
	};


public:
	bool insert(const K& data)
	{
		return _hb.insert(data);
	}



	typedef typename HashBucket<K, K, SetKeyOfValue, HFun>::iterator iterator;

	iterator begin()
	{
		return _hb.begin();
	}

	iterator end()
	{
		return _hb.end();
	}

private:
	HashBucket<K, K, SetKeyOfValue, HFun> _hb;
};


int main()
{
	return 0;
}