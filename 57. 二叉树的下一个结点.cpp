/*
����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
*/

/*
˼·��
���жϸý���Ƿ������������������ڣ�����һ�������������������е������ӽڵ㡣
����Ľ�㲻����������������Ҫ���Ÿ��ڵ�һֱ���ϱ�����ֱ���ҵ�һ���������ڵ�����ӽڵ�Ľ�㡣
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