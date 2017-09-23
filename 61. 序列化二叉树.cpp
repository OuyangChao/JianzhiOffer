/*
请实现两个函数，分别用来序列化和反序列化二叉树
*/

/*
思路：前序遍历
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
    char* Serialize(TreeNode *root) {
		if (root == NULL)
			return NULL;
		string str("");
		serializeHelper(root, str);
		return (char*)str.c_str();
    }
    TreeNode* Deserialize(char *str) {
		if (str == NULL)
			return NULL;
		string s(str);
		return deserializeHelper(s);
    }
	void serializeHelper(TreeNode *root,string &str)
	{
		if (root == NULL)
		{
			str += "#,";
			return;
		}
		str += to_string(root->val);
		str += ',';
		serializeHelper(root->left, str);
		serializeHelper(root->right, str);
	}
	TreeNode* deserializeHelper(string &str)
	{
		if (str == "")
			return NULL;
		if (str[0] == '#')
		{
			str = str.substr(2);
			return NULL;
		}
		TreeNode* pRoot = new TreeNode(stoi(str));
		str = str.substr(str.find_first_of(',') + 1);
		pRoot->left = deserializeHelper(str);
		pRoot->right = deserializeHelper(str);
		return pRoot;
	}
};