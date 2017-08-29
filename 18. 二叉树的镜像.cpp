/*
���������Ķ�����������任ΪԴ�������ľ���
*/

/*
˼·���ݹ�
*/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL || (pRoot->left == NULL && pRoot->right == NULL))
			return;
		
		TreeNode *tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		if (pRoot->left != NULL)
		{
			Mirror(pRoot->left);
		}
		
		if (pRoot->right != NULL)
		{
			Mirror(pRoot->right);
		}
    }
};