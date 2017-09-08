/*
����һ����������������һ������S���������в������������ǵ����ǵĺ�������S��
����ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
*/

/*
˼·��leftָ��������ߵ�һ�����֣�rightָ�������ұߵ�һ�����֡�
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