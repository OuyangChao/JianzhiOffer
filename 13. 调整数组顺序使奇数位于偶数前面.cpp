/*
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣�
���е�ż��λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
*/

/*
˼·���ҵ���һ��ż����λ�ã��������飬��������������ڵ�һ��ż��֮����Ӻ���ǰ������
ͬʱż��λ�ú���һλ��
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator odd = array.begin();
		vector<int>::iterator even = array.begin();
		for (; even != array.end(); ++even)
		{
			if (*even % 2 == 0)
				break;
		}
		for (; odd != array.end(); ++odd)
		{
			if (*odd % 2 != 0 && odd > even) // Ϊ����������ż��֮�󣬴Ӻ���ǰ����
			{
				for (vector<int>::iterator iter = odd; iter > even; --iter)
				{
					int tmp = *iter;
					*iter = *(iter - 1);
					*(iter - 1) = tmp;
				}
				even += 1;
			}
		}
    }
};