/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/*
思路：
构造一个头结点pNewHead，指向原链表的头结点。
结点p用来判断是否有重复结点。
q用来存储非重复结点。
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