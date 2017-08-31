/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/

/*
思路：构造排序规则
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
		string str("");
		sort(numbers.begin(), numbers.end(), cmp);
		for (size_t i = 0; i < numbers.size(); ++i)
			str += to_string(numbers[i]);
		return str;
    }
	static bool cmp(int a, int b)
	{
		string A("");
		string B("");
		A += to_string(a);
		A += to_string(b);
		B += to_string(b);
		B += to_string(a);
		return A < B;
	}
};