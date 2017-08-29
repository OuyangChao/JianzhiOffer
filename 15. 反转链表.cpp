/*
输入一个链表，反转链表后，输出链表的所有元素。
*/

/*
思路：
(1)->2->3->4->5
(2->1)->3->4->5
(3->2->1)->4->5
(4->3->2->1)->5
(5->4->3->2->1)
pLast指向前面已经反转完成的头结点
pNext指向下一个需要反转的结点
当pNext指向(2->1)->3->4->5中的3时，pLast此时指向2，pHead的下一个结点此时指向的是3
ListNode* tmp = pNext->next; // 备份3的下一个结点，即4
pNext->next = pLast;         // 3的一个结点指向pLast，即3指向2
pHead->next = tmp;           // pHead的下一个结点指向4
pLast = pNext;               // 更新pLast为3
pNext = tmp;                 // pNext指向下一个结点
// 经过这次反转后变成(3->2->1)->4->5
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		ListNode* pLast = pHead;
		ListNode* pNext = pHead->next;
		while (pNext != NULL)
		{
			ListNode* tmp = pNext->next;
			pNext->next = pLast;
			pHead->next = tmp;
			pLast = pNext;
			pNext = tmp;
		}
		return pLast;
    }
};