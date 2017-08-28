/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/

/*
思路：自底向上
*/

class Solution {
public:
    int Fibonacci(int n) {
		if (n == 0 || n == 1)
			return n;
		vector<int> ivec(n + 1, 0);
		ivec[0] = 0;
		ivec[1] = 1;
		for (size_t i = 2; i < n + 1; ++i)
		{
			ivec[i] = ivec[i - 1] + ivec[i - 2];
		}
		return ivec[n];
    }
};