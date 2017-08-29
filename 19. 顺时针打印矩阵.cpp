/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/*
思路：用左上和右下的坐标定位出一次要旋转打印的数据，
一次旋转打印结束后，往对角分别前进和后退一个单位。
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<int> res;
		int left = 0, top = 0, right = cols - 1, bottom = rows - 1;
		while (left <= right && top <= bottom)
		{
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[top][i]);
			for (int i = top + 1; i <= bottom; ++i)
				res.push_back(matrix[i][right]);
			if (top != bottom)
			{
				for (int i = right - 1; i >= left; --i)
					res.push_back(matrix[bottom][i]);
			}
			if (left != right)
			{
				for (int i = bottom - 1; i >= top + 1; --i)
					res.push_back(matrix[i][left]);
			}
			++left;
			++top;
			--right;
			--bottom;
		}
		return res;
    }
};