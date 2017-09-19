/*
��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
*/

/*
˼·�����������ţ��Ƿ����룬�Ƿ�Խ��
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