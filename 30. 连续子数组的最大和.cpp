/*
HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:
�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��᲻�ᱻ������ס��(�������ĳ���������1)
*/

/*
˼·����¼��ǰ���ֵ
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
		int thisSum = 0, maxSum = array[0];
		for (size_t i = 0; i < array.size(); ++i)
		{
			thisSum += array[i];
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
			}
			else if (thisSum < 0)
				thisSum = 0;
		}
		return maxSum;
    }
};