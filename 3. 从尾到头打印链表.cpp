/*
输入一个链表，从尾到头打印链表每个节点的值。
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
思路：利用堆栈，先push进去，然后依次pop取栈顶
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