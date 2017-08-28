/*
����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���
*/

/*
˼·�����ֿ�������һ������b�Ķ�����������������a^b���㷨��
���磺
a = 2, b = 35
��b�Ķ����Ʊ�ʾ��ʽΪ100011
�� a^b = (2^32) * (2^2) * (2^1)
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