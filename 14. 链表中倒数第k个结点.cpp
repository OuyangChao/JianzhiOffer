/*
����һ����������������е�����k����㡣
*/

/*
˼·������ָ��p1,p2��p2����k����Ȼ��p1,p2ͬʱ�ߣ�p2����ʱp1�����ڵ�����k����㴦��
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