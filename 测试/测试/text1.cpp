#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{
		vector<int> vec;
		for (int i = 0; i < num; ++i)
		{
			int tmp = 0;
			cin >> tmp;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end());
		int min = 0;
		cin >> min;
		int index = 0;
		while (min)
		{
			++index;
			if (vec[index - 1] != vec[index])
				--min;
		}
		cout << vec[index] << endl;
	}
	return 0;
}