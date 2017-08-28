/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
思路：
*/

class Solution {
public:
    int jumpFloorII(int number) {
		if (number == 1 || number == 2)
			return number;
		vector<int> ivec(number, 1); // 注意此处初始化为1，默认为有一种直接一步跳上n级的
		ivec[0] = 1;
		ivec[1] = 2;
		for (size_t i = 2; i < number; ++i)
		{
			for (size_t j = 0; j < i; ++j)
			{
				ivec[i] += ivec[j];
			}
		}
		return ivec[number - 1];
    }
};