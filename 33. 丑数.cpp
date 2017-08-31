/*
��ֻ��������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ����������7��
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
*/

/*
˼·����̬�滮�����ڵ�i��������һ����֮ǰ�Ѵ�������2����3����5��
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
		if (index < 1)
			return 0;
		vector<int> res(index);
		res[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;
		for (int i = 1; i < index; ++i)
		{
			res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
			if (res[i] == res[t2] * 2)
				++t2;
			if (res[i] == res[t3] * 3)
				++t3;
			if (res[i] == res[t5] * 5)
				++t5;
		}
		return res[index - 1];
    }
};