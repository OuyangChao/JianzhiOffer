/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

/*
思路：
第一步：首先求所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换。
第二步：固定第一个字符，求后面所有字符的排列，递归。
注意判断字符重复的情况。
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
		Permute(str, 0, res);
		return res;
    }
	void Permute(string str, int start, vector<string> &res)
	{
		if (start == str.length() - 1)
			res.push_back(str);
		
		for (int i = start; i < str.length(); ++i)
		{
			if (i != start && str[i] == str[start])
				continue;
			char tmp = str[i];
			str[i] = str[start];
			str[start] = tmp;
			Permute(str, start + 1, res);
		}
	}
};