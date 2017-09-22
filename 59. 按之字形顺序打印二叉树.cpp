/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

/*
思路：两个栈，打印奇数层时，先保存左子节点再保存右子节点到第一个栈里；
打印偶数层时，先保存右子节点再保存左子节点到第二个栈里。
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
		stack<TreeNode*> levels[2];
		int current = 0;
		int next = 1;
		levels[current].push(pRoot);
		vector<int> vec;
		while (!levels[current].empty() || !levels[next].empty())
		{
			TreeNode* pNode = levels[current].top();
			levels[current].pop();
			vec.push_back(pNode->val);
			if (current == 0)
			{
				if (pNode->left != NULL)
					levels[next].push(pNode->left);
				if (pNode->right != NULL)
					levels[next].push(pNode->right);
			}
			else
			{
				if (pNode->right != NULL)
					levels[next].push(pNode->right);
				if (pNode->left != NULL)
					levels[next].push(pNode->left);
			}
			if (levels[current].empty())
			{
				res.push_back(vec);
				vec.clear();
				current = 1 - current;
				next = 1 - next;
			}
		}
		return res;
    }
};