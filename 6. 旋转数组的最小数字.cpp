/*
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/

/*
˼·������Сֵ
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        return *min_element(rotateArray.begin(), rotateArray.end());
    }
};