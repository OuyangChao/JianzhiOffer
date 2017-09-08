/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

/*
思路：先把整个句子都翻转，然后用空格分隔句子，分别翻转每个单词。
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