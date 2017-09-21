/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

/*
思路：用e或E将字符串分为两部分，分别判断。
*/

class Solution {
public:
    bool isNumeric(char* string)
    {
		if (string == NULL)
			return false;
		char *pe = string;
		while (*pe != '\0')
		{
			if (*pe == 'e' || *pe == 'E')
				break;
			++pe;
		}
		if (*pe != '\0')
		{
			bool flag = true;
			char *p = pe + 1;
			if (*p == '+' || *p == '-')
				++p;
			if (*p == '\0')
				flag = false;
			while (*p != '\0')
			{
				if (*p < '0' || *p > '9')
				{
					flag = false;
					break;
				}
				++p;
			}
			return isNumericCore(string, pe - 1) && flag;
		}
		else
		{
			return isNumericCore(string, pe);
		}
    }
	bool isNumericCore(char *start, char *end)
	{
		if (*start == '+' || *start == '-' || (*start >= '0' && *start <= '9'))
		{
			++start;
		}
		int dotnum = 0;
		while (*start != '\0' && start <= end)
		{
			if (*start == '.')
				++dotnum;
			else if (*start < '0' || *start > '9')
				return false;
			++start;
		}
		if (dotnum > 1)
			return false;
		else
			return true;
	}
};