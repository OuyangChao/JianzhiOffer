/*
统计一个数字在排序数组中出现的次数。
*/

/*
思路：二分查找，循环实现
*/

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
		if (data.size() == 0)
			return 0;
		
		int first = getFirstK(data, k);
		int last = getLastK(data, k);
		
		if (first != -1 && last != -1)
			return last - first + 1;
		return 0;
    }
	int getFirstK(const vector<int> &data, int k)
	{
		int start = 0, end = data.size() - 1;
		int mid = (start + end) / 2;
		while (start <= end)
		{
			if (data[mid] < k)
				start = mid + 1;
			else if (data[mid] > k)
				end = mid - 1;
			else if (mid - 1 >= 0 && data[mid - 1] == k)
				end = mid - 1;
			else
				return mid;
			mid = (start + end) / 2;
		}
		return -1;
	}
	int getLastK(const vector<int> &data, int k)
	{
		int start = 0, end = data.size() - 1;
		int mid = (start + end) / 2;
		while (start <= end)
		{
			if (data[mid] < k)
				start = mid + 1;
			else if (data[mid] > k)
				end = mid - 1;
			else if (mid + 1 < data.size() && data[mid + 1] == k)
				start = mid + 1;
			else
				return mid;
			mid = (start + end) / 2;
		}
		return -1;
	}
};