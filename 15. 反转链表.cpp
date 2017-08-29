/*
����һ��������ת�����������������Ԫ�ء�
*/

/*
˼·��
(1)->2->3->4->5
(2->1)->3->4->5
(3->2->1)->4->5
(4->3->2->1)->5
(5->4->3->2->1)
pLastָ��ǰ���Ѿ���ת��ɵ�ͷ���
pNextָ����һ����Ҫ��ת�Ľ��
��pNextָ��(2->1)->3->4->5�е�3ʱ��pLast��ʱָ��2��pHead����һ������ʱָ�����3
ListNode* tmp = pNext->next; // ����3����һ����㣬��4
pNext->next = pLast;         // 3��һ�����ָ��pLast����3ָ��2
pHead->next = tmp;           // pHead����һ�����ָ��4
pLast = pNext;               // ����pLastΪ3
pNext = tmp;                 // pNextָ����һ�����
// ������η�ת����(3->2->1)->4->5
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