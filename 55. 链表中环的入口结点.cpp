/*
一个链表中包含环，请找出该链表的环的入口结点。
*/

/*
思路：先计算出环中结点个数n，双指针，一个指针先走n步，另一个指针从头开始走，相遇的点就是入口。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		ListNode* pMeetNode = MeetingNode(pHead);
		if (pMeetNode == NULL)
			return NULL;
		int nodesInLoop = 1;
		ListNode* pNode1 = pMeetNode;
		while (pNode1->next != pMeetNode)
		{
			pNode1 = pNode1->next;
			++nodesInLoop;
		}
		pNode1 = pHead;
		for (int i = 0; i < nodesInLoop; ++i)
			pNode1 = pNode1->next;
		ListNode* pNode2 = pHead;
		while (pNode1 != pNode2)
		{
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
    }
	ListNode* MeetingNode(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* pSlow = pHead;
		ListNode* pFast = pSlow->next;
		while (pSlow != NULL && pFast != NULL)
		{
			if (pFast == pSlow)
				return pFast;
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != NULL)
				pFast = pFast->next;
		}
		return NULL;
	}
};