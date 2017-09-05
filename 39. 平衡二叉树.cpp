/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
思路：求二叉树的最大深度和最小深度。注意：求最小深度的时候需要考虑根节点有一个子节点为空的特殊情况。
*/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		int maxDepth = maxTreeDepth(pRoot);
		int minDepth = minTreeDepth(pRoot);
		if (pRoot != NULL && (pRoot->left == NULL || pRoot->right == NULL))
			minDepth = 1;
		if (maxDepth - minDepth <= 1)
			return true;
		else
			return false;
    }
	int maxTreeDepth(TreeNode* pRoot)
    {
		if (pRoot == NULL)
			return 0;
		if (pRoot->left == NULL && pRoot->right == NULL)
			return 1;
		return max(maxTreeDepth(pRoot->left), maxTreeDepth(pRoot->right)) + 1;
    }
	int minTreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		if (pRoot->left == NULL && pRoot->right == NULL)
			return 1;
		int m = minTreeDepth(pRoot->left) + 1;
		int n = minTreeDepth(pRoot->right) + 1;
		m = (m == 1 ? INT_MAX : m);
		n = (n == 1 ? INT_MAX : n);
		return min(m, n);
	}
};