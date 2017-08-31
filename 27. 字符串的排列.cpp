/*
����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/

/*
˼·��
��һ�������������п��ܳ����ڵ�һ��λ�õ��ַ������ѵ�һ���ַ��ͺ������е��ַ�������
�ڶ������̶���һ���ַ�������������ַ������У��ݹ顣
ע���ж��ַ��ظ��������
*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
		Permute(str, 0, res);
		return res;
    }
	void Permute(string str, int start, vector<string> &res)
	{
		if (start == str.length() - 1)
			res.push_back(str);
		
		for (int i = start; i < str.length(); ++i)
		{
			if (i != start && str[i] == str[start])
				continue;
			char tmp = str[i];
			str[i] = str[start];
			str[start] = tmp;
			Permute(str, start + 1, res);
		}
	}
};