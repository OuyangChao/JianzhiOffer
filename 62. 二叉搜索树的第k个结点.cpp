/*
����һ�Ŷ��������������ҳ����еĵ�k��Ľ�㡣
���磬 5 / \ 3 7 /\ /\ 2 4 6 8 �У��������ֵ��С˳�����������ֵΪ4��
*/

/*
˼·���������
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
		return KthNodeCore(pRoot, k);
    }
	TreeNode* KthNodeCore(TreeNode* pRoot, int &k)
	{
		if (pRoot == NULL)
			return NULL;
		TreeNode* target = NULL;
		if (pRoot->left)
			target = KthNodeCore(pRoot->left, k);
		if (target == NULL)
		{
			if (k == 1)
				target = pRoot;
			--k;
		}
		if (target == NULL && pRoot->right != NULL)
			target = KthNodeCore(pRoot->right, k);
		return target;
	}
};