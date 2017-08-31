/*
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

/*
思路：基于快速排序的partition思想
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (k > input.size() || k <= 0)
			return res;
		int start = 0;
		int end = input.size() - 1;
		int pivotpos = partition(input, start, end);
		while (pivotpos != k - 1)
		{
			if (pivotpos > k - 1)
			{
				end = pivotpos - 1;
				pivotpos = partition(input, start, end);
			}
			else
			{
				start = pivotpos + 1;
				pivotpos = partition(input, start, end);
			}
		}
		
		return vector<int>(input.begin(), input.begin() + k);
    }
	int partition(vector<int> &ivec, int left, int right)
	{
		int pivot = ivec[left];
		while (left < right)
		{
			while (left < right && ivec[right] >= pivot)
				--right;
			ivec[left] = ivec[right];
			while (left < right && ivec[left] <= pivot)
				++left;
			ivec[right] = ivec[left];
		}
		ivec[left] = pivot;
		return left;
	}
};