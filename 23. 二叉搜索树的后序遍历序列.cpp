/*
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��
*/

/*
˼·���ں�������õ��������У����һ�����������ĸ��ڵ��ֵ��
�����е�ǰ������ֿ��Է�Ϊ�����֣���һ����������������ֵ�����Ƕ��ȸ��ڵ��ֵС��
�ڶ�����������������ֵ�����Ƕ��ȸ�����ֵ��
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