/*
���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
*/

/*
˼·����Ȼ��쳲���������
*/

class Solution {
public:
    int rectCover(int number) {
		if (number == 0 || number == 1 || number == 2)
			return number;
		vector<int> ivec(number, 0);
		ivec[0] = 1;
		ivec[1] = 2;
		for (size_t i = 2; i < number; ++i)
		{
			ivec[i] = ivec[i - 1] + ivec[i - 2];
		}
		return ivec[number - 1];
    }
};