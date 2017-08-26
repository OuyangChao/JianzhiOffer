/*
����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ��
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/*
˼·�����ö�ջ����push��ȥ��Ȼ������popȡջ��
*/

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> vec_val;
        stack<ListNode *> stkList;
		ListNode* pnode = head;
		while (pnode != NULL)
		{
			stkList.push(pnode);
			pnode = pnode->next;
		}
		
		while (!stkList.empty())
		{
			vec_val.push_back(stkList.top()->val);
			stkList.pop();
		}
		
		return vec_val;
    }
};