/*
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

/*
思路：构造哈希表
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		if (str == "")
			return -1;
		const int tableSize = 256;
		unsigned int hashTable[tableSize] = {0};
		for (int i = 0; i < str.length(); ++i)
			++hashTable[str[i]];
		int pos = 0;
		for (; pos < str.length(); ++pos)
			if (hashTable[str[pos]] == 1)
				break;
		return pos;
    }
};