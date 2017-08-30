/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*
思路：队列
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ivec;
		if (root == NULL)
			return ivec;
		std::deque<TreeNode*> dequeTreeNode;
		dequeTreeNode.push_back(root);
		while (!dequeTreeNode.empty())
		{
			TreeNode* node = dequeTreeNode.front();
			dequeTreeNode.pop_front();
			ivec.push_back(node->val);
			if (node->left != NULL)
				dequeTreeNode.push_back(node->left);
			if (node->right != NULL)
				dequeTreeNode.push_back(node->right);
		}
		return ivec;
    }
};