/*
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬
��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/

/*
˼·��
1������ÿ���ڵ㣬�磺���ƽڵ�A�õ�A1����A1����ڵ�A����
2����������A1->random = A->random->next;
3���������ֳ�ԭ����͸��ƺ������
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