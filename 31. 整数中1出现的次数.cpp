/*
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,
���Ժܿ���������Ǹ�����������1���ֵĴ�����
*/

/*
˼·��http://blog.csdn.net/yi_afly/article/details/52012593
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
		if (n < 1)
			return 0;
		int count = 0;
		int base = 1;
		int round = n;
		while (round > 0)
		{
			int weight = round % 10;
			round /= 10;
			count += round * base;
			if (weight == 1)
				count += (n % base) + 1;
			else if (weight > 1)
				count += base;
			base *= 10;
		}
		return count;
    }
};