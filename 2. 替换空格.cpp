/*
��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

/*
˼·������ָ��p1, p2��һ��ָ��ԭ�ַ�����ĩβ��һ��ָ�����ַ�����ĩβ
���p1ָ����ַ�Ϊ�ո����滻Ϊ%20
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