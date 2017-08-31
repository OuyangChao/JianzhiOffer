/*
����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/

/*
˼·�����ڿ��������partition˼��
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