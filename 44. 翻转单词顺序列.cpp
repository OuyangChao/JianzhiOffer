/*
ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�
ͬ��Cat��Fishд�������ĸ���Ȥ����һ������Fish������������ȴ������������˼��
���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
*/

/*
˼·���Ȱ��������Ӷ���ת��Ȼ���ÿո�ָ����ӣ��ֱ�תÿ�����ʡ�
*/

class Solution {
public:
    string ReverseSentence(string str) {
		ReverseString(str);
		int left = 0;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')
			{
				string strtmp = str.substr(left, i - left);
				ReverseString(strtmp);
				str.replace(left, i - left, strtmp);
				left = i + 1;
			}
		}
		if (left == 0)
			ReverseString(str);
		else
		{
			string strtmp = str.substr(left, str.length() - left);
			ReverseString(strtmp);
			str.replace(left, str.length() - left, strtmp);
		}
		return str;
    }
	void ReverseString(string &str)
	{
		for (int i = 0; i < str.length() / 2; ++i)
		{
			char tmp = str[i];
			str[i] = str[str.length() - 1 - i];
			str[str.length() - 1 - i] = tmp;
		}
	}
};