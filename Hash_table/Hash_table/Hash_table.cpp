#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

enum State
{
	EXIST,
	DELETE,
	EMPTY
};

template <class K, class V>
struct Node
{
	pair<K, V> _value;
	State _state;
};

template <class K, class V>
class HashTable
{
public:
	typedef Node<K, V> Node;
	HashTable(size_t N = 10)
	{
		_table.resize(N);
		for (int i = 0; i < N; ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	bool insert(const pair<K, V>& value)
	{
		//检查容量
		CheckCapcity();

		int idx = value.first % _table.size();
		while (_table[idx]._state = EXIST)
		{
			if (_table[idx]._value.first == value.first)
				return false;
			++idx;
			if (idx == _table.size())
				idx = 0;
		}
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}

	void CheckCapcity()
	{
		//超过负载因子，需要增容
		if (_size * 10 / _table.size() >= 7)
		{
			int newC = _table.size() * 2;
			//增容：不能直接resize, 元素在新表中可能发生变化

			//建立新表，
			HashTable<K, V> newHt(newC);
			for (int i = 0; i < _table.size(); ++i)
			{
				if (_table[i]._state == EXIST)
				{
					newHt.insert(_table[i]._value);
				}
			}
			_table.swap(newHt._table);
		}
	}

	Node* find(const K& key)
	{
		int idx = key % _table.size();
		while (_table[idx].state != EMPTY)
		{
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
				return &_table[idx];
			++idx;
			//是否越界
			if (idx == _table.size())
				idx = 0;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			node->_state == DELETE;
			--_size;
			return true;
		}
		return false;
	}

	void hashTablePrint()
	{
		for (int i = 0; i < _table.size(); ++i)
		{
			if (_table[i]._state == EXIST)
				cout << _table[i]._value.first << "-->" << _table[i]._value.second << endl;
		}
	}


private:
	vector<Node> _table;
	size_t _size;
};



int main()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(3);
	arr.resize(1);
	cout << arr.size() << endl;
	return 0;
}