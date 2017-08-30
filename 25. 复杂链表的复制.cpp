/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
思路：
1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
2、遍历链表，A1->random = A->random->next;
3、将链表拆分成原链表和复制后的链表
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
			return NULL;
		RandomListNode* pNode = pHead;
		while (pNode)
		{
			RandomListNode* pNext = new RandomListNode(pNode->label);
			pNext->next = pNode->next;
			pNode->next = pNext;
			pNode = pNext->next;
		}
		pNode = pHead;
		while (pNode)
		{
			RandomListNode* pNext = pNode->next;
			if (pNode->random)
				pNext->random = pNode->random->next;
			pNode = pNext->next;
		}
		pNode = pHead;
		RandomListNode* pCloneHead = pHead->next;
		while (pNode->next)
		{
			RandomListNode *tmp = pNode->next;
			pNode->next = tmp->next;
			pNode = tmp;
		}
		return pCloneHead;
    }
};