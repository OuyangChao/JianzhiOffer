/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
数值为0或者字符串不是一个合法的数值则返回0
*/

/*
思路：考虑正负号，非法输入，是否越界
*/

class Solution {
public:
    int StrToInt(string str) {
		long long num = 0;
		if (str.length() > 0)
		{
			bool minus = false;
			if (str[0] == '+')
				str = str.substr(1, str.length() - 1);
			else if (str[0] == '-')
			{
				str = str.substr(1, str.length() - 1);
				minus = true;
			}
			for (int i = 0; i < str.length(); ++i)
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					int flag = minus ? -1 : 1;
					num = num * 10 + flag * (str[i] - '0');
					if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
					{
						num = 0;
						break;
					}
				}
				else
				{
					num = 0;
					break;
				}
			}
		}
		return num;
    }
};