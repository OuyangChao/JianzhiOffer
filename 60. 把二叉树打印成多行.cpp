/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

/*
思路：toBePrinted表示当前层中还没有打印的结点数，nextLevel表示下一层的结点数。
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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		if (pRoot == NULL)
			return res;
		queue<TreeNode*> myqueue;
		myqueue.push(pRoot);
		vector<int> vec;
		int toBePrinted = 1;
		int nextLevel = 0;
		while (!myqueue.empty())
		{
			TreeNode* pNode = myqueue.front();
			myqueue.pop();
			vec.push_back(pNode->val);
			if (pNode->left)
			{
				myqueue.push(pNode->left);
				++nextLevel;
			}
			if (pNode->right)
			{
				myqueue.push(pNode->right);
				++nextLevel;
			}
			--toBePrinted;
			if (toBePrinted == 0)
			{
				res.push_back(vec);
				vec.clear();
				toBePrinted = nextLevel;
				nextLevel = 0;
			}
		}
		return res;
	}
};