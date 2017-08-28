/*
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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
˼·��
1. ǰ��������еĵ�һ�������Ǹ�����ֵ
2. ������������ҵ�������ֵ
3. ����������������������
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
		
		// ������������ҵ�������ֵ
		vector<int>::iterator iter = startIn;
		while (*iter != root->val)
		{
			++iter;
		}
		
		int len = iter - startIn;
		if (len > 0)
			root->left = ConstructCore(startPre + 1, startPre + len, startIn, iter - 1); // ����������
		if (iter < endIn)
			root->right = ConstructCore(startPre + len + 1, endPre, iter + 1, endIn);    // ����������
		return root;
	}
};