/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/

/*
˼·������map
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
		map<int, int> mymap;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			++mymap[numbers[i]];
			if (mymap[numbers[i]] > numbers.size() / 2)
				return numbers[i];
		}
		return 0;
    }
};