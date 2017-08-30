/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/*
思路：按照中序遍历的顺序进行转换
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
		TreeNode* pLastNodeInList = NULL;
		ConvertNode(pRootOfTree, &pLastNodeInList);
		
		TreeNode* pHeadOfList = pLastNodeInList;
		while (pHeadOfList != NULL && pHeadOfList->left != NULL)
			pHeadOfList = pHeadOfList->left;
		return pHeadOfList;
    }
	void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList)
	{
		if (pNode == NULL)
			return;
		TreeNode* pCurrent = pNode;
		if (pCurrent->left != NULL)
			ConvertNode(pCurrent->left, pLastNodeInList);
		
		pCurrent->left = *pLastNodeInList;
		if (*pLastNodeInList != NULL)
			(*pLastNodeInList)->right = pCurrent;
		*pLastNodeInList = pCurrent;
		
		if (pCurrent->right != NULL)
			ConvertNode(pCurrent->right, pLastNodeInList);
	}
};