/*
������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
*/

/*
˼·�����ݷ�
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
		bool *visited = new bool[rows * cols]();
		int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
		delete[] visited;
		return count;
    }
	int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited)
	{
		int count = 0;
		if (check(threshold, rows, cols, row, col, visited))
		{
			visited[row * cols + col] = true;
			count = 1 + movingCountCore(threshold, rows, cols, row, col - 1, visited)
				+ movingCountCore(threshold, rows, cols, row - 1, col, visited)
				+ movingCountCore(threshold, rows, cols, row, col + 1, visited)
				+ movingCountCore(threshold, rows, cols, row + 1, col, visited);
		}
		return count;
	}
	bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
	{
		if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row * cols + col] && getDigitSum(row) + getDigitSum(col) <= threshold)
			return true;
		else
			return false;
	}
	int getDigitSum(int number)
	{
		int sum = 0;
		while (number > 0)
		{
			sum += number % 10;
			number /= 10;
		}
		return sum;
	}
};