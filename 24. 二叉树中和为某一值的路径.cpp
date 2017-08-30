/*
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/

/*
思路：深度优先搜索（DFS）
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> > vecPath;
		int currentSum = 0;
		vector<int> path;
		FindPath(root, expectNumber, path, currentSum, vecPath);
		return vecPath;
    }
	void FindPath(TreeNode* root,int expectNumber, vector<int> &path, int currentSum, vector<vector<int> > &vecPath)
	{
		if (root == NULL)
			return;
		currentSum += root->val;
		path.push_back(root->val);
		bool isLeaf = root->left == NULL && root->right == NULL;
		if (currentSum == expectNumber && isLeaf)
			vecPath.push_back(path);
		
		if (root->left != NULL)
			FindPath(root->left, expectNumber, path, currentSum, vecPath);
		if (root->right != NULL)
			FindPath(root->right, expectNumber, path, currentSum, vecPath);
		path.pop_back();
	}
};