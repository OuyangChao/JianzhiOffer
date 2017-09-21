/*
��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��
*/

/*
˼·����ϣ�����ַ���ASCII����Ϊ��ϣ��ļ�ֵ�������ַ���Ӧ��λ����Ϊ��ϣ���ֵ��
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