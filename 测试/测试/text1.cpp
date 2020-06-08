#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string countAndSay(int n) {
	if (n == 1)
		return "1";
	string pre = countAndSay(n - 1), ans = "";
	int count = 1;
	for (int i = 0; i < pre.size(); ++i)
	{
		if (i + 1 < pre.size() && pre[i] == pre[i + 1])
		{
			++count;
		}
		else
		{
			char tmp = '0' + count;
			ans += tmp;
			ans += pre[i];
			count = 1;
		}
	}
	return ans;
}

int main()
{
	countAndSay(3);
	return 0;
}