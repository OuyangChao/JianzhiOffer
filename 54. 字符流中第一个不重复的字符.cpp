/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
*/

/*
思路：哈希表，用字符的ASCII码作为哈希表的键值，而把字符对应的位置作为哈希表的值。
*/

class Solution
{
public:
	int occurrence[256];
	int index;
	Solution()
	{
		for (int i = 0; i < 256; ++i)
			occurrence[i] = 0;
		index = 1;
	}
  //Insert one char from stringstream
    void Insert(char ch)
    {
		if (occurrence[ch] == 0)
			occurrence[ch] = index;
		else if (occurrence[ch] > 0)
			occurrence[ch] = -1;
		++index;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
		char ch = '#';
		int minIndex = numeric_limits<int>::max();
		for (int i = 0; i < 256; ++i)
		{
			if (occurrence[i] > 0 && occurrence[i] < minIndex)
			{
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}
		return ch;
    }
};