/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
思路：
先判断该结点是否存在右子树，如果存在，则下一个结点就是它的右子树中的最左子节点。
如果改结点不存在右子树，则需要沿着父节点一直向上遍历，直到找到一个是它父节点的左子节点的结点。
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
		if (pNode == NULL)
			return NULL;
		TreeLinkNode* pNext = NULL;
		if (pNode->right != NULL)
		{
			pNext = pNode->right;
			while (pNext->left != NULL)
				pNext = pNext->left;
		}
		else if (pNode->next != NULL)
		{
			TreeLinkNode* pTmp = pNode;
			while (pTmp)
			{
				if (pTmp->next && pTmp->next->left == pTmp)
				{
					pNext = pTmp->next;
					break;
				}
				else
					pTmp = pTmp->next;
			}
		}
		return pNext;
    }
};