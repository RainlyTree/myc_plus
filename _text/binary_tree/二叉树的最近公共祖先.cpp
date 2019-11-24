#define _CRT_SECURE_NO_WARNINGS 1

//Letcode下

//使用栈记录路径的方式
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	void GetPath(TreeNode* root, TreeNode* p, stack<TreeNode*>& pst)
	{
		if (root == NULL)
			return;
		if (root->val != p->val)
		{
			pst.push(root);
			//去左边找他的值
			GetPath(root->left, p, pst);
			//在左边没有找到
			if (pst.top() != p && root->left != NULL)
			{
				pst.pop();
				GetPath(root->right, p, pst);
				if (pst.top() != p && root->right != NULL)
					pst.pop();
			}
			else
			{
				GetPath(root->right, p, pst);
				if (pst.top() != p && root->right != NULL)
					pst.pop();
			}
			return;
		}
		else
		{
			pst.push(p);
		}
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> pst;
		stack<TreeNode*> qst;
		GetPath(root, p, pst);
		GetPath(root, q, qst);
		while (pst.size() > qst.size())
		{
			pst.pop();
		}
		while (pst.size() < qst.size())
		{
			qst.pop();
		}
		while (((pst.top()->val) != (qst.top()->val)))
		{
			qst.pop();
			pst.pop();
		}
		TreeNode* tmp = pst.top();
		return tmp;
	}
};


//用一定的特性
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//如果当前根为空或者当前根为 p 或者 q直接返回根节点
		if (!root || root == p || root == q)
			return root;
		//获取左侧的节点
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		//获取右侧的节点
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		//如果是在根节点的左右 返回跟
		if (left && right) return root;
		//不在根的左右 在跟的同一侧 找在哪一侧
		return left ? left : right;
	}
};