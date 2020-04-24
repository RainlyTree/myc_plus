// write your code here cpp
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int getln(string& m, string& n)
{
	int ms = m.size() + 1, ns = n.size() + 1;
	int dp[20][20];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= m.size(); ++i)
	{
		for (int j = 0; j <= n.size(); ++j)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			if (m[i - 1] == n[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[m.size()][n.size()];
}

int main()
{
	string m, n;
	while (cin >> m >> n)
	{
		cout << getln(m, n) << endl;
	}
	return 0;
}