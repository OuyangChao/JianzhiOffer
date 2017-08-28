/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*
思路：
1. 前序遍历序列的第一个数字是根结点的值
2. 在中序遍历中找到根结点的值
3. 构建左子树，构建右子树
*/
 
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		return ConstructCore(pre.begin(), pre.end() - 1, vin.begin(), vin.end() - 1);
    }
	
	TreeNode* ConstructCore(vector<int>::iterator startPre, vector<int>::iterator endPre, vector<int>::iterator startIn, vector<int>::iterator endIn)
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->val = *startPre;
		root->left = root->right = NULL;
		if (startPre == endPre)
			return root;
		
		// 在中序遍历中找到根结点的值
		vector<int>::iterator iter = startIn;
		while (*iter != root->val)
		{
			++iter;
		}
		
		int len = iter - startIn;
		if (len > 0)
			root->left = ConstructCore(startPre + 1, startPre + len, startIn, iter - 1); // 构建左子树
		if (iter < endIn)
			root->right = ConstructCore(startPre + len + 1, endPre, iter + 1, endIn);    // 构建右子树
		return root;
	}
};