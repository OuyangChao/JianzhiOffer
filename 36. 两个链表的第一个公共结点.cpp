/*
�������������ҳ����ǵĵ�һ��������㡣
*/

/*
˼·���ȼ�����������ĳ��ȣ����������߼�����Ȼ�������ʼ�ߣ���һ����ͬ�Ľ����ǵ�һ���������
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		int len1 = getLength(pHead1);
		int len2 = getLength(pHead2);
		ListNode* pNode1 = pHead1;
		ListNode* pNode2 = pHead2;
		if (len1 > len2)
		{
			int i = len1 - len2;
			while (i--)
			{
				pNode1 = pNode1->next;
			}
		}
		else if (len2 > len1)
		{
			int i = len2 - len1;
			while (i--)
			{
				pNode2 = pNode2->next;
			}
		}
		while (pNode1)
		{
			if (pNode1 == pNode2)
				break;
			pNode1 = pNode1->next;
			pNode2 = pNode2->next;
		}
		return pNode1;
    }
	int getLength(ListNode* pHead)
	{
		ListNode* pNode = pHead;
		int len = 0;
		while (pNode)
		{
			pNode = pNode->next;
			++len;
		}
		return len;
	}
};