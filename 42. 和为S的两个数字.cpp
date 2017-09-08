/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

/*
思路：left指向数组左边第一个数字，right指向数组右边第一个数字。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		vector<int> res;
		int left = 0;
		int right = array.size() - 1;
		int minRes = INT_MAX;
		while (left < right)
		{
			int curSum = array[left] + array[right];
			if (curSum == sum && array[left] * array[right] < minRes)
			{
				minRes = array[left] * array[right];
				res.clear();
				res.push_back(array[left]);
				res.push_back(array[right]);
				++left;
			}
			else if (curSum > sum)
				--right;
			else if (curSum < sum)
				++left;
			else
				++left;
		}
		return res;
    }
};