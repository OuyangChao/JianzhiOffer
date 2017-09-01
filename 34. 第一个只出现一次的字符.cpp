/*
��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
*/

/*
˼·�������ϣ��
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