/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
那么中位数就是所有数值排序之后中间两个数的平均值。
*/

/*
思路：使最大堆中所有数据都小于最小堆中的数据，而且两个堆中数据的数目之差不超过1。
*/

class Solution {
public:
    void Insert(int num)
    {
		if (((min.size() + max.size()) & 1) == 0)
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());
		}
		else
		{
			if (min.size() > 0 && min[0] < num)
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}
    }
	
    double GetMedian()
    {
		int size = min.size() + max.size();
		if (size == 0)
			return -1;
		if ((size & 1) == 1)
			return min[0];
		else
			return (min[0] + max[0]) / 2.0;
    }
private:
	vector<int> min;
	vector<int> max;
};