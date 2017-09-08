/*
С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!
*/

/*
˼·��������������small��big�ֱ��ʾ���е���Сֵ�����ֵ�����Ȱ�small��ʼ��Ϊ1��
big��ʼ��Ϊ2�������small��big�����еĺʹ���s�����ǿ��Դ�������ȥ����С��ֵ��
Ҳ��������small��ֵ�������small��big�����еĺ�С��s�����ǿ�������big��
��������а�����������֡���Ϊ�����������Ҫ���������֣�����һֱ����small��(1+s)/2Ϊֹ��
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		if (sum < 3)
			return res;
		int small = 1;
		int big = 2;
		int middle = (1 + sum) / 2;
		int curSum = small + big;
		while (small < middle)
		{
			if (curSum == sum)
				res.push_back(getSequence(small, big));
			while (curSum > sum && small < middle)
			{
				curSum -= small;
				++small;
				if (curSum == sum)
					res.push_back(getSequence(small, big));
			}
			++big;
			curSum += big;
		}
		return res;
    }
	vector<int> getSequence(int small, int big)
	{
		vector<int> res;
		for (int i = small; i <= big; ++i)
			res.push_back(i);
		return res;
	}
};