/*
��ʵ��һ����������֮���δ�ӡ������������һ�а��մ����ҵ�˳���ӡ��
�ڶ��㰴�մ��������˳���ӡ�������а��մ����ҵ�˳���ӡ���������Դ����ơ�
*/

/*
˼·������ջ����ӡ������ʱ���ȱ������ӽڵ��ٱ������ӽڵ㵽��һ��ջ�
��ӡż����ʱ���ȱ������ӽڵ��ٱ������ӽڵ㵽�ڶ���ջ�
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