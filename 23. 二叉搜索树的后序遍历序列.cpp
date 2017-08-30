/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

/*
思路：在后序遍历得到的序列中，最后一个数字是树的根节点的值。
数组中的前面的数字可以分为两部分：第一部分是左子树结点的值，它们都比根节点的值小；
第二部分是右子树结点的值，它们都比根结点的值大。
*/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int length = sequence.size();
		if (length == 0)
			return false;
		
		int root = sequence[length - 1];
		int i = 0;
		for (; i < length - 1; ++i)
		{
			if (sequence[i] > root)
				break;
		}
		for (int j = i; j < length - 1; ++j)
		{
			if (sequence[j] < root)
				return false;
		}
		bool left = true;
		if (i > 0)
			left = VerifySquenceOfBST(vector<int>(sequence.begin(), sequence.begin() + i));
		bool right = true;
		if (i < length - 1)
			right = VerifySquenceOfBST(vector<int>(sequence.begin() + i, sequence.begin() + length - 1));
		
		return left && right;
    }
};