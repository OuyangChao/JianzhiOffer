/*
��һ����ά�����У�
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ��������
����������һ����ά�����һ��������
�ж��������Ƿ��и�������
*/

/*
1	2	8	9
2	4	9	12
4	7	9	12
6	8	11	15
˼·��
�����Ͻǿ�ʼ��������Ҫ������ֵΪtarget�������ĵ�ǰֵΪcur������Ϊ(row, col)
��ʼֵ��row = 0, col = cols - 1,colsΪ��������
���cur����target����ô��һ�к����ֵ������target�����Խ���һ�к��ԣ�--col
���curС��target����ô��һ��ǰ���ֵ��С��target�����Խ���һ�к��ԣ�++row
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
		int cols = array[0].size();
		int row = 0;
		int col = cols - 1;
		while (row <= rows - 1 && col >= 0)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] > target)
				--col;
			else if (array[row][col] < target)
				++row;
		}
		return false;
    }
};