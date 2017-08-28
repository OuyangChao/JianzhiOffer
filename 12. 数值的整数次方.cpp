/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

/*
思路：二分快速幂是一种利用b的二进制特征来快速求a^b的算法。
例如：
a = 2, b = 35
则b的二进制表示形式为100011
则 a^b = (2^32) * (2^2) * (2^1)
*/

class Solution {
public:
    double Power(double base, int exponent) {
		double ret = 1.0;
		double tmp = base;
		int exp = exponent > 0 ? exponent : -exponent;
		while (exp > 0)
		{
			if (exp & 1)
				ret *= tmp;
			exp >>= 1;
			tmp *= tmp;
		}
		return exponent > 0 ? ret : (1 / ret);
    }
};