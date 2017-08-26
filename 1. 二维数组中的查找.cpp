/*
在一个二维数组中，
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，
输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。
*/

/*
1	2	8	9
2	4	9	12
4	7	9	12
6	8	11	15
思路：
从右上角开始搜索，设要搜索的值为target，搜索的当前值为cur，坐标为(row, col)
初始值，row = 0, col = cols - 1,cols为数组列数
如果cur大于target，那么这一列后面的值都大于target，可以将这一列忽略，--col
如果cur小于target，那么这一行前面的值都小于target，可以将这一行忽略，++row
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
		int cols = array[0].size();
		int row = 0;
		int col = cols - 1;
		while (row <= rows - 1 && col >= 0)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				--col;
			else if (array[row][col] < target)
				++row;
		}
		return false;
    }
};