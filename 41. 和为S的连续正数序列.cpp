/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
*/

/*
思路：考虑用两个数small和big分别表示序列的最小值和最大值。首先把small初始化为1，
big初始化为2。如果从small到big的序列的和大于s，我们可以从序列中去掉较小的值，
也就是增大small的值。如果从small到big的序列的和小于s，我们可以增大big，
让这个序列包含更多的数字。因为这个序列至少要有两个数字，我们一直增加small到(1+s)/2为止。
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		if (sum < 3)
			return res;
		int small = 1;
		int big = 2;
		int middle = (1 + sum) / 2;
		int curSum = small + big;
		while (small < middle)
		{
			if (curSum == sum)
				res.push_back(getSequence(small, big));
			while (curSum > sum && small < middle)
			{
				curSum -= small;
				++small;
				if (curSum == sum)
					res.push_back(getSequence(small, big));
			}
			++big;
			curSum += big;
		}
		return res;
    }
	vector<int> getSequence(int small, int big)
	{
		vector<int> res;
		for (int i = small; i <= big; ++i)
			res.push_back(i);
		return res;
	}
};