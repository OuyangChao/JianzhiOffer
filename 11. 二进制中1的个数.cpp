/*
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/

/*
˼·1����λ
˼·2��n��n-1������n�����ұߵ�1ȥ������1100&1011 = 1000
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