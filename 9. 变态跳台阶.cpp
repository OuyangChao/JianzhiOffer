/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*/

/*
˼·��
*/

class Solution {
public:
    int jumpFloorII(int number) {
		if (number == 1 || number == 2)
			return number;
		vector<int> ivec(number, 1); // ע��˴���ʼ��Ϊ1��Ĭ��Ϊ��һ��ֱ��һ������n����
		ivec[0] = 1;
		ivec[1] = 2;
		for (size_t i = 2; i < number; ++i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				ivec[i] += ivec[j];
			}
		}
		return ivec[number - 1];
    }
};