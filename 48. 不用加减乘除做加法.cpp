/*
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*/

/*
˼·��λ����
����������൱��ÿһλ��ӣ��������ǽ�λ��
���������룬������һλ���൱����ý�λ��
�����������Ľ�����
*/

class Solution {
public:
    int Add(int num1, int num2)
    {
		int sum, carry;
		do
		{
			sum = num1 ^ num2;
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		
		return num1;
    }
};