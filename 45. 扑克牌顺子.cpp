/*
LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...
��������г����5����,�����Լ�������,�����ܲ��ܳ鵽˳��,
����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....
LL��������,��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13��
�����5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����LL����ȥ��������Ʊ���� 
����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��
*/

/*
˼·����������ͳ��0�ĸ�������ͳ����������֮��Ŀ�ȱ������
*/

class Solution {
public:
    bool IsContinuous(vector<int> number) {
		if (number.size() < 1)
			return false;
		int hashTable[14] = {0};
		for (size_t i = 0; i < number.size(); ++i)
			++hashTable[number[i]];
		int index = 0;
		for (int i = 0; i < 14; ++i)
		{
			for (int j = 0; j < hashTable[i]; ++j)
				number[index++] = i;
		}
		int numberOfZero = hashTable[0];
		int numberofGap = 0;
		int small = numberOfZero;
		int big = small + 1;
		while (big < number.size())
		{
			if (number[small] == number[big])
				return false;
			numberofGap += number[big] - number[small] - 1;
			small = big;
			++big;
		}
		return numberofGap > numberOfZero ? false : true;
    }
};