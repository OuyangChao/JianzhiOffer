/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

/*
思路：找到第一个偶数的位置，遍历数组，如果是奇数而且在第一个偶数之后，则从后往前交换，
同时偶数位置后移一位。
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
			if (*odd % 2 != 0 && odd > even) // 为奇数而且在偶数之后，从后往前交换
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