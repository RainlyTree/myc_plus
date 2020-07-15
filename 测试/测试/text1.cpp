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
#include<thread>
using namespace std;

int numIdenticalPairs(vector<int>& nums) {
	unordered_map<int, int> fin;
	for (int i = 0; i < nums.size(); ++i)
	{
		fin[nums[i]]++;
	}
	int sum = 0;
	auto it = fin.begin();
	while (it != fin.end())
	{
		if (it->second > 1)
		{
			sum += (1 + it->second) * it->second / 2;
		}
		++it;
	}
	return sum;
}

int convertInteger(int A, int B) {
	int num = 0;
	while (A && B)
	{
		if ((A & 1) != (B & 1))
		{
			++num;
		}
		A = A >> 1;
		B = B >> 1;
	}
	while (A)
	{
		A = A & (A - 1);
		++num;
	}
	while (B)
	{
		B = B & (B - 1);
		++num;
	}
	return num;
}

int main()
{
	convertInteger(15, 29);
	return 0;
}