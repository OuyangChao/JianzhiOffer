/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

/*
思路1：移位
思路2：n与n-1相与会把n的最右边的1去掉，如1100&1011 = 1000
*/

class Solution {
public:
    int NumberOf1(int n) {
		/*
		int num = 0;
		int m = 1;
		int len = 0;
		while (m << 1 != 0)
		{
			m = m << 1;
			++len;
		}
		++len;
		while (len--)
		{
			if (n & m)
				++num;
			n = n << 1;
		}
		return num;
		*/
		int num = 0;
		while (n)
		{
			++num;
			n = n & (n - 1);
		}
		return num;
    }
};