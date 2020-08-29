#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num = 0;
	//while (cin >> num)
	{
		vector<int> arr(1000000 , 0);
		arr[1000000 - 1] = 1000000
		if (num < 2)
		{
			cout << 0 << endl;
			//continue;
		}
		for (int i = 0; i < num; ++i)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int sum = 0;
		for (int i = 0; i < num - 1; ++i)
		{
			sum = sum * 2 + arr[i + 1] - arr[i];
		}
		cout << sum << endl;
	}
	return 0;
}