/*
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵�����
�������ַ���ģ�����ָ���������������һ���������ַ�����S��
�������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,
Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
*/

/*
˼·��substr
*/

class Solution {
public:
    string LeftRotateString(string str, int n) {
		if (str.length() == 0)
			return str;
		n %= str.length();
		return str.substr(n, str.length() - n) + str.substr(0, n);
    }
};