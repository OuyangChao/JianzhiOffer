/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007
*/

/*
思路：归并排序
*/

class Solution {
public:
    int InversePairs(vector<int> data) {
		int length = data.size();
		if (length <= 0)
			return 0;
		vector<int> copy(data.size());;
		return mergesort(data, 0, length - 1, copy) % 1000000007;
    }
	long long mergesort(vector<int> &data, int first, int last, vector<int> &copy)
	{
		if (first < last)
		{
			int mid = (first + last) / 2;
			long long left = mergesort(data, first, mid, copy);
			long long right = mergesort(data, mid + 1, last, copy);
			long long count = mergearray(data, first, mid, last, copy);
			return left + right + count;
		}
		return 0;
	}
	long long mergearray(vector<int> &data, int first, int mid, int last, vector<int> &copy)
	{
		long long count = 0;
		int i = first;
		int j = mid + 1;
		int m = mid;
		int n = last;
		int k = 0;
		while (i <= m && j <= n)
		{
			if (data[i] > data[j])
			{
				copy[k++] = data[i++];
				count += n - j + 1;
				if (count >= 1000000007)
					count %= 1000000007;
			}
			else
			{
				copy[k++] = data[j++];
			}
		}
		
		while (i <= m)
		{
			copy[k++] = data[i++];
		}
		while (j <= n)
		{
			copy[k++] = data[j++];
		}
		
		for (i = 0; i < k; ++i)
			data[first + i] = copy[i];
		
		return count;
	}
};