/*
请实现一个函数，将一个字符串中的空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

/*
思路：两个指针p1, p2，一个指向原字符串的末尾，一个指向新字符串的末尾
如果p1指向的字符为空格，则替换为%20
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
		char *p1 = str;
		int nblank = 0;
		while (*p1 != '\0')
		{
			if (*p1 == ' ')
				++nblank;
			++p1;
		}
		int oldlength = p1 - str;
		int newlength = oldlength + 2 * nblank;
		if (newlength > length)
			return;
		char *p2 = str + newlength;
		int len = oldlength;
		while (len-- >= 0)
		{
			if (*p1 == ' ')
			{
				*p2-- = '0';
				*p2-- = '2';
				*p2-- = '%';
			}
			else
				*p2-- = *p1;
			--p1;
		}
	}
};