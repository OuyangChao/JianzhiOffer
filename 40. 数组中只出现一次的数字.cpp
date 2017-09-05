/*
һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
*/

/*
˼·���������ҳ�ֻ����һ�ε����֡���������ֻ����һ�ε����֣����Ը���������������Ϊ�����֣�
Ȼ���ٷֱ�������
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if (data.size() < 2)
			return;
		int resultExclusiveOR = 0;
		for (size_t i = 0; i < data.size(); ++i)
			resultExclusiveOR ^= data[i];
		unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);
		for (size_t i = 0; i < data.size(); ++i)
		{
			if (isBit1(data[i], indexOf1))
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
    }
	unsigned int FindFirstBitIs1(int num)
	{
		int indexBit = 0;
		while ((num & 1) == 0 && (indexBit < 8 * sizeof(int)))
		{
			num = num >> 1;
			++indexBit;
		}
		return indexBit;
	}
	bool isBit1(int num, unsigned int indexBit)
	{
		num = num >> indexBit;
		return (num & 1);
	}
};