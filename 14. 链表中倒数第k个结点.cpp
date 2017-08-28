/*
输入一个链表，输出该链表中倒数第k个结点。
*/

/*
思路：两个指针p1,p2，p2先走k步，然后p1,p2同时走，p2走完时p1正好在倒数第k个结点处。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		int t = 0;
		while (p2 != NULL)
		{
			p2 = p2->next;
			if (++t == k)
				break;
		}
		if (t != k)
			return NULL;
		while (p2 != NULL)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
    }
};