/*
����һ�ö��������жϸö������Ƿ���ƽ���������
*/

/*
˼·����������������Ⱥ���С��ȡ�ע�⣺����С��ȵ�ʱ����Ҫ���Ǹ��ڵ���һ���ӽڵ�Ϊ�յ����������
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