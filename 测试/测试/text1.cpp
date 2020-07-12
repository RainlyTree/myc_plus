#include<iostream>
#include<new>
#include<cstddef>
#include<cstdlib>
#include<climits>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> rightSideView(TreeNode* root) {
	vector<int> fin;
	queue<TreeNode*> right_que;
	right_que.push(root);
	int num = 1;
	while (!right_que.empty())
	{
		TreeNode* ro = right_que.front();
		if (ro->left)
		{
			right_que.push(root->left);
		}
		if (ro->right)
		{
			right_que.push(root->right);
		}
		if (num == 1)
		{
			fin.push_back(ro->val);
			right_que.pop();
			num = right_que.size();
		}
		else
		{
			right_que.pop();
			--num;
		}
	}


	return fin;
}

int trailingZeroes(int n) {
	int num2 = 0;
	int num5 = 0;
	for (int i = 2; i <= n; ++i)
	{
		int tmp = i;
		while (tmp % 2 == 0)
		{
			++num2;
			tmp /= 2;
		}
		while (tmp % 5 == 0)
		{
			++num5;
			tmp /= 5;
		}
	}
	return min(num2, num5);
}

vector<int> minSubsequence(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int len = nums.size();
	if (len <= 1)
		return nums;
	vector<int> fin;
	int sum = 0;
	int lsum = 0;
	for (int i = 0; i < len; ++i)
	{
		sum += nums[i];
	}
	for (int i = len - 1; i >= 0; --i)
	{
		sum -= nums[i];
		lsum += nums[i];
		if (sum >= lsum)
		{
			fin.push_back(nums[i]);
		}
	}
	return fin;
}

#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	set<char> fin;
	for (int i = 0; i < s2.size(); ++i)
	{
		fin.insert(s2[i]);
	}
	string use;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (fin.count(s1[i]) == 1)
			continue;
		use += s1[i];
	}
	s1 = use;
	return 0;
}