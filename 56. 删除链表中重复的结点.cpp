/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/

/*
˼·��
����һ��ͷ���pNewHead��ָ��ԭ�����ͷ��㡣
���p�����ж��Ƿ����ظ���㡣
q�����洢���ظ���㡣
*/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		
		int first = -1;
		if (pHead->val == -1)
			first = -2;
		ListNode* pNewHead = new ListNode(first);
		pNewHead->next = pHead;
		
		ListNode* pNode = pNewHead;
		ListNode* q = pNewHead;
		while (pNode != NULL)
		{
			ListNode* p = pNode;
			while (pNode->next && pNode->next->val == pNode->val)
				pNode = pNode->next;
			if (p != pNode)
			{
				pNode = pNode->next;
				ListNode* pTmp = q->next;
				while (pTmp != pNode)
				{
					ListNode* pTmp2 = pTmp->next;
					delete pTmp;
					pTmp = pTmp2;
				}
				q->next = pNode;
			}
			else
			{
				q = pNode;
				pNode = pNode->next;
			}
		}
		q = pNewHead->next;
		delete pNewHead;
		return q;
    }
};